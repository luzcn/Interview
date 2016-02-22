#pragma once
#include "stdafx.h"
//
//You are given a m x n 2D grid initialized with these three possible values.
//
//- 1 - A wall or an obstacle.
//0 - A gate.
//INF - Infinity means an empty room.We use the value 231 - 1 = 2147483647 
// to represent INF as you may assume that the distance to a gate is less than 2147483647.
//
// Fill each empty room with the distance to its nearest gate.
// If it is impossible to reach a gate, it should be filled with INF.
//
// For example, given the 2D grid :
//
// INF - 1  0  INF
// INF INF INF - 1
// INF - 1 INF - 1
// 0   - 1 INF INF
//
//After running your function, the 2D grid should be :
//
//3 - 1   0   1
//2   2   1 - 1
//1 - 1   2 - 1
//0 - 1   3   4

namespace leetcode
{
    struct Point
    {
        int x;
        int y;
        int distance;

        Point(int _x, int _y, int d)
            :x(_x), y(_y), distance(d)
        {}
    };

    // BFS
    void bfs(vector<vector<int>>& rooms, std::queue<Point>& que_candidate)
    {
        int m = rooms.size();
        int n = rooms[0].size();

        //vector<vector<bool>> visited(m, vector<bool>(n, false));


        while (!que_candidate.empty())
        {
            int x = que_candidate.front().x;
            int y = que_candidate.front().y;
            int d = que_candidate.front().distance;
            que_candidate.pop();

            if (x < 0 || x >= m || y < 0 || y >= n
                || rooms[x][y] == -1 || rooms[x][y] < d)
            {
                continue;
            }

            rooms[x][y] = d;

            que_candidate.push({ x - 1, y, d + 1 });
            que_candidate.push({ x + 1, y, d + 1 });
            que_candidate.push({ x, y - 1, d + 1 });
            que_candidate.push({ x, y + 1, d + 1 });
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms)
    {
        if (rooms.empty())
            return;

        int m = rooms.size();
        int n = rooms[0].size();
        std::queue<pair<int, int>> que_candidate;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                {
                    que_candidate.push({ i, j });
                }
            }
        }

        vector<pair<int, int>> dirs{ {1,0},{-1,0},{0,1},{0,-1} };
        // BFS
        while (!que_candidate.empty())
        {
            int x = que_candidate.front().first;
            int y = que_candidate.front().second;
            que_candidate.pop();

            for (auto dir : dirs)
            {
                int i = x + dir.first;
                int j = y + dir.second;

                if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] == -1 || rooms[i][j] < rooms[x][y] + 1)
                    continue;

                rooms[i][j] = rooms[x][y] + 1;
                que_candidate.push({ i,j });
            }
        }
    }
}