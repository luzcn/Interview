#pragma once
#include "stdafx.h"

// A palindrome is a String that is spelled the same forward and backwards.
// 
// Given a String base that may or may not be a palindrome,  we can always force base to be a palindrome by adding letters to it.
//
// For example, given the word "RACE", we could add the letters "CAR" to its back to get "RACECAR" (quotes for clarity only).
// However, we are not restricted to adding letters at the back.
//
// For example, we could also add the letters "ECA" to the front to get "ECARACE".
// In fact, we can add letters anywhere in the word, so we could also get "ERCACRE" by adding an 'E' at the beginning, 
// a 'C' after the 'R', and another 'R' before the final 'E'.
//
// Your task is to make base into a palindrome by adding as few letters as possible and return the resulting String.
// When there is more than one palindrome of minimal length that can be made, 
// return the lexicographically earliest (that is, the one that occurs first in alphabetical order).

namespace leetcode
{
    // Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it.
    // Find and return the shortest palindrome you can find by performing this transformation.
    //    For example :
    //  Given "aacecaaa", return "aaacecaaa".
    //  Given "abcd", return "dcbabcd".

    // Thougeht:
    // Since the problem asks us to add characters infront of the input string,
    // we can find the longest palindrom substring starting from index 0.
    // Using KMP solution to compute the failure table of string "s + reverse(s)"
    // this table can help to solve this problem in O(n) time.
    string shortestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;

        // Since s may contain duplicates,
        // add a special character "#" to avoid incorrectly computing the failure table
        // i.e. s = "aa", s + reverse(s) will be "aaaa", the failure table will be [0, 1,2,3] wichi is incorrect
        string r = s;
        std::reverse(r.begin(), r.end());

        string p = s + "#" + r;
        vector<int> lps(p.size(), 0);

        for (int i = 1; i < p.size(); i++)
        {
            int j = lps[i - 1];
            while (j > 0 && p[i] != p[j])
            {
                j = lps[j - 1];
            }

            lps[i] = j + (p[i] == p[j] ? 1 : 0);
        }

        string str_add = s.substr(lps[lps.size() - 1]);
        std::reverse(str_add.begin(), str_add.end());

        return str_add + s;
    }
}