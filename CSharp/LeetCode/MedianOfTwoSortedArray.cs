using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class MedianOfTwoSortedArray
    {
        public double FindMedianSortedArrays(int[] nums1, int[] nums2)
        {
            int m = nums1.Length;
            int n = nums2.Length;

            if ((m + n) % 2 == 0)
            {
                var t1 = findKthSmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2);
                var t2 = findKthSmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);

                return (t1 + t2) / 2.0;
            }
            else
            {
                return (double)findKthSmallest(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
            }
        }

        private int findKthSmallest(int[] A, int l1, int r1,
            int[] B, int l2, int r2, int k)
        {
            int m = r1 - l1;
            int n = r2 - l2;

            if (m <= 0) return B[k - 1];
            if (n <= 0) return A[k - 1];
            if (k <= 1) return Math.Min(A[l1], B[l2]);

            if (m / 2 + n / 2 + 1 >= k)
            {
                if (A[m / 2] >= B[n / 2]) // discard section 2
                {
                    return findKthSmallest(A, l1, m / 2, B, l2, r2, k);
                }
                else
                {
                    // discard section 4
                    return findKthSmallest(A, l1, r1, B, l2, n / 2, k);
                }
            }
            else
            {
                if (A[m / 2] >= B[n / 2])
                {
                    // discard section 3
                    return findKthSmallest(A, l1, r1, B, l2 + n / 2 + 1, r2, k - (n / 2 + 1));
                }
                else
                {
                    return findKthSmallest(A, l1 + m / 2 + 1, r1, B, l2, r2, k - (m / 2 + 1));
                }
            }
        }
    }
}
