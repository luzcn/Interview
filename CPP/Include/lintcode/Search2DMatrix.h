#pragma once
#include "stdafx.h"

namespace lintcode
{
    //Write an efficient algorithm that searches for a value in an m x n matrix.
    //    This matrix has the following properties :
    //  1. Integers in each row are sorted from left to right.
    //  2. The first integer of each row is greater than the last integer of the previous row.
    //    Example
    //    Consider the following matrix :
    //[
    //    [1, 3, 5, 7],
    //    [10, 11, 16, 20],
    //    [23, 30, 34, 50]
    //]
    //Given target = 3, return true.
    //    Challenge
    //    O(log(n) + log(m)) time
    // binary search the column first, then binary search row
    bool searchMatrix_Twice(vector<vector<int> > &matrix, int target)
    {
        // write your code here
        if (matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;
        while (top <= bottom)
        {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                top = mid + 1;
            else
            {
                bottom = mid - 1;
                if (bottom < 0)
                    return false;
            }
        }
        int row = bottom;
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }

    //Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
    //    This matrix has the following properties :
    //*Integers in each row are sorted from left to right.
    //    * Integers in each column are sorted from up to bottom.
    //    * No duplicate integers in each row or column.
    //    Example
    //    Consider the following matrix :
    //[
    //    [1, 3, 5, 7],
    //    [2, 4, 7, 8],
    //    [3, 5, 9, 10]
    //]
    //Given target = 3, return 2.
    //    Challenge
    //    O(m + n) time and O(1) extra space
    int searchMatrix2(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty())
            return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        int x = m - 1, y = 0;
        int res = 0;
        while (x >= 0 && y < n)
        {
            if (matrix[x][y] == target)
            {
                res++;
                x--;
            }
            else if (matrix[x][y] < target)
            {
                y++;
            }
            else
            {
                x--;
            }
        }

        return res;
    }

}
