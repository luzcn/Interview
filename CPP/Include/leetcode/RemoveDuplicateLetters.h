#pragma once
#include "stdafx.h"

//Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.
//You must make sure your result is the smallest in lexicographical order among all possible results.
//
//Example:
//
//Given "bcabc"
//Return "abc"
//
//Given "cbacdcbc"
//Return "acdb"
namespace leetcode
{
    string removeDuplicateLetters(string str)
    {
        if (str.empty())
            return{};

        bool processed[26] = {};
        int counts[26] = {};
        string result = "";

        for (char c : str)
        {
            counts[c - 'a']++;
        }

        for (char c : str)
        {
            counts[c - 'a']--;
            if (processed[c - 'a'])
                continue;

            while (!result.empty() && counts[result.back() - 'a'] > 0 && c < result.back())
            {
                processed[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            processed[c - 'a'] = true;
        }

        return result;
    }
}