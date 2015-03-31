using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice.LeetCode.Bits
{
    /***
        Reverse bits of a given 32 bits unsigned integer.

        For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
        return 964176192 (represented in binary as 00111001011110000010100101000000).
    ***/
    class ReverseBits
    {
        public uint reverseBits(uint n)
        {
            List<uint> list = new List<uint>();
            for (int i = 31; i >= 0; i--)
            {
                list.Add((n & 1));
                n >>= 1;
            }

            foreach (var v in list)
            {
                Console.Write(v);
            }
            Console.WriteLine();

            uint res = 0;

            for (int i = 31; i >= 0; i--)
            {
                res += System.Convert.ToUInt32(list[i] * (Math.Pow(2, 31 - i)));
            }

            return res;
        }
    }
}
