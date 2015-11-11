#pragma once
#include "stdafx.h"

//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.
namespace leetcode
{

    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        if (s.size() < 2)
            return s.size();

        unordered_map<char, int> map;
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            // if contains 2 characters
            if (map.size() == 2 && map.find(c) == map.end())
            {
                int position = std::min_element(map.begin(), map.end(),
                    [&](pair<char, int> p1, pair<char, int> p2) {return p1.second < p2.second; })->second;

                start = position + 1;
                map.erase(s[position]);
            }

            map[c] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
}