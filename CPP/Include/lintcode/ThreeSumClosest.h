#pragma once
#include "stdafx.h"
#include <numeric>
//  Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
//  Return the sum of the three integers.
//
//  For example, given array S = { -1, 2, 1, -4 }, and target = 1. 
//  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//  You may assume that each input would have exactly one solution.
namespace lintcode
{
    int threeSumClosest(vector<int> nums, int target) 
    {
        if (nums.size() < 3)
            throw std::exception("invalid input");

        int res = 0; //std::accumulate(nums.begin(), nums.end(), 0);
        int closest = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int t1 = target - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            int current_sum = 0;
            while (l < r)
            {
                current_sum = nums[i] + nums[l] + nums[r];
                if (nums[l] + nums[r] == t1)
                    return target;
                else if (nums[l] + nums[r] < t1)
                {
                    
                    l++;
                }
                else
                {
                    r--;
                }
                int dist = abs(current_sum - target);
                if (dist < closest)
                {
                    closest = dist;
                    res = current_sum;
                }
            }
        }
        return res;
    }
}