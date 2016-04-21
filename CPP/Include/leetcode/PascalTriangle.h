#pragma once
#include "stdafx.h"

//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]

namespace leetcode
{
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle;

        for (int level = 0; level < numRows; level++)
        {
            triangle.push_back(vector<int>(level + 1, 1));

            for (int i = 1; i < level; i++)
            {
                triangle[level][i] = triangle[level - 1][i - 1] + triangle[level - 1][i];
            }
        }

        return triangle;
    }


    //Given an index k, return the kth row of the Pascal's triangle.
    //    For example, given k = 3,
    //    Return[1, 3, 3, 1].
    //    Note:
    //Could you optimize your algorithm to use only O(k) extra space ?
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex < 0)
        {
            return{};
        }

        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;

        for (int level = 1; level <= rowIndex; level++)
        {
            for (int i = level; i >= 1; i--)
            {
                result[i] = result[i] + result[i - 1];
            }
        }

        return result;
    }
}