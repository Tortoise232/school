using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RSACrypter
{
    public partial class Form1 : Form
    {

        RSACrypter myCrypter;
        public Form1()
        {
            InitializeComponent();
            Console.WriteLine("BUTTON PRESSED");
            myCrypter = new RSACrypter(109, 199);
           // myCrypter.d = 2753;
            //myCrypter.e = 17;
            qtextbox.AppendText(myCrypter.q.ToString());
            ptextbox.AppendText(myCrypter.p.ToString());
            ntextbox.AppendText(myCrypter.n.ToString());
            totienttextbox.AppendText(myCrypter.phin.ToString());
            publicKey.AppendText("(" + myCrypter.n + ", " + myCrypter.e + ")");
            privateKey.AppendText("(" + myCrypter.n + ", " + myCrypter.d + ")");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void encryptButton_Click(object sender, EventArgs e)
        {
            
            cipherText.Text = myCrypter.encryptText(plainText.Text);
            cipherTextNumerical.ResetText();
            if(plainText.Text.Length !=0 )
                foreach (BigInteger x in myCrypter.cipherTextAsNumbers)
                {
                    cipherTextNumerical.Text += x;
                    cipherTextNumerical.Text += " ";
                }

            plainText.ResetText();
        }

        private void decryptButton_Click(object sender, EventArgs e)
        {
            plainText.Text = myCrypter.decryptText(cipherText.Text);
            cipherText.ResetText();
            cipherTextNumerical.ResetText();
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }
    }
}
