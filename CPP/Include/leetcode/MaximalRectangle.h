#pragma once

#include "stdafx.h"


// Given a 2D binary matrix filled with 0's and 1's, 
// find the largest rectangle containing all ones and return its area.
namespace leetcode
{
    int maximalRectangle(vector<vector<int>>& M)
    {
        if (M.empty())
            return 0;

        int m = M.size();
        int n = M[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // count how many contigouse '1' in each row.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    if (j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    int minVal = dp[i][j];
                    int k = i;

                    while (k >= 0 && M[k][j] == 1)
                    {
                        minVal = min(minVal, dp[k][j]);
                        maxArea = max(maxArea, minVal * (i - k + 1));
                        k--;
                    }
                }
            }
        }
        return maxArea;
    }

    // Maximal Square
    //  Given a 2D binary matrix filled with 0's and 1's, 
    // find the largest square containing all 1's and return its area.
    //
    //  For example, given the following matrix :
    //
    //  1 0 1 0 0
    //  1 0 1 1 1
    //  1 1 1 1 1
    //  1 0 0 1 0
    //
    // Return 4.
    int maximalSquare(vector<vector<int>>& M) 
    {
        if (M.empty())
            return 0;

        int m = M.size();
        int n = M[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // count how many contigouse '1' in each row.
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    if (j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1] + 1;
                    }
                }
            }
        }

        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j] == 1)
                {
                    int minVal = dp[i][j];
                    int k = i;

                    while (k >= 0 && M[k][j] == 1)
                    {
                        minVal = min(minVal, dp[k][j]);
                        if (i - k + 1 == minVal)
                        {
                            maxArea = max(maxArea, minVal * (i - k + 1));
                        }

                        k--;
                    }
                }
            }
        }
        return maxArea;
    }
}