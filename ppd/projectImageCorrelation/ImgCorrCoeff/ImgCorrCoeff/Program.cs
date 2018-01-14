using System;
using System.Drawing;
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
        static MeanRGB mean1;
        static MeanRGB mean2;

        //the images
        static Bitmap image1;
        static Bitmap image2;


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

        static void Main(string[] args)
        {
            //Console.Write("First image file path: ");
            string path1 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\15pixels1.png";
           // Console.Write("Second image file path: ");
            string path2 = "E:\\Program Files (x86)\\GitHub\\school\\ppd\\projectImageCorrelation\\ImgCorrCoeff\\ImgCorrCoeff\\15pixels2.png";
            loadImages(path1, path2);
            if (!checkImageSizes())
                return;
            //calc means
            mean1 = calcMean(image1);
            mean2 = calcMean(image2);

            double corCoff = correlationCoefficientSeq();
            Console.Write("Result is: " + corCoff);
            Console.Read();

        }
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        static double correlationCoefficientSeq()
        {
            double cont = 0;
            for (int i = 0; i < image1.Width; i++)
                for (int j = 0; j < image2.Height; j++)
                {
                    // double sumRedAdd = (image1.GetPixel(i, j).R - mean1.R) * (image2.GetPixel(i, j).R - mean2.R);
                    //double denSumRedA = Math.Pow((image1.GetPixel(i, j).R - mean1.R), 2);
                    //double denSumRedB = Math.Pow((image2.GetPixel(i, j).R - mean2.R), 2);
                    //Console.WriteLine(sumRedAdd + " " + denSumRedA + " " + denSumRedB);
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
            Console.WriteLine("\n"+ resultR + " R      " + resultG + " G       " + resultB + " B      ");
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
            Console.WriteLine("Size:" + bitmap.Height * bitmap.Width);
            float meanR = sumR / (bitmap.Width * bitmap.Height);
            float meanG = sumG / (bitmap.Width * bitmap.Height);
            float meanB = sumB / (bitmap.Width * bitmap.Height);
            Console.WriteLine("Sums: " + sumR + " " + sumG + " " + sumB);
            Console.WriteLine("Means: " + meanR + " " + meanG + " " + meanB);
            MeanRGB result = new MeanRGB(meanR, meanG, meanB);
            return result;
            
        }

        static void loadImages(string source1, string source2)
        {
            image1 = new Bitmap(source1);
            Console.WriteLine("IMAGE 1: ");
            for (int i = 0; i < image1.Width; i++)
                for (int j = 0; j < image1.Height; j++)
                {
                    Console.Write(image1.GetPixel(i, j).R + ",");
                }
            image2 = new Bitmap(source2);
            Console.WriteLine("IMAGE 2: ");
            for (int i = 0; i < image2.Width; i++)
                for (int j = 0; j < image2.Height; j++)
                {
                    Console.Write(image2.GetPixel(i, j).R + ",");
                }
        }

        void initMeans()
        {
            mean1 = calcMean(image1);
            mean2 = calcMean(image2);
        }

        static bool checkImageSizes()
        {
            return (image1.Height == image2.Height && image2.Width == image1.Width);
        }

    }
}
