#pragma once
#include "stdafx.h"

//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].

namespace leetcode
{
    void swapRange(vector<int>& nums, int i, int j)
    {
        while (i < j)
        {
            auto temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;

        // swap the first n- k characters
        swapRange(nums, 0, n - k - 1);

        // swap the right k characters
        swapRange(nums, n - k, n - 1);

        // swap the entire array
        swapRange(nums, 0, n - 1);
    }

}