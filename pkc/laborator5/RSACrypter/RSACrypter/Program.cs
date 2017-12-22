using System;
using System.Collections;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Numerics;
namespace RSACrypter
{
    static class Program
    {

        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
            
        }
        public static bool isPrime(BigInteger nr)
        {
            for (int i = 2; i < nr / 2; i++)
                if (nr % 2 == 0)
                    return false;
            return true;
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

        public static BigInteger randomPrime()
        {
            BigInteger nr = randomBigInt();
            while (!isPrime(nr))
                nr = randomBigInt();
            return nr;
        }
        public static BigInteger randomBigInt()
        {
            Random random = new Random();
            byte[] bytes = new byte[1];
            BigInteger R;
            random.NextBytes(bytes);
            bytes[bytes.Length - 1] &= (byte)0x7F; //force sign bit to positive
            R = new BigInteger(bytes);
            
            return R;
        }

        public static BigInteger gcd(BigInteger a, BigInteger b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }


        
    }
    public class RSACrypter
    {
        public BigInteger n, p, q, phin, d, e;
        public RSACrypter(BigInteger p, BigInteger q)
        {
            this.p = p;
            this.q = q;
            this.n = p * q;
            this.phin = (p - 1) * (q - 1);
            this.setE(0);
            this.setD(0);
            this.printState();
        }

        public RSACrypter()
        {
            Random rand = new Random();
            this.p = 0;
            while (this.p == 0 || Program.isPrime(this.p))
                p = rand.Next(50);
            this.q = 0;
            while (this.q == 0 || Program.isPrime(this.q) || p == q)
                q = rand.Next(50);
            this.n = p * q;
            this.phin = (p - 1) * (q - 1);
            this.setE(0);
            this.setD(0);
            this.printState();
        }


        public RSACrypter(BigInteger p, BigInteger q, BigInteger d, BigInteger e)
        {
            this.p = p;
            this.q = q;
            this.n = p * q;
            this.phin = (p - 1) * (q - 1);
            this.setD(d);
            this.setE(e);
            this.printState();
        }
        public void setE(BigInteger e)
        {
            Console.WriteLine("SETTING E");
            if (e < phin && Program.gcd(e, phin) == 1 && e != 0)
                this.e = e;
            //if the provided d value is bad
            else
            {
                e = 1;
                do
                {
                    e++;
                } while (e < phin && Program.gcd(e, phin) != 1);
            }
            this.e = e;
            Console.WriteLine("DONE SETTING E");
        }
        public void setD(BigInteger d)
        {
            Console.WriteLine("SETTING D");
            if ((this.e * d) % phin == 1 && d != this.e)
            {     
                this.d = d;
                return;
            }

            this.d = new BigInteger(1);
            while ((this.e * this.d) % phin != 1 || this.d == this.e)
                this.d++;
            Console.WriteLine("DONE SETTING D");
        }

        public string encryptText(string text)
        {
            string result = "";
            for(int i = 0; i < text.Length; i ++)
                result += (char)(Program.modularExpo(new BigInteger(text[i]), this.e, this.n));
            return result;
        }

        public string decryptText(string text)
        {
            string result = "";
            for (int i = 0; i < text.Length; i++)
                result += (char)(Program.modularExpo(new BigInteger(text[i]), this.d, this.n));
            return result;
        }

        public string printState()
        {
            string text = "";
            text += " P: " + p + " Q: " + q + " N: " + n + " PHI(N): " + phin + " D: " + d + " E: " + e + "\n";
            text += "Public key: (" + n + ", " + e + ")";
            text += "\n";
            text += "Private key: (" + n + ", " + d + ")";
            return text;
        }
    }
    
}
