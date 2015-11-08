#pragma once
#include "stdafx.h"

// A table composed of N x M cells, each having a certain quantity of apples, is given. 
// You start from the upper-left corner. At each step you can go down or right one cell. 
// Find the maximum number of apples you can collect. 
namespace careercup
{
    int maxSum(vector<vector<int>>& M)
    {
        if (M.empty())
            return 0;

        int m = M.size();
        int n = M[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = M[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = M[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = M[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = M[i][j] + std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
}