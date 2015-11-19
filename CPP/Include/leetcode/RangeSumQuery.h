#pragma once
#include "stdafx.h"

namespace leetcode
{
    // Your NumArray object will be instantiated and called as such:
    // NumArray numArray(nums);
    // numArray.sumRange(0, 1);
    // numArray.sumRange(1, 2);
    class NumArray {
    public:
        NumArray(vector<int> &nums)
        {
            totalSums.resize(nums.size() + 1);
            totalSums[0] = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                totalSums[i + 1] = totalSums[i] + nums[i];
            }
        }

        int sumRange(int i, int j)
        {
            return totalSums[j + 1] - totalSums[i];
        }
    private:
        vector<int> totalSums;
    };


    // Range Sum Query 2D - Immutable
    // Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined 
    // by its upper left corner(row1, col1) and lower right corner(row2, col2).
    //
    //Given matrix = [
    //        [3, 0, 1, 4, 2],
    //        [5, 6, 3, 2, 1],
    //        [1, 2, 0, 1, 5],
    //        [4, 1, 0, 1, 7],
    //        [1, 0, 3, 0, 5]
    //]
    //    sumRegion(2, 1, 4, 3) -> 8
    //    sumRegion(1, 1, 2, 2) -> 11
    //    sumRegion(1, 2, 2, 4) -> 12
    class NumMatrix
    {
    public:
        NumMatrix(vector<vector<int>> &matrix)
        {
            if (!matrix.empty)
            {
                int m = matrix.size();
                int n = matrix[0].size();

                totalSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));


                // compute the total sum of each row
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        totalSum[i][j] = matrix[i - 1][j - 1] + totalSum[i][j - 1];
                    }
                }

                // add up all the row sum for each column, 
                // the result is the range sum of each rectangle
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        totalSum[i][j] += totalSum[i - 1][j];
                    }
                }
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            if (totalSum.empty())
                return 0;

            return totalSum[row2 + 1][col2 + 1]
                - totalSum[row1][col2 + 1] // the up rectangle range sum
                - totalSum[row2 + 1][col1] // the left rectangle range sum
                + totalSum[row1][col1];    // the up left conner range sum, it removed twice
        }
    private:
        vector<vector<int>> totalSum;
    };

}