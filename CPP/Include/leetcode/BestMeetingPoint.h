#pragma once
#include "stdafx.h"

namespace leetcode
{
    // A group of two or more people wants to meet and minimize the total travel distance.
    // You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group.
    // The distance is calculated using Manhattan Distance, where distance(p1, p2) = | p2.x - p1.x | +| p2.y - p1.y |.
    //    For example, given three people living at(0, 0), (0, 4), and (2, 2) :
    //    1 - 0 - 0 - 0 - 1
    //    | | | | |
    //    0 - 0 - 0 - 0 - 0
    //    | | | | |
    //    0 - 0 - 1 - 0 - 0
    //    The point(0, 2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.So return 6.
    int minTotalDistance(vector<vector<int>>& grid)
    {
        if (grid.empty())
            return INT_MAX;

        vector<int> rows;
        vector<int> cols;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        sort(cols.begin(), cols.end());

        int minX = rows[rows.size() / 2];
        int minY = cols[cols.size() / 2];

        int totalDistance = 0;
        for (int i = 0; i < cols.size(); i++)
        {
            totalDistance += abs(minX - rows[i]);
            totalDistance += abs(minY - cols[i]);
        }
        
        return totalDistance;
    }

    // follow up:
    // if in the maxtrix, some cells are blocked indicated as 'X', how to solve the problem.
}