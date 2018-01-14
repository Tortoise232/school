using System;
using System.Collections;
using System.Drawing;
using System.Threading;

namespace ImgCorrCoeff
{
    class MeanRGB
    {
        public float R = 0;
        public float G = 0;
        public float B = 0;
        public MeanRGB(float r, float g, float b)
        {
            this.R = r;
            this.G = g;
            this.B = b;
        }
    }

    class Program
    {
        static int NR_OF_CORES = 4;
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


        static int threadsDoneCt = 0;
        static void Main(string[] args)
        {
            //Console.Write("First image file path: ");
            string path1 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\uganda.jpg";
           // Console.Write("Second image file path: ");
            string path2 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\uganda2.jpg";

            initRun(path1, path2);
            double corCoff = correlationCoefficientSeq();
            clearData();
            initRun(path1, path2);
            corCoff = correlationCoefficientThreaded();
            Console.Read();

        }
        static void initRun(string path1, string path2)
        {
            loadImages(path1, path2);
            if (!checkImageSizes())
                return;
            //calc means
            mean1 = calcMean(image1);
            mean2 = calcMean(image2);

            height = image1.Height;
            width = image1.Width;
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
            Console.Write("Sequential result is: " + (resultR + resultG + resultB) / 3 + "\n");
            return (resultR + resultG + resultB) / 3;
        }

        public static void correlationCoeff(Object state)
        {
            int part = (int)state;
            int startingRow = (height / NR_OF_CORES) * part;
            int lastRow;
            if (part == NR_OF_CORES - 1)
                lastRow = height;
            else
              lastRow = startingRow + (height / NR_OF_CORES);
            Console.WriteLine("THREAD " + part + " STARTED FOR: " + startingRow + " THROUGH TO " + lastRow);
            for (int i = 0; i < width; i++)
                for (int j = startingRow; j < lastRow; j++)
                {
                    Color image1Pix;
                    Color image2Pix;
                    lock (image1)
                    {
                        //Console.WriteLine(i + " " + j);
                        image1Pix = image1.GetPixel(i, j);
                    }
                    lock (image2)
                    {
                        image2Pix = image2.GetPixel(i, j);
                    }
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
            Console.WriteLine("THREAD " + part + " FINISHED.");
            threadsDoneCt++;
        }

        static double correlationCoefficientThreaded()
        {
            
            for(int i = 0; i < NR_OF_CORES; i ++ )
            {
                ThreadPool.QueueUserWorkItem(correlationCoeff, i);
            }

            while (threadsDoneCt < NR_OF_CORES)
            {
                Thread.Sleep(100);
            }
            double resultR = numeratorSumRed / Math.Sqrt(denominatorSumARed * denominatorSumBRed);
            double resultG = numeratorSumGreen / Math.Sqrt(denominatorSumAGreen * denominatorSumBGreen);
            double resultB = numeratorSumBlue / Math.Sqrt(denominatorSumABlue * denominatorSumBBlue);
            //Console.WriteLine("\n"+ resultR + " R      " + resultG + " G       " + resultB + " B      ");
            Console.Write("Threading result is: " + (resultR + resultG + resultB) / 3 + "\n");
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
            float meanR = sumR / (bitmap.Width * bitmap.Height);
            float meanG = sumG / (bitmap.Width * bitmap.Height);
            float meanB = sumB / (bitmap.Width * bitmap.Height);
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
          
            height = 0;
            width = 0;

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
}
