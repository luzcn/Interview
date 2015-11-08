using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /**
     *  Given an unsorted integer array, find the first missing positive integer.
        For example,
        Given [1,2,0] return 3,
        and [3,4,-1,1] return 2.
        Your algorithm should run in O(n) time and uses constant space. 
     **/
    class FindMissingPositive
    {
        public int FirstMissingPositive(int[] A)
        {
            // similar to counting sort
            // let A[i-1] = i, i>=1
            // Note: elements in A can be larger than array size.
            if (A.Length == 0)
                return 1;

            int n = A.Length;
            for (int i = 0; i < n; i++)
            {
                var t = A[i];
                while (t > 0 && t < n && A[t - 1] != t)
                {
                    var temp = A[t - 1];
                    A[t - 1] = t;
                    t = temp;
                    A[i] = temp;
                }
            }

            Console.WriteLine(string.Join(" ", A));

            int index = 0;
            for (index = 0; index < n; index++)
            {
                if (A[index] != index + 1)
                    break;
            }
            return index + 1;
        }
    }
}
