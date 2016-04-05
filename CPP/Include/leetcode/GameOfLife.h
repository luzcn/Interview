#pragma once
#include "stdafx.h"

// According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//  Given a board with m by n cells, each cell has an initial state live(1) or dead(0).
//  Each cell interacts with its eight neighbors(horizontal, vertical, diagonal) 
//  using the following four rules(taken from the above Wikipedia article) :
//
//    Any live cell with fewer than two live neighbors dies, as if caused by under - population.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by over - population..
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
//    Write a function to compute the next state(after one update) of the board given its current state.
// 
//To avoid decisions and branches in the counting loop, 
//the rules can be rearranged from an egocentric approach of the inner field regarding its neighbors to a scientific observer's viewpoint: 
//1. if the sum of all nine fields is 3, the inner field state for the next generation will be life (no matter of its previous contents); 
//2. if the all-field sum is 4, the inner field retains its current state 
//3. every other sum sets the inner field to death.
namespace leetcode
{
    // How to resolve the problem in O(1) space?
    // The input is matrix of int, which has 32 bits, but the possible value of each cell is "0" or "1", which only requires 1 bit.
    // so we can use the second bit to store the next state and keep the current state.
    // example: for board[i][j] the binary representation is
    // 0 -> 00: the current state is dead and next state keeps dead
    // 1 -> 11 : live -> live
    // 0 -> 10 : dead -> live
    // 1 -> 01 : live -> dead

    int computeNineCells(const vector<vector<int>>& board, const int& i, const int& j, const int& m, const int& n)
    {
        int count = 0;
        for (int k = max(i - 1, 0); k <= min(i + 1, m - 1); k++)
        {
            for (int l = max(j - 1, 0); l <= min(j + 1, n - 1); l++)
            {
                count += board[k][l] & 1;   // &1 is to get the current state which is the first bit
            }
        }

        return count;
    }
    void gameOfLife(vector<vector<int>>& board)
    {
        if (board.empty())
            return;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = computeNineCells(board, i, j, m, n);
                if (count == 3 /*|| count - board[i][j] == 3*/) // the next state is live
                {
                    // the binary representation 2 is "10", so the this operation set the second bit to "1"
                    board[i][j] |= 2;
                }
                else if (count == 4)    // keeps unchanged.
                {
                    if (board[i][j] & 1)
                        board[i][j] |= 2;
                }
                // all others will be dead
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] >>= 1;
            }
        }

    }



    // use bit manipulate
    class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board)
        {
            if (board.empty() || board[0].empty())
                return;

            int m = board.size();
            int n = board[0].size();
            // vector<vector<int>> matrix(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int lives = 0;
                    for (auto& dir : dirs)
                    {
                        int x = i + dir.first;
                        int y = j + dir.second;

                        if (x < 0 || x >= m || y < 0 || y >= n)
                            continue;

                        lives += board[x][y] & 1;
                        //if (board[x][y] & 1)
                        //    lives++;
                    }

                    if (lives < 2 || lives > 3)
                    {
                        // the next generation is 0
                         board[i][j] |= 0;
                    }
                    else if (lives == 3 || (board[i][j] & 1))
                    {
                        // lives == 3, re-generation
                        // otherwise, keep the state unchanged
                        board[i][j] |= 2;
                    }
                }
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    board[i][j] = board[i][j] >> 1;
                }
            }
            cout << board[0][0];
        }
    private:
        vector<pair<int, int>> dirs{ { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 },{ -1, -1 },{ -1,1 },{ 1,-1 },{ 1,1 } };
    };

    
}