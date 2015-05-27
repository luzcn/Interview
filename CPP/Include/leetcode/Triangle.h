#pragma once
#include "stdafx.h"
#include <numeric>
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/
namespace Triangle
{
    // Recursive helper function
    int minRec(vector<vector<int>>& T, int level, int index)
    {
        if (level >= T.size())
            return 0;

        return T[level][index] + std::min(minRec(T, level + 1, index), minRec(T, level + 1, index + 1));
    }


    // DP solution
    int minDP(vector<vector<int>>& T)
    {
        int m = T.size();
        vector<int> res(m);

        // put last row elements into res
        for (int i = 0; i < m; i++)
        {
            res[i] = T[m - 1][i];
        }

        // bottom up
        for (int level = m - 2; level >= 0; level--)
        {
            for (int i = 0; i < T[level].size(); i++)
            {
                res[i] = T[level][i] + std::min(res[i], res[i + 1]);
            }
        }
        return res[0];
    }


    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.empty() || triangle[0].empty())
            return 0;

        //return minRec(triangle, 0, 0);
        return minDP(triangle);
    }
}