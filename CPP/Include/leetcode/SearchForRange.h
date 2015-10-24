#pragma once
#include "stdafx.h"

//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].

namespace leetcode
{
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> res{ -1,-1 };

        int l = 0;
        int r = nums.size() - 1;
        int pos = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
            {
                pos = m;
                break;
            }
            else if (target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }

        if (pos == -1)
            return res;

        // if we found one, we can search on both left and right side to get the range.
        auto first = pos;
        auto second = pos;
        while (first >= 0 && nums[first] == target)
        {
            res[0] = first;
            first--;
        }

        while (second < nums.size() && nums[first] == target)
        {
            res[1] = second;
            second++;
        }

        return res;
    }
}