#pragma once
#include "stdafx.h"
#include <queue>
namespace careercup
{
    namespace helper
    {
        // Partition
        int partition(vector<int>& nums, int l, int r)
        {
            int m = l - 1;
            int pivot = nums[r];
            for (int i = l; i < r; i++)
            {
                if (nums[i] < pivot)
                {
                    m++;
                    if (m != i)
                    {
                        int temp = nums[i];
                        nums[i] = nums[m];
                        nums[m] = temp;
                    }
                }
            }
            m++;
            int temp = nums[r];
            nums[r] = nums[m];
            nums[m] = temp;

            return m;
        }

        // find kth smallest divide-conquer solution, similar to quick sort.
        int kthSmallestDivideConquer(vector<int>& nums, int l, int r, int k)
        {
            if (l == r)
                return nums[l];

            int m = partition(nums, l, r);
            int leftlen = m - l + 1;
            if (leftlen == k)
                return nums[m];
            else if (leftlen > k)
                return kthSmallestDivideConquer(nums, l, m - 1, k);
            else
                return kthSmallestDivideConquer(nums, m + 1, r, k - m - 1);
        }

        int kthSmallestHeap(vector<int>& nums, int k)
        {
            vector<int> v(k);
            make_heap(v.begin(), v.end());


            return 0;
        }
    }
    // Find the kth smallest element from an array
    int findKthSmallest(vector<int>& nums, int k)
    {
        return helper::kthSmallestDivideConquer(nums, 0, nums.size() - 1, k);
    }
}