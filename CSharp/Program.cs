using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    using LeetCode;
    using CareerCup;
    class Program
    {
        static void Main(string[] args)
        {
            Permutations2 pm = new Permutations2();
            int[] num = { 3, 3, 0, 3 };

            var s = pm.PermuteUnique(num);

            foreach (var i in s)
                Console.WriteLine(string.Join(" ", i));
        }
    }
}
