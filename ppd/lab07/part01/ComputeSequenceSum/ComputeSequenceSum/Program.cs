

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Threading;

namespace ComputeSequenceSum
{
 
    class Program
    {
        
        public static Random random = new Random();
        public const int NUMBER_LENGTH = 10;
        public const int ARRAY_LENGTH = 20;
        public static ArrayList startingList = new ArrayList();
        public static ArrayList resultList = new ArrayList();

        public static void init()
        {
            fillStartingList();
            for (int i = 0; i < ARRAY_LENGTH; i++)
            {
                resultList.Add(new BigInteger(-1));
            }

        }

        public static void threadingSolution()
        {
            ArrayList threadList = new ArrayList();
            resultList[0] = startingList[0];
            int i = 1;
            while (i <= ARRAY_LENGTH)
            {
                Thread calcElem = new Thread(() => computeElement(i++));
                calcElem.Start();
                threadList.Add(calcElem);
            }

            foreach (Thread myThread in threadList)
            {
                myThread.Join();
            }
        }

        public static void computeElement(int position)
        {
            if (position == 0 || position >= ARRAY_LENGTH)
                return;
            //Console.Write("\nTHREAD " + position + " STARTED");
            //wait until the previous element is computed
            while ((BigInteger)resultList[position - 1] < 0)
            {
                System.Threading.Thread.Sleep(100);
                //Console.Write("\nTHREAD " + position + " IS WAITING FOR " + (position - 1));
            }
            //Console.Write("\nAccessing position: " + position);
            resultList[position] = (BigInteger)startingList[position] + (BigInteger)resultList[position - 1];
            //Console.Write("\nTHREAD " + position + " MADE BIG MATHS " + resultList[position]);
        }

        static void Main(string[] args)
        {
            init();
            for (int i = 0; i < ARRAY_LENGTH; i++)
                Console.Write(startingList[i] + " ");
            Console.WriteLine("\n---------------------------------------------");
            sequentialSolution();
            for (int i = 0; i < ARRAY_LENGTH; i++)
                Console.Write(resultList[i] + " ");
            for (int i = 0; i < ARRAY_LENGTH; i++)
                resultList[i] = new BigInteger(-1);
            threadingSolution();
            Console.WriteLine("\n---------------------------------------------");
            for (int i = 0; i < ARRAY_LENGTH; i++)
                Console.Write(resultList[i] + " ");
            BigInteger resultSimple = new BigInteger(0);
            for (int i = 0; i < ARRAY_LENGTH; i++)
                resultSimple += (BigInteger)resultList[i];
            BigInteger resultThreading = threadAddNumbers(resultList);
            Console.WriteLine("ADDING A BUNCH OF NUMBERS SIMPLE: " + resultSimple);
            Console.WriteLine("ADDING A BUNCH OF NUMBERS THREAD: " + resultThreading);
            
            
        }

        public static void sequentialSolution()
        {
            resultList[0] = startingList[0];
            for (int i = 1; i < ARRAY_LENGTH; i++)
                resultList[i] = (BigInteger)resultList[i - 1] + (BigInteger)startingList[i];
        }


        public static BigInteger RandomBigInt()
        {
            byte[] bytes = new byte[NUMBER_LENGTH];
            BigInteger R;
            random.NextBytes(bytes);
            bytes[bytes.Length - 1] &= (byte)0x7F; //force sign bit to positive
            R = new BigInteger(bytes);

            return R;
        }

        static void fillStartingList()
        {
            for (int i = 0; i < ARRAY_LENGTH; i++)
                startingList.Add(RandomBigInt());
        }

        
        static BigInteger threadAddNumbers(ArrayList a)
        {
            Console.WriteLine(a.Count);
            if (a.Count > 1)
            {
                //bad array splitting (it works tho)
                ArrayList aBottomHalf = new ArrayList(a.Count / 2);
                ArrayList aTopHalf = new ArrayList(a.Count / 2);
                for (int i = 0; i < a.Count / 2; i++)
                {
                    aBottomHalf.Add(a[i]);
                    aTopHalf.Add(a[i + a.Count / 2]);
                }
                if (a.Count % 2 != 0)
                    aTopHalf.Add(a[a.Count - 1]);


                BigInteger resultBot = new BigInteger(0);
                BigInteger resultTop = new BigInteger(0);

                //start a thread for each halfs of the array (create a binary tree of thread / thread calls)
                Thread bottomThread = new Thread(() => resultBot = threadAddNumbers(aBottomHalf));
                Thread topThread = new Thread(() => resultTop = threadAddNumbers(aTopHalf));

                bottomThread.Start();
                topThread.Start();

                bottomThread.Join();
                topThread.Join();
                //uber fucking magic
                return resultBot + resultTop;
                   
            }
            //fucking magic
            return (BigInteger)a[0];

        }
    }
}
