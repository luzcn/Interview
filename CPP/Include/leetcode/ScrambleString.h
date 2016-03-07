#pragma once
#include "stdafx.h"

// Given a string s1, we may represent it as a binary tree 
// by partitioning it to two non-empty substrings recursively.
//
// To scramble the string, we may choose any non-leaf node and swap its two children.
// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

namespace leetcode
{
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size())
            return false;

        int check[26]{ 0 };

        for (char c : s1)
        {
            check[c - 'a']++;
        }

        for (char c : s2)
        {
            check[c - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (check[i] != 0)
                return false;
        }

        if (s1.size() == 1 && s2.size() == 1)
            return true;

        for (int i = 1; i < s1.size(); i++)
        {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);

            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);

            if (isScramble(s11, s21) && isScramble(s12, s22))
            {
                return true;
            }

            // already scrambled
            // for example: "great" and "eatgr"
            // need to check s1.substr(0, i) and s2.(s2.size()-i, i)
            s21 = s2.substr(s2.size() - i, i);
            s22 = s2.substr(0, s2.size() - i);
            if (isScramble(s11, s21) && isScramble(s12, s22))
            {
                return true;
            }
        }

        return false;
    }
}