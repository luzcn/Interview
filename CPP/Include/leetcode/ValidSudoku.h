#pragma once
#include "stdafx.h"

namespace ValidSudoku
{
    bool isValidSudoku(vector<string>& board)
    {
        // check rows
        for (int i = 0; i < 9; i++)
        {
            vector<bool> visited(9, false);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int c = board[i][j] - '1';
                    if (visited[c])
                    {
                        return false;
                    }
                    visited[c] = true;
                }
            }
        }
        // check columns
        for (int j = 0; j < 9; j++)
        {
            vector<bool> visited(9, false);
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] != '.')
                {
                    int c = board[i][j] - '1';
                    if (visited[c])
                    {
                        return false;
                    }
                    visited[c] = true;
                }
            }
        }

        // check boxes
        bool blocks[3][3][9] = { false };
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    auto c = board[i][j] - '1';
                    if (blocks[i / 3][j / 3][c])
                    {
                        return false;
                    }
                    blocks[i / 3][j / 3][c] = true;
                }
            }
        }
        return true;
    }
}

#if 0
int row_offset = 0;
int col_offset = 0;
while (row_offset < 9)
{
    while (col_offset < 9)
    {
        for (int i = row_offset; i < 3; i++)
        {
            int visited[9];
            for (int j = col_offset; j < 3; j++)
            {
                if (board[i][j] != '.')
                {
                    auto c = board[i][j] - '1';
                    if (visited[c] == 1)
                    {
                        return false;
                    }
                    visited[c] = 1;
                }
            }
        }
        col_offset += 3;
    }
    col_offset = 0;
    row_offset += 3;
}
#endif // 0