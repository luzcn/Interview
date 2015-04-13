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
            int[][] grid = new int[][]
            { 
                new int[]{ 1, 1, 1, 1, 0 },
                new int[]{ 1,1,0,1,0} ,
                new int[]{1,1,0,0,0},
                new int[]{0,0,0,0,0}
            };

            Graph.BFS();
        }
    }
}
