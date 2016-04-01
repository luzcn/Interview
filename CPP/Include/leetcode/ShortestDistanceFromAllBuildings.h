#pragma once
#include "stdafx.h"

// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
// You can only move up, down, left and right.You are given a 2D grid of values 0, 1 or 2, where:
//
//  Each 0 marks an empty land which you can pass by freely.
//  Each 1 marks a building which you cannot pass through.
//  Each 2 marks an obstacle which you cannot pass through.
//
// For example, given three buildings at(0, 0), (0, 4), (2, 2), and an obstacle at(0, 2) :
//
//    1 - 0 - 2 - 0 - 1
//    |   |   |   |   |
//    0 - 0 - 0 - 0 - 0
//    |   |   |   |   |
//    0 - 0 - 1 - 0 - 0
//
//    The point(1, 2) is an ideal empty land to build a house, as the total travel distance of 3 + 3 + 1 = 7 is minimal.
//    So return 7.
//
//    Note:
// There will be at least one building.
// If it is not possible to build such house according to the above rules, return -1.

// brute force solution
// for each cell which has value '0', use bfs find the shortest distance to all the house (value is '1').
// if there is one house unreachable from this cell, returns the distance as INT_MAX;
namespace leetcode
{
    struct point
    {
        point(int _x, int _y, int d)
            :x(_x), y(_y), distance(d)
        {}

        int x;
        int y;
        int distance;
    };

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distance, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        std::queue<point> que;
        que.push({ i - 1, j, 1 });
        que.push({ i + 1, j, 1 });
        que.push({ i, j - 1, 1 });
        que.push({ i, j + 1, 1 });

        while (!que.empty())
        {
            auto p = que.front();
            que.pop();

            if (p.x < 0 || p.x >= m || p.y < 0 || p.y >= n
                || visited[p.x][p.y] || grid[p.x][p.y] != 0)
            {
                continue;
            }


            visited[p.x][p.y] = true;
            if (distance[p.x][p.y] != INT_MAX)
                distance[p.x][p.y] += p.distance;

            que.push({ p.x - 1, p.y, p.distance + 1 });
            que.push({ p.x + 1, p.y, p.distance + 1 });
            que.push({ p.x, p.y - 1, p.distance + 1 });
            que.push({ p.x, p.y + 1, p.distance + 1 });
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    distance[i][j] = INT_MAX;
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid)
    {
        if (grid.empty())
            return -1;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> distance(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    bfs(grid, distance, i, j);
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (distance[i][j] < result)
                    {
                        result = distance[i][j];
                    }
                }
            }
        }

        return result == INT_MAX ? -1 : result;
    }
}