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
        vector<vector<int>> DP(m, vector<int>(n));

        DP[m - 1][n - 1] = dungeon[m - 1][n - 1];
        for (int i = m - 2; i >= 0; i--)
        {
            if (DP[i + 1][n - 1] > 0)
            {
                DP[i][n - 1] = dungeon[i][n - 1];
            }
            else
                DP[i][n - 1] = DP[i + 1][n - 1] + dungeon[i][n - 1];
        }
        for (int j = n - 2; j >= 0; j--)
        {
            if (DP[m - 1][j + 1] > 0)
            {
                DP[m - 1][j] = dungeon[m - 1][j];
            }
            else
                DP[m - 1][j] = DP[m - 1][j + 1] + dungeon[m - 1][j];
        }


        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                auto v1 = DP[i + 1][j];
                auto v2 = DP[i][j + 1];

                if (v1 > 0 || v2 > 0)
                {
                    DP[i][j] = dungeon[i][j];
                }
                else
                {
                    DP[i][j] = dungeon[i][j] + max(v1, v2);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << DP[i][j] << " ";
            }
            cout << endl;
        }

        cout << "----------" << endl;

        return abs(DP[0][0]) + 1;
    }
}