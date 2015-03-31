using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice.LeetCode.Array
{
    class RemoveElement
    {
        public int Remove(int[] A, int elem)
        {
            int r = A.Length - 1;

            while (r >= 0 && A[r] == elem)
            {
                r--;
            }

            int l = 0;
            while (l <= r)
            {
                if (A[l] != elem)
                {
                    l++;
                }
                else
                {
                    A[l] = A[r];
                    A[r] = elem;
                    r--;
                }
            }

            return l;
        }
    }
}
