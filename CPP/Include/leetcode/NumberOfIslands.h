#pragma once

#include "stdafx.h"

namespace leetcode
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


    // A 2d grid map of m rows and n columns is initially filled with water.
    // We may perform an addLand operation which turns the water at position(row, col) into a land.
    // 
    // Given a list of positions to operate, count the number of islands after each addLand operation.
    //
    // An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
    //
    // You may assume all four edges of the grid are all surrounded by water.
    //    Example:
    // Given m = 3, n = 3, positions = [[0, 0], [0, 1], [1, 2], [2, 1]].
    //    Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
    //    0 0 0
    //    0 0 0
    //    0 0 0
    //
    //    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
    //    1 0 0
    //    0 0 0   Number of islands = 1
    //    0 0 0
    //
    //    Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
    //    1 1 0
    //    0 0 0   Number of islands = 1
    //    0 0 0
    //
    //    Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
    //    1 1 0
    //    0 0 1   Number of islands = 2
    //    0 0 0
    //
    //    Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
    //    1 1 0
    //    0 0 1   Number of islands = 3
    //    0 1 0
    //
    //    We return the result as an array: [1, 1, 2, 3]
    //
    //    Challenge :
    //    Can you do it in time complexity O(k log mn), where k is the length of the positions ?
    // Union-Find soltuion https://leetcode.com/discuss/69572/easiest-java-solution-with-explanations
    // 
    class Solution
    {
    public:
        vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions)
        {
            if (m <= 0 || n <= 0)
                return{};

            int dirs[4][2] = { { 0, 1 },{ 1, 0 },{ -1, 0 },{ 0, -1 } };
            vector<vector<bool>> isIsland(m, vector<bool>(n, false));

            int count = 0;  // number of islands
            vector<int> number_islands_list;

            for (const auto& p : positions)
            {
                if (!isIsland[p.first][p.second])
                {
                    int x = p.first;
                    int y = p.second;

                    isIsland[x][y] = true;
                    count++;

                    // compute the id
                    int id = n * x + y;
                    m_parent[id] = id;

                    // check the neigbors
                    for (int i = 0; i < 4; i++)
                    {
                        int newX = x + dirs[i][0];
                        int newY = y + dirs[i][1];

                        if (newX < 0 || newX >= m || newY < 0 || newY >= n || !isIsland[newX][newY])
                            continue;

                        // compute the id of the neighbor island
                        int neighborId = n * newX + newY;

                        // find the root of neighbor island
                        int neighborRoot = findRoot(neighborId);


                        int root = findRoot(id);

                        if (root != neighborRoot)
                        {
                            --count;
                            m_parent[root] = neighborRoot;
                        }
                    }
                }

                number_islands_list.push_back(count);
            }

            return number_islands_list;

        }

    private:
        int findRoot(int id)
        {
            int root = id;
            while (root != m_parent[root])
            {
                root = m_parent[root];
            }

            return root;
        }

        std::unordered_map<int, int> m_parent;
    };

}