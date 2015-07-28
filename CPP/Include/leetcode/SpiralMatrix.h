#pragma once
#include "stdafx.h"

namespace leetcode
{
    //  Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
    //    For example,
    //    Given the following matrix :
    //  [
    //    [1, 2, 3],
    //    [4, 5, 6],
    //    [7, 8, 9]
    //  ]
    //  You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].
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

            // if only single row or one colum, no need to print repeatly
            if (r1 > r2 || c1 > c2)
                break;

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

    //  Spiral Matrix II 
    //    Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
    // 
    //    For example,
    //    Given n = 3,
    //    You should return the following matrix :
    //  [
    //    [1, 2, 3],
    //    [8, 9, 4],
    //    [7, 6, 5]
    //  ]
    vector<vector<int>> generateMatrix(int n)
    {
        int value = 1;
        vector<vector<int>> M(n, vector<int>(n));

        int r1 = 0;
        int r2 = n - 1;

        int c1 = 0;
        int c2 = n - 1;

        while (r1 <= r2 && c1 <= c2)
        {
            // top row
            for (int j = c1; j <= c2; j++)
                M[r1][j] = value++;
            r1++;
            if (r1 > r2)  // if n==1
                break;

            // right column
            for (int i = r1; i <= r2; i++)
                M[i][c2] = value++;
            c2--;

            // bottom row
            for (int j = c2; j >= c1; j--)
                M[r2][j] = value++;
            r2--;

            // left column
            for (int i = r2; i >= r1; i--)
                M[i][c1] = value++;
            c1++;
        }

        return M;
    }
}