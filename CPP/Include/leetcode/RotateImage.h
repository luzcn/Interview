#pragma once
#include "stdafx.h"

// rotate the matrix in 90 degree clock wised.
 //[                  [
 // [1, 2, 3]          [7, 4, 1]
 // [4, 5, 6]     =>   [8, 5, 2]
 // [7, 8, 9]          [9, 6, 3]
 //]                  ]
namespace leetcode
{
    void rotate(vector<vector<int>>& board)
    {
        int n = board.size();
        int row = 0;
        int col = 0;

        for (int i = row; i < n - row - 1; i++)
        {
            for (int j = col; j < n - col - 1; j++)
            {
                int temp1 = board[i][j];
                board[i][j] = board[n - j - 1][i];

                int temp2 = board[j][n - i - 1];
                board[j][n - i - 1] = temp1;

                int temp3 = board[n - i - 1][n - j - 1];
                board[n - i - 1][n - j - 1] = temp2;

                board[n - j - 1][i] = temp3;
            }
            col++;
        }
    }
}