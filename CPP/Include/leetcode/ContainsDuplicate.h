#pragma once
#include "stdafx.h"

//  Given an array of integers, find out whether there are two distinct indices i and j in the array 
//  such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
namespace leetcode
{
    // brute force solution O(n*k)
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (nums.empty())
            return false;

        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i + j < nums.size() && std::abs(nums[i] - nums[i + j]) <= t)
                    return true;
            }
        }
        return false;
    }
}


#if 0
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    if (nums.empty())
        return false;

    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(nums[i]) == map.end())
        {
            map.emplace(nums[i], i);
            for (int j = 1; j <= t; j++)
            {
                if (map.find(nums[i] - j) == map.end())
                {
                    map.emplace(nums[i] - j, i);
                }
                else
                    map[nums[i] - j] = i;
            }
        }
        else
        {
            if (i - map[nums[i]] <= k)
                return true;
            else
            {
                map[nums[i]] = i;
                for (int j = 1; j <= t; j++)
                {
                    if (map.find(nums[i] - j) == map.end())
                    {
                        map.emplace(nums[i] - j, i);
                    }
                    else
                        map[nums[i] - j] = i;
                }
            }
        }
    }
    return false;
}
#endif
