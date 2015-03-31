using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /***
        Given a list of non negative integers, arrange them such that they form the largest number.

        For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

        Note: The result may be very large, so you need to return a string instead of an integer.
    ***/
    public class LargestNumber
    {
        public string getLargestNumber(int[] num)
        {
            string res = string.Empty;
            List<List<int>> result = new List<List<int>>();
            getAllString(num, result, 0);

            foreach (var v in result)
            {

            }

            return res;
        }

        private void getAllString(int[] num, List<List<int>> result, List<int> current, int index)
        {
            if(index >= num.Length)
            {
                return;
            }

            for (int i = 0; i < result.Count; i++)
            {
                //current.Insert(i, )
            }
        }
    }
}
