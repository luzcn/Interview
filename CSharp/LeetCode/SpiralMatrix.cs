using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /***
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

    For example,
    Given the following matrix:

    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]

    You should return [1,2,3,6,9,8,7,4,5]. 
    ***/
    class SpiralMatrix
    {
        public IList<int> SpiralOrder(int[,] matrix)
        {
            IList<int> result = new List<int>();
            int m = matrix.GetLength(0);
            int n = matrix.GetLength(1);

            int col1 = 0;
            int col2 = n - 1;

            int row1 = 0;
            int row2 = m - 1;

            while (col1 <= col2 && row1 <= row2)
            {
                // print the top row from left to right.
                for (int j = col1; j <= col2; j++)
                {
                    result.Add(matrix[row1, j]);
                }
                row1++;

                // print the right column from top to bottom.
                for (int i = row1; i <= row2; i++)
                {
                    result.Add(matrix[i, col2]);
                }
                col2--;

                // if there is only one row or one column left.
                // do not need to output in reverse order
                if (row1 > row2 || col1 > col2)
                    break;

                // print the bottom row from right to left
                for (int j = col2; j >= col1; j--)
                {
                    result.Add(matrix[row2, j]);
                }
                row2--;

                // print the left colum from bottom to top
                for (int i = row2; i >= row1; i--)
                {
                    result.Add(matrix[i, col1]);
                }
                col1++;
            }

            return result;
        }
    }
}
