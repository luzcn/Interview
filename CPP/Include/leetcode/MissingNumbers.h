#pragma once
#include "stdafx.h"

//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?

namespace leetcode
{
    int missingNumber(vector<int> nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = nums[i];
            while (t >= 0 && t < n && nums[t] != t)
            {
                int temp = nums[t];
                nums[t] = t;
                t = temp;
            }
        }

        int i = 0;
        for (; i < n; i++)
        {
            if (nums[i] != i)
                break;
        }

        return i;
    }
}