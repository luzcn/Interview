#pragma once
#include "stdafx.h"

namespace lintcode
{
    bool isValid(vector<int>& rows, int currentRow, int pos)
    {
        for (int i = 0; i < currentRow; i++)
        {
            auto d = pos - rows[i];

            if (d == 0) // same column
                return false;
            if (abs(d) == currentRow - i) // diagonal
                return false;
        }
        return true;
    }

    void solveRec(int n, vector<vector<string>>& res, vector<int>& rows, int row)
    {
        if (row == n)
        {
            vector<string> oneSolution;
            for (int i = 0; i < n; i++)
            {
                string str = "";
                for (int j = 0; j < n; j++)
                {
                    if (j == rows[i])
                        str += "Q";
                    else
                        str += ".";
                }
                oneSolution.push_back(str);
            }
            res.push_back(oneSolution);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isValid(rows, row, i))
            {
                rows[row] = i;
                solveRec(n, res, rows, row + 1);
            }
        }
    }


    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> rows(n, 0);
        vector<vector<string>> res;

        solveRec(n, res, rows, 0);
        return res;
    }
}