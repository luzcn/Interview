using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.CareerCup.Bits
{
    class Operations
    {
        /// <summary>
        /// Perform the addition by using bit operations.
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int add(int a, int b)
        {
            return a;
        }

        /// <summary>
        /// perform multiplication.
        /// </summary>
        /// <param name="a"></param>
        /// <param name="b"></param>
        /// <returns></returns>
        public int multiplication(int a, int b)
        {
            int result = 0;
            while (b != 0)
            {
                if ((b & 1) == 1)   // b is odd number, i.e. 1, 3, 5
                {
                    result = result + a;
                }

                a <<= 1;    // a = a*2
                b >>= 1;    // b = b/2
            }
            return result;
        }
    }
}
