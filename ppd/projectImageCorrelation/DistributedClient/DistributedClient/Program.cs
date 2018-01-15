using System;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Text;
using System.Drawing;

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

// State object for receiving data from remote device.  
public class StateObject
{
    // Client socket.  
    public Socket workSocket = null;
    // Size of receive buffer.  
    public const int BufferSize = 256;
    // Receive buffer.  
    public byte[] buffer = new byte[BufferSize];
    // Received data string.  
    public StringBuilder sb = new StringBuilder();
}

public class DistributedClient
{
    static private String filename1 = "";
    static private String filename2 = "";
    static private int allocatedPart = -1;



    // The port number for the remote device.  
    private const int port = 11000;

    // ManualResetEvent instances signal completion.  
    private static ManualResetEvent connectDone =
        new ManualResetEvent(false);
    private static ManualResetEvent sendDone =
        new ManualResetEvent(false);
    private static ManualResetEvent receiveDone =
        new ManualResetEvent(false);

    // The response from the remote device.  
    private static String response = String.Empty;

    private static void parseResponse(String response)
    {
        string[] splitResponse = response.Split(';');
        filename1 = splitResponse[0];
        filename2 = splitResponse[1];
        allocatedPart = Int32.Parse(splitResponse[2]);
    }

    static MeanRGB mean1;
    static MeanRGB mean2;

    //the images
    static Bitmap image1;
    static Bitmap image2;

    static int height;
    static int width;

    //used for the correlation formula
    static double numeratorSumRed = 0;
    static double denominatorSumARed = 0;
    static double denominatorSumBRed = 0;

    static double numeratorSumGreen = 0;
    static double denominatorSumAGreen = 0;
    static double denominatorSumBGreen = 0;

    static double numeratorSumBlue = 0;
    static double denominatorSumABlue = 0;
    static double denominatorSumBBlue = 0;

    static int part;

    static int NR_OF_SLAVES;
    private static void initThings()
    {
        string[] splitResponse = response.Split(';');
        image1 = new Bitmap(splitResponse[0]);
        mean1 = new MeanRGB(Int32.Parse(splitResponse[1]), Int32.Parse(splitResponse[2]), Int32.Parse(splitResponse[3]));
        image2 = new Bitmap(splitResponse[4]);
        mean2 = new MeanRGB(Int32.Parse(splitResponse[5]), Int32.Parse(splitResponse[6]), Int32.Parse(splitResponse[7]));
        part = Int32.Parse(splitResponse[8]);
        height = Int32.Parse(splitResponse[9]);
        width = Int32.Parse(splitResponse[10]);
        NR_OF_SLAVES = Int32.Parse(splitResponse[11]);
        Console.WriteLine("SIZE: " + height + " " + width);
        Console.WriteLine("ASSIGNED PART: " + part);
        
    }
    
