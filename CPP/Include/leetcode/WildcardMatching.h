#pragma once
#include "stdafx.h"

//mplement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") ? false
//isMatch("aa", "aa") ? true
//isMatch("aaa", "aa") ? false
//isMatch("aa", "*") ? true
//isMatch("aa", "a*") ? true
//isMatch("ab", "?*") ? true
//isMatch("aab", "c*a*b") ? false

// whenever encounter ‘*’ in p, keep record of the current position of ‘*’ in p and the current index in s. 
// Try to match the stuff behind this ‘*’ in p with s, if not matched, just s++ and then try to match again.
namespace leetcode
{
    bool isMatch(string s, string p) 
    {
        int i = 0;
        int j = 0;
        int star = -1;
        int mark = -1;

        while (i < s.size())
        {
            if (j < p.size() && (p[j] == '?' || p[j] == s[i]))
            {
                i++;
                j++;
            }
            else if (j < p.size() && p[j] == '*')
            {
                star = j;
                mark = i;
                j++;
                // ??????, ??s??????p?‘*’?????, 
                // ????,?????if???, ?????, ?????s????????
            }
            else if (star != -1)
            {
                j = star + 1;
                i = ++mark;
            }
            else
            {
                return false;
            }
        }

        // remove redundant '*' in p.
        while (j < p.size() && p[j] == '*')
        {
            j++;
        }

        return j == p.size();
    }
}