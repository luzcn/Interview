using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice.LeetCode
{
    /// <summary>
    /// 
    /// Rotate an array of n elements to the right by k steps.
    /// For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4]. 
    /// 
    /// </summary>
    class RotateArray
    {
        public void Rotate(int[] nums, int k)
        {
            RotateRange(nums, 0, nums.Length - k - 1);

            RotateRange(nums, nums.Length - k, nums.Length - 1);

            RotateRange(nums, 0, nums.Length - 1);
        }

        private void RotateRange(int[] nums, int l, int r)
        {
            while (l < r)
            {
                var temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;

                l++;
                r--;
            }
        }
    }
}
