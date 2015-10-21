#pragma once
#include "stdafx.h"

//Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//Example
//
//For example, given the array[2, 3, -2, 4], the contiguous subarray[2, 3] has the largest product = 6.
// [2,-3,-2,-4] return 12
// [-1, 99] return 99
// [-3,-4] return 12
//
namespace lintcode
{
    int maxProduct(vector<int>& A)
    {
        // write your code here
        if (A.empty())
            return 0;

        int product = 1;
        int maxProduct = INT_MIN;
        

        return maxProduct;
    }
}