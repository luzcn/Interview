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
            RepeatedDNASequence dna = new RepeatedDNASequence();
            Console.WriteLine(dna.FindRepeatedDnaSequences("GAGAGAGAGAGA")[0]);
        }
    }
}
