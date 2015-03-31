#pragma once
#include "stdafx.h"
#include <algorithm>

namespace LongestCommonSubsequence
{
    string lcs(string s, string t)
    {
        // construct the dp table.
        int m = s.size();
        int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }


        // backtrack
        string result("");
        auto x = m;
        auto y = n;

        while (x > 0 && y > 0)
        {
            if (dp[x][y] == dp[x][y - 1])
            {
                y--;
            }
            else if (dp[x][y] == dp[x-1][y])
            {
                x--;
            }
            else
            {
                result.append(s.substr(x - 1, 1));
                x--;
                y--;
            }
        }
        std::reverse(result.begin(), result.end());

        return result;
    }
}