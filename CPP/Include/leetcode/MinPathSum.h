#pragma  once
#include "stdafx.h"

/*
 *Given a m x n grid filled with non-negative numbers,
 *find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.
 */
namespace MinPathSum
{
    using namespace std;

    /*
     *	the brute force recursive solution.
     */
    int minPathSumRec(vector<vector<int>>& grid, int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        if (i == 0)
        {
            return grid[i][j] + minPathSumRec(grid, 0, j - 1);
        }

        if (j == 0)
        {
            return grid[i][j] + minPathSumRec(grid, i - 1, 0);
        }

        return grid[i][j] + std::min(minPathSumRec(grid, i - 1, j), minPathSumRec(grid, i, j - 1));
    }

    /*
     *	DP solution, O(m*n) space.
     */
    int minPathSum_DP(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cache;
        cache.resize(m, vector<int>(n));

        cache[0][0] = grid[0][0];

        // for rows.
        for (int i = 1; i < m; ++i)
        {
            cache[i][0] = cache[i - 1][0] + grid[i][0];
        }

        // for columns.
        for (int j = 1; j < n; ++j)
        {
            cache[0][j] = cache[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                cache[i][j] = grid[i][j] + std::min(cache[i - 1][j], cache[i][j - 1]);
            }
        }
        return cache[m - 1][n - 1];
    }

    /*
     *	DP, O(m+n) solution
     */
    int minPathSum_DP2(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows(m,0);
        vector<int> columns(n,0);
        rows[0] = grid[0][0];
        columns[0] = grid[0][0];

        for (int i = 1; i < m; ++i)
        {
            rows[i] = rows[i - 1] + grid[i][0];
        }

        for (int j = 1; j < n; ++j)
        {
            columns[j] = columns[j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                auto value = grid[i][j] + min(rows[i], columns[j]);
                rows[i] = value;
            }
        }

        return rows[m - 1];
    }

    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        //return minPathSumRec(grid, m - 1, n - 1);
        
    }
}
