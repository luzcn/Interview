#pragma once
#include "stdafx.h"

namespace ValidSudoku
{
    // Given a sodoku, check if it is a valid one (no duplicates in row, in column and in 3X3 box).
    bool isValid(vector<string>& board)
    {

    }
}
namespace SudokuSolver
{
    bool valid(vector<string>& board, int x, int y, int val)
    {
        int m = board.size();
        int n = board[0].size();
        // column
        for (int i = 0; i < m; i++) 
        {
            if (board[i][y] != '.' && board[i][y] == val + '0')
                return false;
        }

        // row
        for (int j = 0; j < n; j++)
        {
            if (board[x][j] != '.' && board[x][j] == val + '0')
                return false;
        }

        //box
        int square_x = x / 3;
        int square_y = y / 3;
        for (int i = square_x * 3; i <= square_x * 3 + 2; i++)
        {
            for (int j = square_y * 3; j <= square_y * 3 + 2; j++)
            {
                cout << board[i][j] << endl;
                if (board[i][j] == val + '0')
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<string>& board) 
    {

    }
}
