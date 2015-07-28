#pragma once
#include "stdafx.h"

//Given an array of n integers where n > 1, nums, 
//return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given[1, 2, 3, 4], return[24, 12, 8, 6].
//
//Follow up :
//Could you solve it with constant space complexity ? 
//(Note : The output array does not count as extra space for the purpose of space complexity analysis.)

namespace leetcode
{
    // O(1) space solution
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> res(nums.size());
        res[0] = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int right_product = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = nums[i] * right_product;
            right_product *= nums[i];
        }

        return res;
    }
}