using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class SlidingWindowMaximum
    {
        public int[] MaxSlidingWindow(int[] nums, int k)
        {
            int[] result = new int[nums.Length - k + 1];
            LinkedList<int> list = new LinkedList<int>();

            // check the first k elements
            // always keep the first element is the maximum
            for (int i = 0; i < k; i++)
            {
                if (list.Count > 0 && nums[list.Last()] <= nums[i])
                {
                    list.RemoveLast();
                }

                list.AddLast(i);
            }
            result[0] = nums[list.First()];

            for (int i = k; i < nums.Length; i++)
            {
                if (list.Count > 0 && list.First() == i - k)
                {
                    list.RemoveFirst();
                }

                while(list.Count > 0 && nums[list.Last()] <= nums[i])
                {
                    list.RemoveLast();
                }

                list.AddLast(i);

                result[i - k + 1] = nums[list.First()];
            }

            return result;
        }
    }
}
