using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.DataStructure
{
    class Graph
    {
        /// <summary>
        /// Graph BFS
        /// </summary>
        /// <param name="graph">The input graph matrix</param>
        /// <param name="s"> The start graph node</param>
        public void BFS(int[,] graph, int s)
        {
            int vertex = graph.GetLength(0);

            IList<int> list = new List<int>();
            List<bool> visited = new List<bool>();
            for (int i = 0; i < vertex; i++)
            {
                visited.Add(false);
            }

            if (visited[s] == false)
            {
                que.Enqueue(s);     // use a queue for BFS
                visited[s] = true;

                while (que.Count() != 0)
                {
                    var u = que.Dequeue();
                    Console.WriteLine(u);

                    for (int i = 0; i < vertex; i++)
                    {
                        if (graph[u, i] == 1 && !visited[i])
                        {
                            que.Enqueue(i);
                            visited[i] = true;
                        }
                    }
                }
            }

        }
        private Queue<int> que = new Queue<int>();
    }
}
#if false
    static void Main(string[] args)
        {
            int[,] grid = new int[,]
            {
                {0,1,0,0},
                {0,0,1,1},
                {0,0,0,0},
                {1,0,0,0}
            };

            Graph gs = new Graph();
            gs.BFS(grid, 0);
        }
#endif