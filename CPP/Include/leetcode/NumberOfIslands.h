#pragma once

#include "stdafx.h"

namespace NumberOfIslands
{
    void flood_fill(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;

        if (grid[i][j] != '1')
            return;

        grid[i][j] = '3';

        flood_fill(grid, i - 1, j);
        flood_fill(grid, i + 1, j);
        flood_fill(grid, i, j - 1);
        flood_fill(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;

        if (grid.size() == 0)
            return 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    flood_fill(grid, i, j);
                }
            }
        }

        return count;
    }

  
}