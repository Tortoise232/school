using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Collections;
using System.Diagnostics;

namespace pollardp_1
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true) {
                Console.WriteLine("Give (another) number!");
                BigInteger nr = BigInteger.Parse(Console.ReadLine());
                Console.WriteLine(nr);
                Stopwatch time = new Stopwatch();
                time.Start();
                ArrayList result = factoriseP1(nr);
                time.Stop();
                Console.WriteLine("pollard's p-1: " + time.ElapsedMilliseconds);
                for (int j = 0; j < result.Count; j++)
                    Console.Write(result[j] + " ");
                Console.Write("\n");
                time = new Stopwatch();
                time.Start();
                result = factoriseS(nr);
                time.Stop();
                Console.WriteLine("simple fact: " + time.ElapsedMilliseconds);
                for (int j = 0; j < result.Count; j++)
                    Console.Write(result[j] + " ");
                Console.Write("\n");
            }
            
        }

        
        public static BigInteger modularExpo(BigInteger nr, BigInteger pow, BigInteger mod)
        {
            BigInteger res = 1;
            nr = nr % mod;
            while (pow > 0)
            {
                if (pow % 2 == 1)
                    res = (res * nr) % mod;
                pow /= 2;
                nr = (nr * nr) % mod;
            }
            return res;
        }
        public static BigInteger randomBigInt()
        {
            Random random = new Random();
            byte[] bytes = new byte[1];
            BigInteger R;
            random.NextBytes(bytes);
            R = new BigInteger(bytes);

            return R;
        }

        public static BigInteger gcd(BigInteger a, BigInteger b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }


        public static bool isPrime(BigInteger a)
        {
            for (BigInteger i = 2; i < a; i++)
                if (a % i == 0)
                    return false;
            return true;
        }

        public static BigInteger factorial(BigInteger nr)
        {
            BigInteger result = 1;
            while (nr > 1)
                result *= nr--;
            return result;
        }

        public static ArrayList factoriseS(BigInteger a)
        {
            ArrayList result = new ArrayList();
            for (BigInteger b = 2; a > 1; b++)
            {
                while (a % b == 0)
                {
                    a /= b;
                    result.Add(b);
                }
            }
            return result;
        }

        public static ArrayList factoriseP1(BigInteger number)
        {
            ArrayList result = new ArrayList();
            BigInteger b = new BigInteger(10);
            //b!
            BigInteger k = factorial(b);
            while (true)
            {
                //random number a from number 0 to n-1
                BigInteger a;
                do
                {
                    a = randomBigInt();
                    if (a < 0)
                        a = -a;
                    Console.WriteLine("ANOTHER RAND PLS " + a);
                } while (a >= number);
                Console.WriteLine("OK TRY  " + a);
                BigInteger tmp = modularExpo(a, k, number);
                tmp--;
                //gcd(a^k - 1 (mod n), number);
                BigInteger gcdRes = gcd(tmp, number);
                if(gcdRes != 1 && gcdRes > 0)
                    if (isPrime(gcdRes))
                    {
                        result.Add(gcdRes);
                        number /= gcdRes;
                    }
                if (isPrime(number))
                {
                    result.Add(number);
                    return result;
                }

            }
        }

    }
}
