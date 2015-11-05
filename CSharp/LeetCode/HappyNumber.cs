using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class HappyNumber
    {
        public bool isHappy(int n)
        {
            IList<int> list = new List<int>();
            while (n >= 1 && !list.Contains(n))
            {
                list.Add(n);
                var str = Convert.ToString(n);
                int sum = 0;
                for (int i = 0; i < str.Length; i++)
                {
                    var t = str[i] - '0';
                    sum += t * t;
                }
                n = sum;
            }


            return n == 1;
        }
    }
}
