#pragma once
#include "stdafx.h"

//Given an integer array, find a subarray where the sum of numbers is zero.
//Your code should return the index of the first number and the index of the last number.
//
//Given[-3, 1, 2, -3, 4], return[0, 2] or [1, 3]
//There is at least one subarray that it's sum equals to zero.
// 
// The brute force solution is trivial, try in O(n) time
// Thought: let's use f(i) to indicate the sum of 0 to i, 
//  if we got f(i) == f(j), it means the sum of i+1 to j is 0, so we find one sum 0 subarray.
namespace lintcode
{
    vector<int> subarraySum(vector<int> nums)
    {
        vector<int> res;
        if (nums.empty())
            return res;

        std::unordered_map<int, int> map; // sum, index;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == 0)
            {
                res.push_back(0);
                res.push_back(i);
                break;
            }
            else if (map.find(sum) == map.end())
            {
                map.emplace(sum, i);
            }
            else
            {
                res.push_back(map[sum] + 1);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
}
