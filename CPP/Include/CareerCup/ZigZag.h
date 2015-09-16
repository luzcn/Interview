#pragma once
#include "stdafx.h"
// A sequence of numbers is called a zig-zag sequence if the differences 
// between successive numbers strictly alternate between positive and negative.
// 
// The first difference(if one exists) may be either positive or negative.
//
// A sequence with fewer than two elements is trivially a zig - zag sequence.
//
// For example, 1, 7, 4, 9, 2, 5 is zigzag
// because the differences(6, -3, 5, -7, 3)  are alternately positive and negative.
// 
// In contrast, 1, 4, 7, 2, 5 and 1, 7, 4, 5, 5 are not zig - zag sequences, 
// the first because its first two differences are positive and the second because its last difference is zero.
//
// Given a sequence of integers, sequence, 
// return the length of the longest subsequence of sequence that is a zig - zag sequence.
// 
// A subsequence is obtained by deleting some number of elements(possibly zero) from the original sequence, 
// leaving the remaining elements in their original order.
namespace careercup
{
    // consider the example: 5,3,4,8,6,7
    // 1. set dp[0]=1,dp[1]=2, this is trivial
    // 2. for each i in [2...n-1], 
    // - if previous is positive and A[i] < A[i-1], then dp[i] = dp[i-1]+1, else keep as dp[i-1]
    // - if previous is negative and A[i] > A[i-1], then dp[i] = dp[i-1]+1, else keep as dp[i-1]
    // the dp array should be [1,2,3,3,4,5] so output 7
    int longestZigZag(vector<int> A)
    {
        if (A.size() <= 2)
            return A.size();

        vector<int> dp(A.size(), 1);
        dp[1] = 2;
        bool isPos = false;

        if (A[1] > A[0])
            isPos = true;
        if (A[1] < A[0])
            isPos = false;

        for (int i = 2; i < A.size(); i++)
        {
            if (isPos)
            {
                if (A[i] < A[i - 1])
                {
                    dp[i] = dp[i - 1] + 1;
                    isPos = false;
                }
                else
                    dp[i] = dp[i - 1];
            }
            else
            {
                if (A[i] > A[i - 1])
                {
                    dp[i] = dp[i - 1] + 1;
                    isPos = true;
                }
                else
                    dp[i] = dp[i - 1];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
}