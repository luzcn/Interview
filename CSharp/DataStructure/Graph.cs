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
            var vertix = graph.GetLength(0);

            if (!map.ContainsKey(s))
            {
                que.Enqueue(s);
                map.Add(s, true);

                while (que.Count() != 0)
                {
                    var current = que.Dequeue();
                    for (int i = 0; i < vertix; i++)
                    {
                        if (graph[s,i] == 1 && map.cout)
                    }
                }
            }

        }
        private Dictionary<int, bool> map = new Dictionary<int, bool>();
        private Queue<int> que = new Queue<int>();
    }
}
