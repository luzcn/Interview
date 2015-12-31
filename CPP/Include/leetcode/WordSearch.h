#pragma once
#include "stdafx.h"

// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, 
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// For example,
// Given board =
//
// [
//    ['A', 'B', 'C', 'E'],
//    ['S', 'F', 'C', 'S'],
//    ['A', 'D', 'E', 'E']
// ]
//
// word = "ABCCED", ->returns true,
// word = "SEE", ->returns true,
// word = "ABCB", ->returns false.

namespace leetcode
{
    bool dfs(vector<vector<char>>& board, string& word,
        vector<vector<bool>>& visited, int i, int j, int index)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if (index >= word.size())
            return true;

        if (!visited[i][j] && board[i][j] == word[index])
        {
            visited[i][j] = true;
            if (dfs(board, word, visited, i - 1, j, index + 1)
                || dfs(board, word, visited, i + 1, j, index + 1)
                || dfs(board, word, visited, i, j - 1, index + 1)
                || dfs(board, word, visited, i, j + 1, index + 1))
            {
                return true;
            }

            visited[i][j] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        if (board.empty())
            return false;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (word.size() == 1)
                        return true;

                    if (dfs(board, word, visited, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
}