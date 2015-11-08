using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /// <summary>
    /// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
    /// 
    /// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, 
    /// so the function should return 3.
    /// </summary>
    class Numberof1Bits
    {
        public int HammingWeight(uint n)
        {
            int count = 0;
            while (n != 0)
            {
                if ((n & 1) == 1)
                    count++;
                n >>= 1;
            }

            return count;
        }
    }
}
