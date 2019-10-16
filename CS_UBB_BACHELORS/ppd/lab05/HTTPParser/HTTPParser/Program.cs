using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace HTTPParser
{
    
    class Program
    {
        private Socket client;
        static void Main(string[] args)
        {
        }

        private async void ConnectToHost(string host)
        {
            IPHostEntry ipHostInfo = Dns.GetHostEntry(host);
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            IPEndPoint remoteEP = new IPEndPoint(ipAddress, 80);
            client = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                client.BeginAccept(remoteEP, new AsyncCallback(AcceptCallBack), client);
            }
            catch
            {

            };
        }

        static void AcceptCallBack(IAsyncResult result) {
               
        }
    }



    class SimpleParser
    {
        public SimpleParser()
        {
           
        }
          

    }

}
