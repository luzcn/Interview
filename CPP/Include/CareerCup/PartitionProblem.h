#pragma once
#include "stdafx.h"
#include <numeric>

// Partition problem is to determine whether a given set can be partitioned into two subsets 
// such that the sum of elements in both subsets is same.
// For example:
// Given multiset {3,1,1,2,2,1}, a valid solution is two sets S1={1,1,1,2}, S2={2,3}.  
namespace careercup
{
    // input S: An array of integers
    // Return true if the array of numbers can be splited into two sub set; the sum of each subset is half of total sum
    bool partitionProblem(vector<int>& S)
    {
        if (S.empty())
            return true;

        // DP solution
        // let p(i,j) == true if there is a subset in {s1,s1...sj}, which sum is i, false as otherwise
        // p(0, j) is true
        // p(i,j) == true, if p(i, j-1) || p(i-s[j], j - 1) is true.

        int m = std::accumulate(S.begin(), S.end(), 0) / 2;
        int n = S.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // we can always find two empty set, and sum is 0.
        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = true;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= S[j - 1])
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - S[j - 1]][j - 1];
                }
            }
        }

        return dp[m][n];
    }
}