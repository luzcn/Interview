#pragma once
#include "stdafx.h"

namespace DungeonGame
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

    int calculateRec(vector<vector<int>>& matrix, int i, int j, int sum)
    {
        if (i >= matrix.size())
            return sum;
        if (j >= matrix[0].size())
            return sum;

        if (i == matrix.size() - 1 && j == matrix[0].size() - 1)
        {
            if (sum <= 0)
                return 10000;
            else
                return sum + matrix[i][j];
        }

        return std::min(calculateRec(matrix, i + 1, j, sum + matrix[i][j]), calculateRec(matrix, i, j + 1, sum + matrix[i][j]));
    }


    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        return calculateRec(dungeon, 0, 0, 0);
    }
}