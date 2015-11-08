using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /**
        Given a list of non negative integers, arrange them such that they form the largest number.

        For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

        Note: The result may be very large, so you need to return a string instead of an integer.
    ***/
    public class LargestNumber
    {
        public string getLargestNumber(int[] num)
        {
            Array.Sort(num, (a, b) =>
            {
                var s = Convert.ToString(a) + Convert.ToString(b);
                var t = Convert.ToString(b) + Convert.ToString(a);
                return t.CompareTo(s);
            });

            var res = string.Join("", num);
            return (res[0] == '0') ? "0" : res;
        }
#if false
        public string getLargestNumber(int[] num)
        {
            List<int> numlist = new List<int>();
            foreach(var i in num)
            {
                numlist.Add(i);
            }

            //string res = string.Empty;
            List<List<int>> sol = new List<List<int>>();
            getPermutation(numlist, sol, new List<int>());

            List<string> list = new List<string>();

            foreach(var l in sol)
            {
                list.Add(string.Join("", l));
            }

            list.Sort((a, b) => { return b.CompareTo(a); });

            return list[0];
        }

        private void getPermutation(List<int> numlist, List<List<int>> sol, List<int> current)
        {
            if (numlist.Count == 0)
            {
                sol.Add(new List<int>(current));
                return;
            }

            for (int i = 0; i < numlist.Count; i++)
            {
                current.Add(numlist[i]);
                numlist.RemoveAt(i);
                getPermutation(numlist, sol, current);
                numlist.Insert(i, current[current.Count - 1]);
                current.RemoveAt(current.Count - 1);
            }
        }
#endif

    }
}
