#pragma once
#include "stdafx.h"

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/
namespace leetcode
{
#pragma region Solution 1
    // need to scan the strings twice
    bool isIsomorphic_helper(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;

        for (int i = 0; i < s.size(); i++)
        {
            char cs = s[i];
            char ct = t[i];

            if (maps.find(cs) == maps.end())
            {
                maps.emplace(cs, i);
            }
            else
            {
                if (mapt.find(ct) == mapt.end() || maps[cs] != mapt[ct])
                    return false;
                else
                    maps[cs] = i;
            }

            mapt[ct] = i;
        }
        return true;
    }
#pragma endregion
    bool isIsomorphic_helper2(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
    }

    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        return isIsomorphic_helper(s, t) && isIsomorphic_helper(t, s);
    }
}