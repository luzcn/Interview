#pragma once
#include "stdafx.h"
//Given a list of integers, which denote a permutation.
//
//Find the previous permutation in ascending order.
//Example
//
//For[1, 3, 2, 3], the previous permutation is[1, 2, 3, 3]
//For[1, 2, 3, 4], the previous permutation is[4, 3, 2, 1]

namespace lintcode
{
    void swap(vector<int>& nums, int i, int j)
    {
        auto t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    vector<int> previousPermuation(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums;

        int n = nums.size();
        if (nums[n - 1] < nums[n - 2])
        {
            swap(nums, n - 1, n - 2);
            return nums;
        }

        int i = n - 2;
        for (i = n - 2; i > 0; i--)
        {
            // find the position, where the value is less than both left and right side value.
            if (nums[i - 1] > nums[i] && nums[i] <= nums[i + 1])
            {
                int leftValue = nums[i - 1];

                // in the range [i+1, n-1], find the maximum value which is larger than the left value
                int index = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (nums[j] > nums[index] && nums[j] < leftValue)
                    {
                        index = j;
                    }
                }

                swap(nums, i - 1, index);
                break;
            }
        }

        std::sort(nums.begin() + i, nums.end(), [&](int a, int b) {return a >= b; });

        return nums;
    }
}