using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    using LeetCode;
    using CareerCup;
    using DataStructure;
    class Program
    {
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
    }
}
