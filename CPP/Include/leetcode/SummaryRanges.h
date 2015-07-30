#include "stdafx.h"

namespace leetcode
{
    // Given a sorted array, find out the range summary
    // for example [1,2,3,7,8,10] outputs ["1->3", "7->8", "10"]
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string>  res;
        if (nums.empty())
            return res;
        if (nums.size() == 1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }

        int start = 0;
        int end = start + 1;

        while (end < nums.size())
        {
            if (nums[end] - nums[end - 1] == 1)
            {
                end++;
            }
            else
            {
                if (start != end - 1)
                {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
                }
                else
                {
                    res.push_back(to_string(nums[start]));
                }
                start = end;
                end = start + 1;
            }
        }
        if (start != end - 1)
        {
            res.push_back(to_string(nums[start]) + "->" + to_string(nums[end - 1]));
        }
        else
        {
            res.push_back(to_string(nums[start]));
        }

        return res;
    }
}