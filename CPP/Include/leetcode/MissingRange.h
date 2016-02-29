#pragma once
#include "stdafx.h"

// Given a sorted integer array where the range of elements are[lower, upper] inclusive, return its missing ranges.
// For example, given[0, 1, 3, 50, 75], lower = 0 and upper = 99, return["2", "4->49", "51->74", "76->99"].

namespace leetcode
{
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> result;
        if (nums.empty())
        {
            if (lower == upper)
            {
                result.push_back(to_string(lower));
            }
            else
            {
                result.push_back(to_string(lower) + "->" + to_string(upper));
            }

            return result;
        }

        int start = 0;
        int end = 1;


        while (nums[start] < lower)
        {
            start++;
        }

        if (nums[start] > lower)
        {
            if (nums[start] == lower + 1)
                result.push_back(to_string(lower));
            else
                result.push_back(to_string(lower) + "->" + to_string(nums[start] - 1));
        }
        end = start + 1;

        while (end < nums.size() && nums[end] <= upper)
        {
            if (nums[end] != nums[end - 1] + 1)
            {
                if (nums[end] == nums[end - 1] + 2)
                {
                    result.push_back(to_string(nums[end] - 1));
                }
                else
                {
                    result.push_back(to_string(nums[end - 1] + 1) + "->" + to_string(nums[end] - 1));
                }
            }
            end++;
        }

        if (end == nums.size() && nums[end - 1] < upper)
        {
            if (nums[end - 1] + 1 == upper)
            {
                result.push_back(to_string(upper));
            }
            else
            {
                result.push_back(to_string(nums[end - 1] + 1) + "->" + to_string(upper));
            }
        }

        return result;
    }
}