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
    int longestIncreasingSubsequence(vector<int> nums)
    {
        int n = nums.size();
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    M[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    M[i][j] = M[i][j - 1] + 1;
                }
                else
                    M[i][j] = M[i][j - 1];
            }
        }

        int len = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][n - 1] > len)
            {
                len = M[i][n - 1];
            }
        }

        return len;
    }
}
