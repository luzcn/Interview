#pragma once

#include "stdafx.h"

/***
 *	 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 *
 *	 Did you use extra space?
 *	 A straight forward solution using O(mn) space is probably a bad idea.
 *	 A simple improvement uses O(m + n) space, but still not the best solution.
 *	 Could you devise a constant space solution?
 *
 */
namespace SetMatrixZeroes
{
    using namespace std;

    // The O(m+n) space solution
    void SetMatrixZero(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return;

        size_t row_len = matrix.size();
        size_t column_len = matrix[0].size();

        // create 2 arrays to record which row/column need to set zeros.
        vector<int> row(row_len, -1);
        vector<int> column(column_len, -1);

        for (size_t i = 0; i < row_len; ++i)
        {
            for (size_t j = 0; j < column_len; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    column[j] = 0;
                }
            }
        }


        // set row to zeros.
        for (size_t i = 0; i < row_len; ++i)
        {
            if (row[i] == 0)
            {
                for (size_t j = 0; j < column_len; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // set column to zeros.
        for (size_t j = 0; j < column_len; ++j)
        {
            if (column[j] == 0)
            {
                for (size_t i = 0; i < row_len; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // The O(1) space solution
    // 
    // The idea is reuse the first row and first column of the input matrix 
    // to record the row/column with zeros.
    void SetMatrixZero2(vector<vector<int>>& M)
    {
        if (M.empty())
            return;

        size_t row_len = M.size();
        size_t col_len = M[0].size();

        bool setFirtRowZero = false;
        bool setFirtColZero = false;


        // Detect if the first column needs to set 0.
        for (size_t i = 0; i < row_len; ++i)
        {
            if (M[i][0] == 0)
            {
                setFirtColZero = true;
                break;
            }
        }

        // Detect if the first row needs to set 0.
        for (size_t j = 0; j < col_len; ++j)
        {
            if (M[0][j] == 0)
            {
                setFirtRowZero = true;
                break;
            }
        }

        // Go through all the elements in the matrix,
        // if find 0, set the corresponding row/col as 0.
        for (size_t i = 1; i < row_len; ++i)
        {
            for (size_t j = 1; j < col_len; ++j)
            {
                if (M[i][j] == 0)
                {
                    M[i][0] = 0;
                    M[0][j] = 0;
                }
            }
        }

        // Go through the matrix again,
        // For each m[i][j], if m[0][j] or m[i][0] is 0, set the m[i][j] as 0.
        for (size_t i = 1; i < row_len; ++i)
        {
            for (size_t j = 1; j < col_len; ++j)
            {
                if (M[i][0] == 0 || M[0][j] == 0)
                {
                    M[i][j] = 0;
                }
            }
        }

        // If need to set first row to 0.
        if (setFirtRowZero)
        {
            for (size_t j = 0; j < col_len; ++j)
            {
                M[0][j] = 0;
            }
        }

        // If need to set first column to 0.
        if (setFirtColZero)
        {
            for (size_t i = 0; i < row_len; ++i)
            {
                M[i][0] = 0;
            }
        }

    }
}

#if 0

void print(const std::vector<std::vector<int>>& m)
{
    for (auto v : m)
    {
        for (auto e : v)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<std::vector<int>> matrix = { { 1, 1, 0, 1 }, { 1, 0, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
    print(matrix);

    std::cout << "----" << std::endl;

    SetMatrixZeroes::SetMatrixZero2(matrix);

    print(matrix);


    return 0;
}


#endif