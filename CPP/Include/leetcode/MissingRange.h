#pragma once
#include "stdafx.h"

// Given a sorted integer array where the range of elements are[lower, upper] inclusive, return its missing ranges.
// For example, given[0, 1, 3, 50, 75], lower = 0 and upper = 99, return["2", "4->49", "51->74", "76->99"].

namespace leetcode
{
    string getRange(int i, int j)
    {
        if (i == j)
        {
            return to_string(i);
        }
        else
        {
            return to_string(i) + "->" + to_string(j);
        }
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> result;
        if (nums.empty() || upper < nums[0] || nums.back() < lower)
        {
            result.push_back(getRange(lower, upper));
            return result;
        }

        int start = 0;
        int end = 1;
        int n = nums.size();

        while (start < n && nums[start] < lower)
        {
            start++;
        }

        if (nums[start] > lower)
        {
            result.push_back(getRange(lower, nums[start] - 1));
        }

        end = start + 1;
        while (end < nums.size() && nums[end] <= upper)
        {
            if (nums[end] != nums[end - 1] + 1)
            {
                // not continuous
                result.push_back(getRange(nums[end - 1] + 1, nums[end] - 1));
            }
            end++;
        }

        if (end == nums.size() && nums.back() < upper)
        {
            result.push_back(getRange(nums.back() + 1, upper));
        }

        return result;
    }
}