#pragma once
#include "stdafx.h"

//  Given a string S and a string T, find the minimum window in S which will contain 
// all the characters in T in complexity O(n).
//
//  For example,
//  S = "ADOBECODEBANC"
//  T = "ABC"
//
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the empty string "".
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
//
// Thought:
// 1. the string T may have duplicate characters, so using a hashmap to store the index of characters does not work.
// 2. using a hashmap to store the character which is required in T and the numbers of character we have found so far.
// 3. once we found a window, move the begin index as far as we can
//   - if s[begin] is not required in T, simply begin++;
//   - s[begin] is in T, but the numbers of s[begin] we found is larger than required in T, 
//      decrease the numbers of s[begin] and increase the begin index
namespace leetcode
{
    string minWindow(string s, string t)
    {
        string result = "";
        if (s.empty() || t.empty())
            return result;

        unordered_map<char, int> need_find;
        unordered_map<char, int> has_found;
        int minLen = INT_MAX;

        for (char& c : t)
        {
            need_find[c]++;
        }

        int count = 0;
        int begin = 0;
        int end = 0;

        while (end < s.size())
        {
            char c = s[end];
            if (need_find.find(c) != need_find.end())
            {
                has_found[c]++;

                // this check condition is required, since there could be no such window in S
                if (has_found[c] <= need_find[c])
                {
                    count++;
                }

                if (count == t.size()) // find one window
                {
                    // need to increase the begin as far as you can
                    while (true)
                    {
                        if (need_find.find(s[begin]) == need_find.end())
                        {
                            // the s[begin] character is not required to find
                            begin++;
                        }
                        else if (has_found[s[begin]] > need_find[s[begin]])
                        {
                            // found more characters of s[begin] than required.
                            has_found[s[begin]]--;
                            begin++;
                        }
                        else
                        {
                            break;
                        }
                    }

                    int currentLen = end - begin + 1;
                    if (currentLen < minLen)
                    {
                        minLen = currentLen;
                        result = s.substr(begin, minLen);
                    }
                }
            }


            end++;
        }

        return result;
    }
}