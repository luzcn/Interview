#pragma once
#include "stdafx.h"

namespace leetcode
{
    //  A group of two or more people wants to meet and minimize the total travel distance.
    //  You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group.
    //  The distance is calculated using Manhattan Distance, where distance(p1, p2) = | p2.x - p1.x | +| p2.y - p1.y |.
    //
    //    For example, given three people living at(0, 0), (0, 4), and (2, 2) :
    //    1 - 0 - 0 - 0 - 1
    //    |   |   |   |   |
    //    0 - 0 - 0 - 0 - 0
    //    |   |   |   |   |
    //    0 - 0 - 1 - 0 - 0
    //  The point(0, 2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.
    // So return 6.
    void getRows(vector<vector<int>>& grid, vector<int>& list)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    list.push_back(i);
                }
            }
        }
    }

    void getColumns(vector<vector<int>>& grid, vector<int>& list)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                if (grid[i][j] == 1)
                {
                    list.push_back(j);
                }
            }
        }
    }

    int min_distance(vector<int>& points, int origin)
    {
        int total_distance = 0;
        for (int p : points)
        {
            total_distance += abs(p - origin);
        }

        return total_distance;
    }

    int minTotalDistance(vector<vector<int>>& grid)
    {
        if (grid.empty())
            return INT_MAX;

        vector<int> rows;
        vector<int> cols;

        getRows(grid, rows);
        getColumns(grid, cols);


        int row = rows[rows.size() / 2];
        int col = cols[cols.size() / 2];
        
        return min_distance(rows, row) + min_distance(cols, col);
    }

    // follow up:
    // if in the maxtrix, some cells are blocked indicated as 'X', how to solve the problem.
}