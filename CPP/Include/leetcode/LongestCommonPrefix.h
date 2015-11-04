#pragma once
#include "stdafx.h"

// Write a function to find the longest common prefix string amongst an array of strings. 
namespace leetcode
{
    string longestCommonPrefix(vector<string>& strs) 
    {
        string prefix = "";
        int index = 0;
        if (strs.empty())
            return prefix;

        int minLength = std::min_element(strs.begin(), strs.end(), [&](string& s1, string& s2) { 
            return s1.size() < s2.size(); 
        })->size();

        while (index < minLength)
        {
            char c = strs[0][index];
            for (int i = 1; i < strs.size(); i++)
            {
                if (c != strs[i][index])
                    return prefix;
            }
            prefix.push_back(c);
            index++;
        }

        return prefix;
    }
}