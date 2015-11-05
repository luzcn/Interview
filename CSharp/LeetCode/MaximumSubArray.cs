using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class MaximumSubArray
    {
        // The O(n) solution
        public int MaxSubArray(int[] A)
        {
            int maxSum = int.MinValue;
            if (A.Length == 0)
                return 0;
            if (A.Length == 1)
                return A[0];

            int currentSum = 0;
            for (int i = 0; i < A.Length; i++)
            {
                currentSum += A[i];
                maxSum = Math.Max(maxSum, currentSum);
                currentSum = Math.Max(0, currentSum);
            }
            return maxSum;
        }

        // Divide-Conquer solution.
    }
}
