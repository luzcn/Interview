using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice
{
    using LeetCode;
    class Program
    {
        static void Main(string[] args)
        {
            LargestNumber ln = new LargestNumber();

            int[] num = { 3, 30, 34, 5, 9 };
            Console.WriteLine(ln.getLargestNumber(num));


        }
    }
}
