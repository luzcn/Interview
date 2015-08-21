#pragma once
#include "stdafx.h"

//Given an integer array, find a subarray with sum closest to zero.
//Return the indexes of the first number and last number.
//
//Example: Given[-3, 1, 1, -3, 5], return[0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]
//Challenge: O(nlogn) time
namespace lintcode
{
    
    vector<int> subarraySumClosest(vector<int> nums)
    {
        
    }

    // brute force is trivial
    vector<int> subarraySumClosest_bruteforce(vector<int> nums)
    {
        vector<int> res(2);
        int closest = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i];
            if (abs(sum) < closest)
            {
                closest = abs(sum);
                res[0] = i;
                res[1] = i;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                if (abs(sum) < closest)
                {
                    closest = abs(sum);
                    res[0] = i;
                    res[1] = j;
                }
            }
        }

        return res;
    }
}