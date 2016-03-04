#pragma once
#include "stdafx.h"

// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions : left, right, up or down.
// You may NOT move diagonally or move outside of the boundary(i.e.wrap - around is not allowed).
//
// Example 1 :
//
//    nums = [
//            [9, 9, 4],
//            [6, 6, 8],
//            [2, 1, 1]
//           ]
//
//  Return 4
//        The longest increasing path is[1, 2, 6, 9].
//
//        Example 2:
//
//    nums = [
//            [3, 4, 5],
//            [3, 2, 6],
//            [2, 2, 1]
//           ]
//
//   Return 4
//        The longest increasing path is[3, 4, 5, 6].Moving diagonally is not allowed.
namespace leetcode
{
    /*void dfs(vector<vector<int>>& matrix, int i, int j, int& longest, int current)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return;

        longest = max(longest, current);

        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
        {
            dfs(matrix, i - 1, j, longest, current + 1);
        }

        if (i + 1 < matrix.size() && matrix[i + 1][j] > matrix[i][j])
        {
            dfs(matrix, i + 1, j, longest, current + 1);
        }

        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
        {
            dfs(matrix, i, j - 1, longest, current + 1);
        }

        if (j + 1 < matrix[0].size() && matrix[i][j + 1] > matrix[i][j])
        {
            dfs(matrix, i, j + 1, longest, current + 1);
        }
    }*/


    // dfs with memoization
    int dfs(const vector<vector<int>>& matrix, int i, int j,
        vector<vector<int>>& memo, const vector<pair<int,int>>& dirs)
    {
        if (memo[i][j])
            return memo[i][j];

        for (auto& dir : dirs)
        {
            int x = i + dir.first;
            int y = j + dir.second;

            if (x >= 0 && x < matrix.size() && j >= 0 && j < matrix[0].size()
                && matrix[x][y] > matrix[i][j])
            {
                memo[i][j] = max(memo[i][j], dfs(matrix, x, y, memo, dirs));
            }
        }

        return ++memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        int longest = 1;

        vector<vector<int>> memo(m, vector<int>(n, 0));
        vector<pair<int, int>> dirs{ {1, 0},{-1,0},{0,1},{0,-1} };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                longest = max(longest, dfs(matrix, i, j, memo, dirs));
            }
        }

        return longest;
    }
}