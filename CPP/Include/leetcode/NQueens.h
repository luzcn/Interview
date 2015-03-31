#pragma once

#include "stdafx.h"

/***
 *	The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]

 */
namespace NQueens
{
    using namespace std;

    bool check(vector<int>& column_for_row, int row)
    {
        for (int i = 0; i < row; ++i)   // row
        {
            auto diff = abs(column_for_row[row] - column_for_row[i]);  // column
            if (diff == 0 || diff == row - i)
            {
                return false;
            }
        }

        return true;
    }

    // NQuees solving helper function
    void solveNQueensRec(vector<vector<string>>& sol, int n, vector<int>& column_for_row, int row)
    {
        if (row == n)
        {
            vector<string> current_sol(n, "");

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (j != column_for_row[i])
                    {
                        current_sol[i].append(".");
                    }
                    else
                    {
                        current_sol[i].append("Q");
                    }
                }
            }
            sol.push_back(current_sol);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            column_for_row[row] = i;
            if (check(column_for_row, row))
            {
                solveNQueensRec(sol, n, column_for_row, row + 1);
            }
        }
    }


    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> sol;
        vector<int> column_for_row;
    }
}

