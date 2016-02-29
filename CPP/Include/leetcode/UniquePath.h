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

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0])
                break;

            rows[i] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j])
                break;

            cols[j] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
                else
                {
                    int value = rows[i - 1] + cols[j - 1];
                    rows[i] = value;
                    cols[j] = value;
                }
            }
        }

        return cols[n - 1];
    }
}