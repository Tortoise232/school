using System;
using System.Collections;
using System.Diagnostics;
using System.Drawing;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace ImgCorrCoeff
{
   
    class MeanRGB
    {
        public int R = 0;
        public int G = 0;
        public int B = 0;
        public MeanRGB(int r, int g, int b)
        {
            this.R = r;
            this.G = g;
            this.B = b;
        }
    }

    class Program
    {
        static Color[,] image1Local = null;
        static Color[,] image2Local = null;


        static int NR_OF_CORES = 4;
        public static MeanRGB mean1;
        public static MeanRGB mean2;

        //the images
        static Bitmap image1;
        static Bitmap image2;

        public static int height;
        public static int width;

        //used for the correlation formula
        public static double numeratorSumRed = 0;
        public static double denominatorSumARed = 0;
        public static double denominatorSumBRed = 0;

        public static double numeratorSumGreen = 0;
        public static double denominatorSumAGreen = 0;
        public static double denominatorSumBGreen = 0;

        public static double numeratorSumBlue = 0;
        public static double denominatorSumABlue = 0;
        public static double denominatorSumBBlue = 0;


        static int threadsDoneCt = 0;
        
        static void Main(string[] args)
        {
            //Console.Write("First image file path: ");
            string path1 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\microsoft600x600.jpg";
            // Console.Write("Second image file path: ");
            string path2 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\vetnisupp600x600.jpg";

            //initRun(path1, path2);
            Stopwatch time = new Stopwatch();
            //time.Start();
            //double corCoff = correlationCoefficientSeq();
           // time.Stop();
            //Console.WriteLine("\nTime: " + time.ElapsedMilliseconds);
            for (int i = 1; i < 8; i++)
            {
                NR_OF_CORES = i;
                
                Console.WriteLine("\nThreads used: " + NR_OF_CORES);
                clearData();
                initRun(path1, path2);
                time = new Stopwatch();
                time.Start();
                double corCoff = correlationCoefficientThreaded();
                time.Stop();
                Console.WriteLine("\nTime: " + time.ElapsedMilliseconds);
               
            }
            clearData();
            AsynchronousSocketListener.StartListening();

        }
        static void storeImagesLocally()
        {
            image1Local = new Color[width, height];
            image2Local = new Color[width, height];
            for (int i = 0; i < width; i ++)
                for(int j = 0; j < height; j++)
                {
                    image1Local[i, j] = image1.GetPixel(i, j);
                    image2Local[i, j] = image2.GetPixel(i, j);
                }


        }

        static void initRun(string path1, string path2)
        {
            
            loadImages(path1, path2);
            height = image1.Height;
            width = image1.Width;
            if (image1Local == null)
                storeImagesLocally();
            if (!checkImageSizes())
                return;
            //calc means
            mean1 = calcMean(image1);
            mean2 = calcMean(image2);

           
        }
        static double correlationCoefficientSeq()
        {
            
            for (int i = 0; i < image1.Width; i++)
                for (int j = 0; j < image2.Height; j++)
                {
                    
                    numeratorSumRed += (image1.GetPixel(i, j).R - mean1.R) * (image2.GetPixel(i, j).R - mean2.R);
                    denominatorSumARed += (image1.GetPixel(i, j).R - mean1.R) * (image1.GetPixel(i, j).R - mean1.R);
                    denominatorSumBRed += (image2.GetPixel(i, j).R - mean2.R) * (image2.GetPixel(i, j).R - mean2.R);

                    numeratorSumGreen += (image1.GetPixel(i, j).G - mean1.G) * (image2.GetPixel(i, j).G - mean2.G);
                    denominatorSumAGreen += (image1.GetPixel(i, j).G - mean1.G) * (image1.GetPixel(i, j).G - mean1.G);
                    denominatorSumBGreen += (image2.GetPixel(i, j).G - mean2.G) * (image2.GetPixel(i, j).G - mean2.G);
                    
                    numeratorSumBlue += (image1.GetPixel(i, j).B - mean1.B) * (image2.GetPixel(i, j).B - mean2.B);
                    denominatorSumABlue += (image1.GetPixel(i, j).B - mean1.B) * (image1.GetPixel(i, j).B - mean1.B);
                    denominatorSumBBlue += (image2.GetPixel(i, j).B - mean2.B) * (image2.GetPixel(i, j).B - mean2.B);
                }
         
            double resultR = numeratorSumRed / Math.Sqrt(denominatorSumARed * denominatorSumBRed);
            double resultG = numeratorSumGreen / Math.Sqrt(denominatorSumAGreen * denominatorSumBGreen);
            double resultB = numeratorSumBlue / Math.Sqrt(denominatorSumABlue * denominatorSumBBlue);
            //Console.WriteLine("\n"+ resultR + " R      " + resultG + " G       " + resultB + " B      ");
            Console.Write("Sequential result is: " + (resultR + resultG + resultB) / 3);
            return (resultR + resultG + resultB) / 3;
        }

        public static void correlationCoeff(object state)
        {

            Stopwatch totalTime = new Stopwatch();
            totalTime.Start();
            int part = (int)state;
            int startingRow = (height / NR_OF_CORES) * part;
            int lastRow;
            if (part == NR_OF_CORES - 1)
                lastRow = height;
            else
                lastRow = startingRow + (height / NR_OF_CORES);
            Console.WriteLine("THREAD " + part + " STARTED FOR: " + startingRow + " THROUGH TO " + lastRow);
            Stopwatch time = new Stopwatch();

            for (int i = 0; i < width; i++) { 
                for (int j = startingRow; j < lastRow; j++)
                {
                    Color image1Pix;
                    Color image2Pix;
                    time.Start();
                    image1Pix = image1Local[i, j];
                    image2Pix = image2Local[i, j];
                    time.Stop();
                    numeratorSumRed += (image1Pix.R - mean1.R) * (image2Pix.R - mean2.R);
                    denominatorSumARed += (image1Pix.R - mean1.R) * (image1Pix.R - mean1.R);
                    denominatorSumBRed += (image2Pix.R - mean2.R) * (image2Pix.R - mean2.R);

                    numeratorSumGreen += (image1Pix.G - mean1.G) * (image2Pix.G - mean2.G);
                    denominatorSumAGreen += (image1Pix.G - mean1.G) * (image1Pix.G - mean1.G);
                    denominatorSumBGreen += (image2Pix.G - mean2.G) * (image2Pix.G - mean2.G);

                    numeratorSumBlue += (image1Pix.B - mean1.B) * (image2Pix.B - mean2.B);
                    denominatorSumABlue += (image1Pix.B - mean1.B) * (image1Pix.B - mean1.B);
                    denominatorSumBBlue += (image2Pix.B - mean2.B) * (image2Pix.B - mean2.B);
                }
            }
            totalTime.Stop();
            Console.WriteLine("THREAD " + part + " FINISHED IN " + totalTime.ElapsedMilliseconds + "(RESOURCE WAITING: " + time.ElapsedMilliseconds + ",WORKING TIME: " + (totalTime.ElapsedMilliseconds - time.ElapsedMilliseconds) + ")" );
            threadsDoneCt++;
        }

        static double correlationCoefficientThreaded()
        {
          
            for (int i = 0; i < NR_OF_CORES; i ++ )
            {
                Thread myThread = new Thread(correlationCoeff);
                myThread.Start(i);
                
            }
            int w = 0;
            //
            while (threadsDoneCt < NR_OF_CORES)
            {
                w++;
                Thread.Sleep(100);
            }
            Console.WriteLine("I slept for: " + w / 10 + " seconds");
            double resultR = numeratorSumRed / Math.Sqrt(denominatorSumARed * denominatorSumBRed);
            double resultG = numeratorSumGreen / Math.Sqrt(denominatorSumAGreen * denominatorSumBGreen);
            double resultB = numeratorSumBlue / Math.Sqrt(denominatorSumABlue * denominatorSumBBlue);
            //Console.WriteLine("\n"+ resultR + " R      " + resultG + " G       " + resultB + " B      ");
            Console.Write("Threading result is: " + (resultR + resultG + resultB) / 3);
            return (resultR + resultG + resultB) / 3;

        }

        static MeanRGB calcMean(Bitmap bitmap)
        {
            int sumR = 0, sumG = 0, sumB = 0 ;
            for (int i = 0; i < bitmap.Width; i++)
                for (int j = 0; j < bitmap.Height; j++)
                {
                    Color pix = bitmap.GetPixel(i, j);
                    sumR += pix.R;
                    sumG += pix.G;
                    sumB += pix.B;
                }
            //Console.WriteLine("Size:" + bitmap.Height * bitmap.Width);
            int meanR = sumR / (bitmap.Width * bitmap.Height);
            int meanG = sumG / (bitmap.Width * bitmap.Height);
            int meanB = sumB / (bitmap.Width * bitmap.Height);
            //Console.WriteLine("Sums: " + sumR + " " + sumG + " " + sumB);
            //Console.WriteLine("Means: " + meanR + " " + meanG + " " + meanB);
            MeanRGB result = new MeanRGB(meanR, meanG, meanB);
            return result;
            
        }

        static void loadImages(string source1, string source2)
        {
            image1 = new Bitmap(source1);
            //Console.WriteLine("IMAGE 1: ");
            //for (int i = 0; i < image1.Width; i++)
                //for (int j = 0; j < image1.Height; j++)
                //{
                    //Console.Write(image1.GetPixel(i, j).R + ",");
                //}
            image2 = new Bitmap(source2);
            
           // Console.WriteLine("IMAGE 2: ");
            //for (int i = 0; i < image2.Width; i++)
                //for (int j = 0; j < image2.Height; j++)
                //{
                   // Console.Write(image2.GetPixel(i, j).R + ",");
                //}
        }

        void initMeans()
        {
            mean1 = calcMean(image1);
            mean2 = calcMean(image2);
        }

        static void clearData()
        {
          
            //used for the correlation formula
            numeratorSumRed = 0;
            denominatorSumARed = 0;
            denominatorSumBRed = 0;

            numeratorSumGreen = 0;
            denominatorSumAGreen = 0;
            denominatorSumBGreen = 0;

            numeratorSumBlue = 0;
            denominatorSumABlue = 0;
            denominatorSumBBlue = 0;
            threadsDoneCt = 0;
        }


        static bool checkImageSizes()
        {
            return (image1.Height == image2.Height && image2.Width == image1.Width);
        }

    }
    // State object for reading client data asynchronously  
    public class StateObject
    {
        // Client  socket.  
        public Socket workSocket = null;
        // Size of receive buffer.  
        public const int BufferSize = 1024;
        // Receive buffer.  
        public byte[] buffer = new byte[BufferSize];
        // Received data string.  
        public StringBuilder sb = new StringBuilder();
    }

    public class AsynchronousSocketListener
    {
        static int processShareCt = 0;
        static int NR_OF_SLAVES = 4;
        static int NR_OF_DONE_SLAVES = 0;
        // Thread signal.  
        public static ManualResetEvent allDone = new ManualResetEvent(false);

        public AsynchronousSocketListener()
        {
        }

        public static void StartListening()
        {
            // Data buffer for incoming data.  
            byte[] bytes = new Byte[1024];

            // Establish the local endpoint for the socket.  
            // The DNS name of the computer  
            // running the listener is "host.contoso.com".  
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 11000);

            // Create a TCP/IP socket.  
            Socket listener = new Socket(ipAddress.AddressFamily,
                SocketType.Stream, ProtocolType.Tcp);

            // Bind the socket to the local endpoint and listen for incoming connections.  
            try
            {
                listener.Bind(localEndPoint);
                listener.Listen(100);

                while (true)
                {
                    // Set the event to nonsignaled state.  
                    allDone.Reset();

                    // Start an asynchronous socket to listen for connections.  
                    Console.WriteLine("Waiting for a connection...");
                    listener.BeginAccept(
                        new AsyncCallback(AcceptCallback),
                        listener);

                    // Wait until a connection is made before continuing.  
                    allDone.WaitOne();
                }

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            Console.WriteLine("\nPress ENTER to continue...");
            Console.Read();

        }

        public static void AcceptCallback(IAsyncResult ar)
        {
            // Signal the main thread to continue.  
            allDone.Set();

            // Get the socket that handles the client request.  
            Socket listener = (Socket)ar.AsyncState;
            Socket handler = listener.EndAccept(ar);
            if (processShareCt > NR_OF_SLAVES)
                return;
            // Create the state object.  
            StateObject state = new StateObject();
            state.workSocket = handler;
            handler.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                new AsyncCallback(ReadCallback), state);
            
        }

        public static void ReadCallback(IAsyncResult ar)
        {
            String content = String.Empty;

            // Retrieve the state object and the handler socket  
            // from the asynchronous state object.  
            StateObject state = (StateObject)ar.AsyncState;
            Socket handler = state.workSocket;

            // Read data from the client socket.   
            int bytesRead = handler.EndReceive(ar);

            if (bytesRead > 0)
            {
                // There  might be more data, so store the data received so far.  
                state.sb.Append(Encoding.ASCII.GetString(
                    state.buffer, 0, bytesRead));

                // Check for end-of-file tag. If it is not there, read   
                // more data.  
                content = state.sb.ToString();
                if (content.IndexOf("<EOF>") > -1)
                {
                    // All the data has been read from the   
                    // client. Display it on the console.  
                    
                    Console.WriteLine("A process connected! Assigning part: " + processShareCt);
                    string message = prepareDataPacketForProcess();
                    // Echo the data back to the client.  
                    Send(handler, message);
                }
                else
                {
                    Console.WriteLine("Received result from process:" + content);
                    string[] splitContent = content.Split(';');
                    NR_OF_DONE_SLAVES++;
                   
                    Program.numeratorSumRed += double.Parse(splitContent[1]);
                    Program.denominatorSumARed += double.Parse(splitContent[2]);
                    Program.denominatorSumBRed += double.Parse(splitContent[3]);

                    Program.numeratorSumBlue += double.Parse(splitContent[4]);
                    Program.denominatorSumABlue += double.Parse(splitContent[5]);
                    Program.denominatorSumBBlue += double.Parse(splitContent[6]);

                    Program.numeratorSumGreen += double.Parse(splitContent[7]);
                    Program.denominatorSumAGreen += double.Parse(splitContent[8]);
                    Program.denominatorSumBGreen += double.Parse(splitContent[9]);

                    if (NR_OF_DONE_SLAVES == NR_OF_SLAVES)
                        finishComputation();
                }
            }
        }
        public static void finishComputation()
        {
            double resultR = Program.numeratorSumRed / Math.Sqrt(Program.denominatorSumARed * Program.denominatorSumBRed);
            double resultG = Program.numeratorSumGreen / Math.Sqrt(Program.denominatorSumAGreen * Program.denominatorSumBGreen);
            double resultB = Program.numeratorSumBlue / Math.Sqrt(Program.denominatorSumABlue * Program.denominatorSumBBlue);
            //Console.WriteLine("\n"+ resultR + " R      " + resultG + " G       " + resultB + " B      ");
            Console.Write("Distributed result is: " + (resultR + resultG + resultB) / 3);
        }
        private static string prepareDataPacketForProcess()
        {
            string result = "";
            result += "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\microsoft600x600.jpg";
            result = result + ";" + Program.mean1.R + ";" + Program.mean1.G + ";" + Program.mean1.B + ";";
            result += "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\vetnisupp600x600.jpg";
            result = result + ";" + Program.mean2.R + ";" + Program.mean2.G + ";" + Program.mean2.B + ";";
            //may god help us on race conditions
            result += processShareCt++;
            result += ";" + Program.width + ";" + Program.height;
            result += ";" + NR_OF_SLAVES;
            return result;
        }

        private static void Send(Socket handler, String data)
        {
            // Convert the string data to byte data using ASCII encoding.  
            byte[] byteData = Encoding.ASCII.GetBytes(data);

            // Begin sending the data to the remote device.  
            handler.BeginSend(byteData, 0, byteData.Length, 0,
                new AsyncCallback(SendCallback), handler);
        }

        private static void SendCallback(IAsyncResult ar)
        {
            try
            {
                // Retrieve the socket from the state object.  
                Socket handler = (Socket)ar.AsyncState;

                // Complete sending the data to the remote device.  
                int bytesSent = handler.EndSend(ar);
                Console.WriteLine("Sent {0} bytes to client.", bytesSent);

                handler.Shutdown(SocketShutdown.Both);
                handler.Close();

            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
            
    }
}
