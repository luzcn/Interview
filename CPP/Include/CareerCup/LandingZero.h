#pragma once
#include "stdafx.h"
//You’re given a board game which is a row of squares, each labeled with an integer.
//This can be represented by a list, e.g.[1, 3, 2, 0, 5, 2, 8, 4, 1].
//
//Given a start position on the board, you “win” by landing on a zero, 
//where you move by jumping from square to square either left or right 
//the number of spaces specified on the square you’re currently on.
//
//Your task is to implement the function : 
//def can_win(board, pos) : returns True if you can win the board from that starting pos, False otherwise

namespace careercup
{
    bool can_winRec(vector<int>& board, int pos, vector<bool>& visited)
    {
        if (pos < 0 && pos >= board.size())
            return false;

        if (board[pos] == 0)
            return true;

        if (!visited[pos])
        {
            visited[pos] = true;
            if (can_winRec(board, pos - board[pos], visited)
                || can_winRec(board, pos - board[pos], visited))
            {
                return true;
            }
        }

        return false;
    }

    bool can_win(vector<int>& board, int pos)
    {
        if (board.size() < pos)
            return false;

        if (board[pos] == 0)
            return true;

        vector<bool> visited(board.size(), false);

        return can_winRec(board, pos, visited);
    }
}