    private static void startWork()
    {
        Console.WriteLine("STARTED WORKING ...");
        initThings();
        int startingRow = (height / NR_OF_SLAVES) * part;
        int lastRow;
        if (part == NR_OF_SLAVES - 1)
            lastRow = height;
        else
            lastRow = startingRow + (height / NR_OF_SLAVES);
        for (int i = 0; i < width; i++)
        {
            for (int j = startingRow; j < lastRow; j++)
            {
                Color image1Pix;
                Color image2Pix;
                image1Pix = image1.GetPixel(i, j);
                image2Pix = image2.GetPixel(i, j);
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
        Console.WriteLine("DONE WORKING!");
    }

    private static string prepareResponse()
    {
        string result = "" + part + ";";
        result += numeratorSumRed + ";" + denominatorSumARed + ";" + denominatorSumBRed + ";";
        result += numeratorSumBlue + ";" + denominatorSumABlue + ";" + denominatorSumBBlue + ";";
        result += numeratorSumGreen + ";" + denominatorSumAGreen + ";" + denominatorSumBGreen + ";";
        return result;
    }

    private static void StartClient()
    {
        // Connect to a remote device.  
        try
        {
            // Establish the remote endpoint for the socket.  
            // The name of the   
            // remote device is "host.contoso.com".  
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint remoteEP = new IPEndPoint(ipAddress, port);

            // Create a TCP/IP socket.  
            Socket client = new Socket(ipAddress.AddressFamily,
                SocketType.Stream, ProtocolType.Tcp);

            // Connect to the remote endpoint.  
            client.BeginConnect(remoteEP,
                new AsyncCallback(ConnectCallback), client);
            connectDone.WaitOne();

            // Send test data to the remote device.  
            Send(client, "A process has connected!<EOF>");
            sendDone.WaitOne();

            // Receive the response from the remote device.  
            Receive(client);
            receiveDone.WaitOne();

            startWork();
            string workResult = prepareResponse();

            

            // Write the response to the console.  
            Console.WriteLine("Response received : {0}", response);



            // Release the socket.  
            client.Shutdown(SocketShutdown.Both);
            client.Close();

            //and then again for the response
            client = new Socket(ipAddress.AddressFamily,
                SocketType.Stream, ProtocolType.Tcp);
            client.BeginConnect(remoteEP,
                new AsyncCallback(ConnectCallback), client);
            connectDone.WaitOne();

            Send(client, workResult);

            // Release the socket.  
            client.Shutdown(SocketShutdown.Both);
            client.Close();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    private static void ConnectCallback(IAsyncResult ar)
    {
        try
        {
            // Retrieve the socket from the state object.  
            Socket client = (Socket)ar.AsyncState;

            // Complete the connection.  
            client.EndConnect(ar);

            Console.WriteLine("Socket connected to {0}",
                client.RemoteEndPoint.ToString());

            // Signal that the connection has been made.  
            connectDone.Set();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    private static void Receive(Socket client)
    {
        try
        {
            // Create the state object.  
            StateObject state = new StateObject();
            state.workSocket = client;

            // Begin receiving the data from the remote device.  
            client.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                new AsyncCallback(ReceiveCallback), state);
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    private static void ReceiveCallback(IAsyncResult ar)
    {
        try
        {
            // Retrieve the state object and the client socket   
            // from the asynchronous state object.  
            StateObject state = (StateObject)ar.AsyncState;
            Socket client = state.workSocket;

            // Read data from the remote device.  
            int bytesRead = client.EndReceive(ar);

            if (bytesRead > 0)
            {
                // There might be more data, so store the data received so far.  
                state.sb.Append(Encoding.ASCII.GetString(state.buffer, 0, bytesRead));

                // Get the rest of the data.  
                client.BeginReceive(state.buffer, 0, StateObject.BufferSize, 0,
                    new AsyncCallback(ReceiveCallback), state);
            }
            else
            {
                // All the data has arrived; put it in response.  
                if (state.sb.Length > 1)
                {
                    response = state.sb.ToString();
                }
                // Signal that all bytes have been received.  
                receiveDone.Set();
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    private static void Send(Socket client, String data)
    {
        // Convert the string data to byte data using ASCII encoding.  
        byte[] byteData = Encoding.ASCII.GetBytes(data);

        // Begin sending the data to the remote device.  
        client.BeginSend(byteData, 0, byteData.Length, 0,
            new AsyncCallback(SendCallback), client);
    }

    private static void SendCallback(IAsyncResult ar)
    {
        try
        {
            // Retrieve the socket from the state object.  
            Socket client = (Socket)ar.AsyncState;

            // Complete sending the data to the remote device.  
            int bytesSent = client.EndSend(ar);
            Console.WriteLine("Sent {0} bytes to server.", bytesSent);

            // Signal that all bytes have been sent.  
            sendDone.Set();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }

    public static int Main(String[] args)
    {
        StartClient();
        return 0;
    }
}
