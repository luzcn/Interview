#include "stdafx.h"

// Given a sorted array, find out the range summary
// for example [1,2,3,7,8,10] outputs ["1->3", "7->8", "10"]

namespace leetcode
{
    string getSummary(vector<int>& nums, int i, int j)
    {
        if (i == j)
        {
            return to_string(nums[i]);
        }

        return to_string(nums[i]) + "->" + to_string(nums[j]);
    }

    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if (nums.empty())
        {
            return result;
        }

        int begin = 0;
        int end = 1;

        while (end < nums.size())
        {
            if (nums[end - 1] != nums[end] - 1)
            {
                result.push_back(getSummary(nums, begin, end - 1));
            }

            begin = end;
            end++;
        }

        // add the last begin->end summary
        result.push_back(getSummary(nums, begin, end - 1));

        return result;
    }
}