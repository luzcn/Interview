#pragma once
#include "stdafx.h"

// Given a rod of length n inches and a
// table of prices pi for i=1, 2, 3,...n, determine the maximum revenue rn obtainable by cutting up the rod and selling the pieces.
// Note that if the price pn for a rod of length n is large enough, an optimal solution may require no cutting at all.
// Example: 1 5 8 9 10 17 17 20 24 30, given n = 4, return 10
namespace careercup
{
    int cutRodRec(vector<int>& price, int n, int i)
    {
        if (i > n)
            return 0;

        return std::max(cutRodRec(price, n - i, i) + price[i], cutRodRec(price, n, i + 1));
    }

    // top-down recursive with cache
    int cutRodRecAux(vector<int>& price, int n, vector<int>& r)
    {
        if (n == 0)
            return 0;
        if (r[n] >= 0)
        {
            return r[n];
        }

        int q = -1;
        for (int i = 1; i <= n; i++)
        {
            q = max(q, cutRodRecAux(price, n - i, r) + price[i - 1]);
        }
        r[n] = q;
        return q;
    }

    // bottom-up solution
    int cutRodDP(vector<int>& price, int n)
    {
        if (n > price.size())
            return 0;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = price[0];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = price[i - 1];
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i], dp[i - j] + dp[j]);
            }
        }

        return dp[n];
    }

    int cutRod(vector<int>& price, int n)
    {
        return cutRodDP(price, n);
    }
}