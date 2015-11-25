#pragma once
#include "stdafx.h"

//Given an array of n positive integers and a positive integer s, 
//find the minimal length of a subarray of which the sum >= s.If there isn't one, return 0 instead.
//
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
// - Two pointer solution
namespace leetcode
{
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int minLength = INT_MAX;

        int begin = 0, end = 0;
        int sum = 0;

        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= s)
            {
                minLength = min(minLength, end - begin + 1);

                sum -= nums[begin];
                begin++;
            }

            end++;
        }

        return minLength;
    }
}