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
    // BFS
    void bfs(vector<vector<int>>& rooms, std::queue<pair<int, int>>& que_candidate)
    {
        vector<pair<int, int>> dirs{ { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

        while (!que_candidate.empty())
        {
            int x = que_candidate.front().first;
            int y = que_candidate.front().second;
            que_candidate.pop();

            for (auto dir : dirs)
            {
                int i = x + dir.first;
                int j = y + dir.second;

                if (i < 0 || i >= rooms.size() || j < 0 || j >= rooms[0].size()
                    || rooms[i][j] == -1 || rooms[i][j] < rooms[x][y] + 1)
                {
                    continue;
                }

                rooms[i][j] = rooms[x][y] + 1;
                que_candidate.push({ i,j });
            }
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

        bfs(rooms, que_candidate);
    }
}