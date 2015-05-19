#pragma once
#include "stdafx.h"

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
                cout << board[i][j] << " ";
                if (board[i][j] == val + '0')
                    return false;
            }
            cout << endl;
        }

        return true;
    }

    bool solveRec(vector<string>& board, int i, int j)
    {
        // finished one row, continue checking the next row
        if (j >= 9)
            return solveRec(board, i + 1, 0);

        // all rows and columns are finished.
        if (i == 9)
            return true;

        if (board[i][j] == '.')
        {
            for (int val = 1; val <= 9; val++)
            {
                if (valid(board, i, j, val))
                {
                    board[i][j] = val + '0';
                    if (solveRec(board, i, j + 1))
                        return true;
                }
                board[i][j] = '.';
            }
        }
        else
        {
            return solveRec(board, i, j + 1);
        }
        return false;
    }

    void solveSudoku(vector<string>& board) 
    {
        solveRec(board, 0, 0);
    }
}
