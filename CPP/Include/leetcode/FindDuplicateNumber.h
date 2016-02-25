#pragma once
#include "stdafx.h"
#include <numeric>

// Given an array nums containing n + 1 integers where each integer is between 1 and n(inclusive), 
// prove that at least one duplicate number must exist.
// Assume that there is only one duplicate number, find the duplicate one.
//
// Note:
//
// You must not modify the array(assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n^2).
// There is only one duplicate number in the array, but it could be repeated more than once.
namespace leetcode
{
    // Binary search solution
    int findDuplicate(const vector<int>& nums)
    {
        int n = nums.size() - 1;

        // The values between l to r are soreted
        // so we can use binary search
        int l = 1;  
        int r = n;
        int mid = 0;

        while (l < r)
        {
            mid = l + (r - l) / 2;
            int count = 0;

            for (int num : nums)
            {
                if (num <= mid)
                {
                    count++;
                }
            }

            if (count > mid) // the duplicat number is less than this mid
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }

    // 
    int findDuplicate_canModify(vector<int>& nums)
    {
        int result = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] > 0)
            {
                nums[abs(nums[i]) - 1] = 0 - nums[abs(nums[i]) - 1];
            }
            else
            {
                result =  abs(nums[abs(nums[i]) - 1]);
                break;
            }
        }

        return result;
    }
}