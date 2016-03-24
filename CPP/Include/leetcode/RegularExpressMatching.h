#pragma once

#include "stdafx.h"

//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

namespace leetcode
{
    /*
    bool isMatch(const char *s, const char *p)
    {
        if (*p == '\0')
            return *s == '\0';

        // if next character is not "*", current pattern character must match string character
        if (*(p + 1) != '*')
        {
            return (*s == *p || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
        }

        // next character is "*" and *p can match *s
        while ((*p == *s) || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }

        // the next character is "*", but *p cannot match *s,
        // consider the pattern character has 0 appearance.
        return isMatch(s, p + 2);
    }
    */

    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.empty();

        if (p[1] == '*')
        {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)
                || isMatch(s, p.substr(2));
        }
        else
        {
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
    }
}