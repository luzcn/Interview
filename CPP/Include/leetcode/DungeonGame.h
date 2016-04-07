#pragma once
#include "stdafx.h"

namespace leetcode
{
    /**
    he demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
    The dungeon consists of M x N rooms laid out in a 2D grid.
    Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

    The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

    Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

    In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

    Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

    For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.
    -2 (K) 	-3 	3
    -5 	-10 	1
    10 	30 	-5 (P)
    */


    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        // set the right bottom value as the dungeon value
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1];

        // compute the last column first
        for (int i = m - 2; i >= 0; i--)
        {
            if (dp[i + 1][n - 1] > 0)
            {
                dp[i][n - 1] = dungeon[i][n - 1];
            }
            else
            {
                dp[i][n - 1] = dp[i + 1][n - 1] + dungeon[i][n - 1];
            }
        }

        for (int j = n - 2; j >= 0; j--)
        {
            if (dp[m - 1][j + 1] > 0)
            {
                dp[m - 1][j] = dungeon[m - 1][j];
            }
            else
                dp[m - 1][j] = dp[m - 1][j + 1] + dungeon[m - 1][j];
        }


        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                int value1 = dp[i + 1][j];
                int value2 = dp[i][j + 1];

                if (value1 > 0 || value2 > 0)
                {
                    // if either bottom or righ cell has positive value
                    // we can keep the current dungeon value
                    dp[i][j] = dungeon[i][j];
                }
                else
                {
                    dp[i][j] = dungeon[i][j] + max(value1, value2);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        cout << "----------" << endl;

        return dp[0][0] > 0 ? 1 : abs(dp[0][0]) + 1;
    }
}