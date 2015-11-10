#pragma once
#include "stdafx.h"

//There are a row of n houses, each house can be painted with one of the three colors : red, blue or green.
//The cost of painting each house with a certain color is different.
//You have to paint all the houses such that no two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
//For example, costs[0][0] is the cost of painting house 0 with color red; 
//costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
//
// DP solution: 
// Use p(i, k) to indicate the ith house paint the kth color, where i in [0,1..n) and k = 0,1,2. 
// p(i,k) = minimum of (for each m in [0,1,2] and m != k, p(i-1, m)) + cost[i][k]
// the initial condition is n == 0 return costs[0][k]
// we need to call this recursive function 3 times for each k = 0, 1, 2, and return minimum result;
namespace leetcode
{
    int dfs(vector<vector<int>>& costs, int n, int k)
    {
        if (n == 0)
            return costs[n][k];

        if (k == 0)
        {
            return min(dfs(costs, n - 1, 1), dfs(costs, n - 1, 2)) + costs[n][k];
        }
        else if (k == 1)
        {
            return min(dfs(costs, n - 1, 0), dfs(costs, n - 1, 2)) + costs[n][k];
        }
        else
        {
            return min(dfs(costs, n - 1, 1), dfs(costs, n - 1, 0)) + costs[n][k];
        }
    }


    int minCostDP(vector<vector<int>>& costs)
    {
        int n = costs.size();

        vector<int> dp(3, 0);
        for (int i = 0; i < 3; i++)
        {
            dp[i] = costs[0][i];
        }

        for (int i = 0; i < n; i++)
        {
            auto f0 = min(dp[1], dp[2]) + costs[i][0];
            auto f1 = min(dp[0], dp[2]) + costs[i][1];
            auto f2 = min(dp[0], dp[1]) + costs[i][2];

            dp[0] = f0;
            dp[1] = f1;
            dp[2] = f2;
        }

        return *min_element(dp.begin(), dp.end());
    }


    int minCostKColors(vector<vector<int>>& costs)
    {
        int n = costs.size();
        int k = costs[0].size();

        vector<int> dp(k, 0);
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            dp[i] = costs[0][i];

            if (dp[i] < min1)
            {
                min2 = min1;
                min1 = dp[i];
            }
            else if (dp[i] < min2)
            {
                min2 = dp[i];
            }
        }

        for (int i = 1; i < n; i++)
        {
            int currentMin1 = INT_MAX;
            int currentMin2 = INT_MAX;

            for (int j = 0; j < k; j++)
            {
                if (dp[j] == min1)
                {
                    dp[j] = min2 + costs[i][j];
                }
                else
                {
                    dp[j] = min1 + costs[i][j];
                }

                if (dp[j] < currentMin1)
                {
                    currentMin2 = currentMin1;
                    currentMin1 = dp[j];
                }
                else if (dp[j] < currentMin2)
                {
                    currentMin2 = dp[j];
                }
            }

            min1 = currentMin1;
            min2 = currentMin2;
        }

        return *min_element(dp.begin(), dp.end());
    }

    int minCost(vector<vector<int>>& costs)
    {
        if (costs.empty())
            return 0;

        return minCostKColors(costs);
    }
}