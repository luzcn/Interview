#pragma once
#include "stdafx.h"

namespace careercup
{
    //      Longest Increasing Subsequence
    //    Given a sequence of integers, find the longest increasing subsequence(LIS).
    //    You code should return the length of the LIS.
    // 
    //    Example
    //    For[5, 4, 1, 2, 3], the LIS  is[1, 2, 3], return 3
    //    For[4, 2, 4, 5, 3, 7], the LIS is[4, 4, 5, 7], return 4
    //    Challenge
    //    Time complexity O(n ^ 2) or O(nlogn)
    //  For i in [0...n-1], dp[i] = max of dp[j] + 1, for j in [0..i).
    int longestIncreasingSubsequence(vector<int> nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] >= nums[j] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }


    // O(nlogn) time
    int longestIncreasingSubsequence2(vector<int> nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        vector<int> LIS;
        //int longestLength = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]);
            if (it == LIS.end())
            {
                LIS.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }

            //longestLength = max(longestLength, (int)LIS.size());
        }

        return LIS.size();
    }
}
#if 0
vector<int> v{ 88,4,24,82,86,1,56,74,71,9,8,18,26,53,
    77,87,60,27,69,17,76,23,67,14,98,13,10,83,20,43,39,29,92,31,0,30,90,70,37,59 };
#endif