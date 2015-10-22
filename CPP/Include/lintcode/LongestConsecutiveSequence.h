#pragma once
#include "stdafx.h"

//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//Example
//
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//Clarification
//
//Your algorithm should run in O(n) complexity.

namespace lintcode
{
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int len = 1;
        int maxLen = 1;

        // init to a hashmap
        unordered_set<int> visited;
        for (int n : nums)
        {
            visited.insert(n);
        }

        for (int n : nums)
        {
            visited.erase(n);
            len = 1;
            int temp = n + 1;
            while (visited.find(temp) != visited.end())
            {
                len++;
                maxLen = max(maxLen, len);
                visited.erase(temp);
                temp++;
            }

            temp = n - 1;
            while (visited.find(temp) != visited.end())
            {
                len++;
                maxLen = max(maxLen, len);
                visited.erase(temp);
                temp--;
            }
        }

        return maxLen;
    }
}