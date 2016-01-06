#pragma once
#include "stdafx.h"

// Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
// If there isn't one, return 0 instead.
//
// Example 1:
//
// Given nums = [1, -1, 5, -2, 3], k = 3,
// return 4. (because the subarray[1, -1, 5, -2] sums to 3 and is the longest)
//
// Example 2 :
//
//    Given nums = [-2, -1, 2, 1], k = 1,
//    return 2. (because the subarray[-1, 2] sums to 1 and is the longest)
//
//    Follow Up :
// Can you do it in O(n) time ?
#if 0
namespace leetcode
{
    int sumRangeQuery(vector<int>& sums, int i, int j)
    {
        return sums[j + 1] - sums[i];
    }

    int maxSubArrayLen(vector<int>& nums, int k)
    {
        if (nums.empty())
            return 0;

        vector<int> sum_list(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum_list[i + 1] = sum_list[i] + nums[i];
        }

        int start = 0;
        int end = nums.size() - 1;
        //int max_len = 0;

        while (start <= end)
        {
            int current_sum = sumRangeQuery(sum_list, start, end);
            if (current_sum == k)
            {
                return end - start + 1;
            }
            else if (current_sum < k)
            {
                if (nums[start] < nums[end])
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
            else
            {
                if (nums[start] < nums[end])
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }

        return 0;
    }
}
#endif

namespace leetcode
{
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        unordered_map<int, int> sum_map;
        int max_len = 0;
        int current_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            current_sum += nums[i];

            if (current_sum == k)
            {
                max_len = i + 1;    // the sum range is [0...i]
            }
            else if (sum_map.find(current_sum - k) != sum_map.end())
            {
                max_len = max(max_len, i - sum_map[current_sum - k]);
            }

            if (sum_map.find(current_sum) != sum_map.end())
            {
                sum_map[current_sum] = i;
            }
        }

        return max_len;
    }
}