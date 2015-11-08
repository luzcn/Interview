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
        int m = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (map.size() < 2 || map.size() == 2 && map.find(c) != map.end())
            {
                maxLen = max(maxLen, i - m + 1);
            }
            // if contains 2 characters
            else //if (map.size() == 2 && map.find(c) == map.end())
            {
                maxLen = max(maxLen, i - m);

                int leftMost = std::min_element(map.begin(), map.end(), 
                    [&](pair<char, int> p1, pair<char, int> p2) {return p1.second < p2.second; })->second;

                m = leftMost + 1;
                map.erase(s[leftMost]);
            }

            map[c] = i;
        }

        return maxLen;
    }
}