using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class BitwiseAndRange
    {
        /**
         * Find the all the common bits of m, n from the highest position and set all the rest bits 0.
         **/
        public int RangeBitwiseAnd(int m, int n)
        {
            int count = 0;
            while (m != n)
            {
                m >>= 1;
                n >>= 1;
                count++;
            }

            return m << count;
        }
    }
}
