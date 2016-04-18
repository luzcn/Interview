#pragma once
#include "stdafx.h"

// Palantir phone interview
// https://en.wikipedia.org/wiki/Connect_Four

// Implement the function that takes a board string
// and decodes it into the representative 2D array.
//
//    |_|_|_|_|_|_|_|
//    |_|_|r|_|_|_|_|
//    |b|r|b|r|b|r|_|
//    |b|b|b|r|r|b|_|
//    |b|r|r|b|b|r|_|
//    |r|b|b|r|r|r|b|
//    CFN: 9_r4_brbrbr_3b2rb_b2r2br_r2b3rb
//
// This function should return a char[6][7] filled with:
//   * 'r' to indicate a red piece
//   * 'b' to indicate a black piece
//   * '_' to indicate an empty space
//
// The input string is not necessarily a valid
// CFN board string.  It is guaranteed not-empty.

namespace careercup
{
    // parsing the string to get numbers
    int getNumber(string& s, int& i)
    {
        int result = 0;

        while (i < s.size() && isdigit(s[i]))
        {
            // assume there is no overflow
            result = result * 10 + (s[i] - '0');
            i++;
        }

        return result;
    }

    // add the character s[index] into board[i][j], the character could repeated whith "number" times
    void addToBoard(string& s, vector<vector<char>>& board, int& i, int& j, int number, int index)
    {
        for (int count = 0; count < number; count++)
        {
            if (j >= 7)
            {
                j = 0;
                i++;
            }

            if (i >= 6)
            {
                // not valid inputstring
                return;
            }

            board[i][j] = s[index];
            j++;
        }
    }

    vector<vector<char>> decodeBoard(string cfn)
    {
        int m = 6;
        int n = 7;
        vector<vector<char>> board;

        int index = 0;  // index of the cfn
        int i, j = 0;   // the index of 2d output matrix

        while (index < cfn.size())
        {
            if (isdigit(cfn[index]))
            {
                // get the number
                int number = getNumber(cfn, index);

                addToBoard(cfn, board, i, j, number, index);

            }
            else if (cfn[index] == 'r' || cfn[index] == 'b')
            {
                addToBoard(cfn, board, i, j, 1, index);
            }
            else
            {
                // invalid character
                return board;
            }

            index++;
        }

        return board;
    }

    // A Connect4 board must obey the laws of gravity.
    // Thus, it is not possible for a piece to be
    // resting on top of an empty space.
    //
    // Not a valid board:
    //
    //    |_|r|_|_|_|_|_|
    //    |_|r|_|_|_|_|_|
    //    |_|r|_|_|_|_|_|
    //    |_|r|_|_|_|_|_|
    //    |_|r|_|_|_|_|_|
    //    |r|_|_|_|_|_|_|
    //    CFN: b41_
    //
    //
    // Implement the function that takes a board string
    // and validates that no pieces are
    // inappropriately placed above an empty square.
    // You may use the `decodeBoard` function you already defined.
    //
    // This function should return:
    //    * TRUE only if the input board does not
    //      have any pieces directly above an empty space.

    // ___rrr
    bool checkColumn(vector<vector<char>>& board, int col)
    {
        int row = 0;
        while (row < 6)
        {
            if (board[row][col] != '_')
            {
                while (row < 6)
                {
                    if (board[row][col] == '_')
                    {
                        return false;
                    }

                    row++;
                }
            }

            row++;
        }

        if (row >= 6)
        {
            return true;
        }
    }
    bool obeysGravity(string boardString)
    {
        auto board = decodeBoard(boardString);

        for (int col = 0; col < 7; col++)
        {
            if (!checkColumn(board, col))
            {
                return false;
            }
        }

        return true;
    }
}