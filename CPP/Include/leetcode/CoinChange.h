#pragma once
#include "stdafx.h"

namespace leetcode
{
    // dfs backtracking solution
    int dfs(vector<int>& coins, int amount, int m)
    {
        if (amount == 0)
        {
            return 0;
        }

        if ((m < 0 && amount > 0) || amount < 0)
        {
            return INT_MAX - 1;
        }

        return min(1 + dfs(coins, amount - coins[m], m), dfs(coins, amount, m - 1));
    }

    int coinChange(vector<int>& coins, int amount)
    {
        int m = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= amount; i++)
        {
            dp[i][0] = INT_MAX - 1;
        }

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i >= coins[j - 1])
                {
                    dp[i][j] = min(dp[i - coins[j - 1]][j] + 1, dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[amount][m] == INT_MAX - 1 ? -1 : dp[amount][m];
    }
}

#pragma region Follow up : change with limited coins
namespace followup
{
    int changeWithLimitedCoins(vector<int>& coins, 
        unordered_map<int, int>& coinsNumber, 
        int amount, int m)
    {
        if (amount == 0)
        {
            return 0;
        }

        if (m < 0 && amount > 0)
        {
            return INT_MAX - 1;
        }

        if (amount < 0)
        {
            return INT_MAX - 1;
        }

        int res1 = INT_MAX - 1;
        int res2 = INT_MAX - 1;
        if (coinsNumber[coins[m]] > 0)
        {
            coinsNumber[coins[m]]--;
            res1 = changeWithLimitedCoins(coins, coinsNumber, amount - coins[m], m) + 1;
            //coinsNumber[coins[i]]++;
        }
        res2 = changeWithLimitedCoins(coins, coinsNumber, amount, m - 1);

        return min(res1, res2);
    }
}
#pragma endregion
