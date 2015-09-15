#pragma once

#include "stdafx.h"

/***
 *	Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
 pennies (1 cent), write code to calculate the number of ways of representing n cents

 http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */
namespace CoinMakeChange
{
    /***
     *	Recursive solution.
     *
     *	To chage money, we have two choices:
     *	- we use this coin, so the total money will be m - S1.
     *	- we do not use this coins, the total money does not change, but the coins set will be change to Sn-1.
     *	C(m, Sn) = C((m - S1), Sn) + C(m, Sn-1);
     */
    int changeWays(int n, int coins[], int m)
    {
        if (n == 0)  // find solution.
        {
            return 1;
        }

        if (m <= 0 && n > 0) // If there is no more coins and n is greater than 0, no solution. 
        {
            return 0;
        }

        if (n < 0)
        {
            return 0;
        }

        return changeWays(n - coins[m - 1], coins, m) + changeWays(n, coins, m - 1);
    }

    // DP solution
    // m is the input money, n is the coins array size
    int change_DP(int n, int coins [], int m)
    {
        // create a (n+1)*m grid to save the solution.
        vector<vector<int>> grid(n + 1, vector<int>(m + 1));

        // initial the first row (i = 0) to all "1".
        for (int j = 0; j <= m; ++j)
        {
            grid[0][j] = 1;
        }


        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (i >= coins[j - 1])
                {
                    grid[i][j] = grid[i - coins[j - 1]][j] + grid[i][j - 1];
                }
                else
                {
                    // cannot take this coin.
                    grid[i][j] = grid[i][j - 1];
                }
            }
        }

        return grid[n][m];
    }
}