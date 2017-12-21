using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace HamiltoneanCycleParser
{
    

    class Node {
        public int id;
        public ArrayList successors = new ArrayList();
    }


    class Program
    {

        public static int NUMBER_NODES = 6;
        public static int NUMBER_OF_SUCC = 3;
        public static ArrayList graph = new ArrayList();
        public static Random rand = new Random();
        public static ArrayList executor = new ArrayList();
        public static bool done = false;
        static void initGraph()
        {
            for(int i = 0; i < NUMBER_NODES; i ++)
            {
                Node node = new HamiltoneanCycleParser.Node();
                node.id = i;
                for(int j = 0; j < NUMBER_OF_SUCC; j ++)
                {
                    int nextSucc = rand.Next(NUMBER_NODES);
                    while(node.successors.Contains(nextSucc) || node.id == nextSucc)
                        nextSucc = rand.Next(NUMBER_NODES);
                    node.successors.Add(nextSucc);
                }
                graph.Add(node);
            }

        } 

        static void printGraph()
        {
            foreach (Node n in graph)
            {
                Console.Write(n.id + ": ");
                foreach (int suc in n.successors)
                    Console.Write(suc + " ");
                Console.Write("\n");
            }
        }

        static bool checkCycle(ArrayList path)
        {
            for (int i = 0; i < NUMBER_NODES; i++)
                if (!path.Contains(i)) 
                    return false;
            for (int i = 0; i < path.Count - 1; i++)
                for (int j = i + 1; j < path.Count; j++)
                    if (path[i] == path[j] && i != 0 && j != path.Count - 1)
                        return false;
            return true;
        }

        static void findCycle(ArrayList pathSoFar, int node)
        {
            foreach(Node n in graph)
            {
                if (n.id != node)
                    continue;
                foreach(int succ in n.successors)
                {
                    if (pathSoFar.Contains(succ))
                        if (checkCycle(pathSoFar))
                        {
                            Console.Write("WE DID IT REDDIT: ");
                            foreach (int elem in pathSoFar)
                                Console.Write(elem + " ");
                            Console.Write("\n");
                            return;
                        }
                        else
                            return;
                    ArrayList pathCont = (ArrayList)pathSoFar.Clone();
                    pathCont.Add(succ);
                    Thread findNext = new Thread(() => findCycle(pathCont, succ));
                    findNext.Start();
                    executor.Add(findNext);
                }
            }
        }

        static void Main(string[] args)
        {
            initGraph();
            printGraph();
            findCycle(new ArrayList(), 0);
            while(!done)
                System.Threading.Thread.Sleep(100);
            foreach (Thread t in executor)
                t.Abort();
        }
    }
}
