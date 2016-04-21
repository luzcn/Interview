#pragma once
#include "stdafx.h"
#include <map>

//  Given an array of integers, find out whether there are two distinct indices i and j in the array 
//  such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
namespace leetcode
{
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        if (nums.empty() || k <= 0)
        {
            return false;
        }

        map<int, int> map; // nums value, index
        int j = 0;      // the index denote which value needs to remove from map

        for (int i = 0; i < nums.size(); ++i)
        {
            if (i - j > k )
            {
                map.erase(nums[j++]);
            }

            std::map<int, int>::iterator it = map.lower_bound(nums[i] - t);

            if (it != map.end() && abs(it->first - nums[i]) <= t)
            {
                // double check if the candidate 'it' satisfy the condition
                return true;
            }

            map[nums[i]] = i;
        }

        return false;
    }
}
