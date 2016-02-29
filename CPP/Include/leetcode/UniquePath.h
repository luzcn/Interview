#pragma once
#include "stdafx.h"

namespace leetcode
{
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> path(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
                break;

            path[i][0] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j])
                break;

            path[0][j] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                    path[i][j] = 0;
                else
                {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
        }

        return path[m - 1][n - 1];
    }
}