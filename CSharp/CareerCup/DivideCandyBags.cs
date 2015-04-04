using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.CareerCup
{
    class DivideCandyBags
    {
        public int divide(int[] bags)
        {
            if (bags.Length == 0)
                return 0;

            if (bags.Length == 1)
                return bags[0];

            if (bags.Length == 2)
                return Math.Abs(bags[0] - bags[1]);

            return 0;
        }

        private int divideRec(int[] bags, int sum1, int sum2, int index)
        {
            if (index >= bags.Length)
                return Math.Abs(sum1 - sum2);

            var s = divideRec(bags, sum1 + bags[index], sum2, index + 1);
            var t = divideRec(bags, sum1, sum2 + bags[index], index + 1);

            return Math.Min(s, t);
        }


        // 
        private int divideDP(int[] bags)
        {

            throw new NotImplementedException();

            //if (bags.Length == 0)
            //    return 0;

            //int n = bags.Length;

            //int[] arr1 = new int[n + 1];
            //int[] arr2 = new int[n + 1];
            //int[] res = new int[n + 1];

            //res[0] = 0;


            //return res[n];
        }
    }
}
