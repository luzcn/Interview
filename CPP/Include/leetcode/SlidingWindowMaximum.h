#pragma once
#include "stdafx.h"
#include <queue>
#include <stack>

//  Given an array nums, there is a sliding window of size k which is moving 
//  from the very left of the array to the very right.
//  You can only see the k numbers in the window.Each time the sliding window moves right by one position.
//
//  For example,
//  Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.

//  Window position                Max
//  -------------- - ---- -
//  [1  3 - 1] - 3  5  3  6  7       3
//  1[3 - 1 - 3] 5  3  6  7       3
//  1  3[-1 - 3  5] 3  6  7       5
//  1  3 - 1[-3  5  3] 6  7       5
//  1  3 - 1 - 3[5  3  6] 7       6
//  1  3 - 1 - 3  5[3  6  7]      7
//
//  Therefore, return the max sliding window as[3, 3, 5, 5, 6, 7].

namespace leetcode
{
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (k == 1)
            return nums;

        vector<int> res;

        std::queue<int> que;
        std::vector<int> max_list;
        int max_temp = INT_MIN;
        int current_max = INT_MIN;
        int count = 0;

        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
            current_max = max(current_max, nums[i]);
        }
        max_list.push_back(current_max);
        res.push_back(current_max);
        que.push(nums[0]);

        
        return res;
    }
}