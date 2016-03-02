#pragma once

#include "stdafx.h"
#include <algorithm>

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// Find the minimum element.
// You may assume no duplicate exists in the array.

namespace leetcode
{
    // Thought: if array is not roated, A[m] should < A[r], so if rotated, A[m] will > A[r]
    // so every time, we find A[m]>A[r], search the [m...r] range.
    int findMin(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int low = 0;
        int high = nums.size() - 1;

        while (low != high)
        {
            int m = low + (high - low) / 2;
            if (nums[m] > nums[high])
            {
                // check the range [m...high]
                low = m + 1;
            }
            else
            {
                high = m;
            }
        }

        return nums[low]; // low == high
    }

    // example: 
    // 9 1 2 3 3 3 3
    // 3 3 3 3 1 2 3
    // A[m] == A[r], but we cannot decide which direction to go.
    int findMinDuplicate(vector<int> &A)
    {
        return *std::min_element(A.begin(), A.end());
    }
}