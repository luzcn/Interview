#pragma once
#include "stdafx.h"

//Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
//
//If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i] - B[i]|
//
//Given[1, 4, 2, 3] and target = 1, one of the solutions is[2, 3, 2, 3], the adjustment cost is 2 and it's minimal.
//
//Return 2.
// You can assume each number in the array is a positive integer and not greater than 100.

namespace lintcode
{
    int dfs(vector<int>& A, vector<int>& B, int index, int target)
    {
        if (index >= A.size())
            return 0;

        int minValue = INT_MAX;
        for (int i = 0; i <= 100; i++)
        {
            if (index == 0 || abs(i - B[index-1]) > target)
                continue;

            
        }
    }

    int MinAdjustmentCost(vector<int> A, int target)
    {

    }
}