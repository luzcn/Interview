#pragma once
#include "stdafx.h"

namespace SpiralMatrix
{
    vector<int> SpiralOrder(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        if (m == 0)
            return res;

        int r1 = 0, r2 = m - 1;
        int c1 = 0, c2 = n - 1;

        while (r1 <= r2 && c1 <= c2)
        {
            //print row
            for (int j = c1; j <= c2; j++)
            {
                res.push_back(matrix[r1][j]);
            }
            r1++;



            //print column
            for (int i = r1; i <= r2; i++)
            {
                res.push_back(matrix[i][c2]);
            }
            c2--;


            // print bottom row
            for (int j = c2; j >= c1; j--)
            {
                res.push_back(matrix[r2][j]);
            }
            r2--;


            for (int i = r2; i >= r1; i--)
            {
                res.push_back(matrix[i][c1]);
            }
            c1++;

        }

        return res;
    }
}