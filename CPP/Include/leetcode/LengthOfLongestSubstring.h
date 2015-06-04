#pragma once
#include "stdafx.h"

namespace leetcode
{
    int lengthOfLongestSubstring(string str)
    {
        if (str.empty())
            return 0;

        int len = 1;
        unordered_map<char, int> map;

        int start = 0;
        int end = start;
        int current_len = 0;

        while (end < str.size())
        {
            char c = str[end];
            if (map.find(c) == map.end()) // not duplicate
            {
                map.emplace(c, end);
                current_len++;
                end++;
            }
            else
            {
                if (map[c] >= start)
                {
                    start = map[c] + 1;
                }
                map[c] = end;
                current_len = end - start + 1;
                end++;
            }

            if (current_len > len)
                len = current_len;
        }

        return len;
    }
}