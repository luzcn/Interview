#pragma once

#include "stdafx.h"

/**
 *	Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 For "(()", the longest valid parentheses substring is "()", which has length = 2.

 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
namespace longestValidParentheses
{
    int longestValidParentheses(string& s)
    {
        int count = 0;
        int current_len = 0;
        int max_len = 0;

        // from 0...n
        for (int i = 0; i < s.size(); ++i)
        {
            // checking current character is '(' or ')'
            // if it is '(', keep on increasing the count and current_len
            // if ')', decreasing the count, but keep on increasing the current length.
            if (s[i] == '(')
            {
                count++;
                current_len++;
            }
            if (s[i] == ')')
            {
                count--;
                current_len++;
            }

            // if we have count == 0, we find valid parathensis
            if (count == 0)
            {
                max_len = max(max_len, current_len);
            }
            if (count < 0)
            {
                current_len = 0;
                count = 0;
            }
        }

        // from n-1...0
        count = 0;
        current_len = 0;
        for (int i = s.size() - 1; i > 0; --i)
        {
            if (s[i] == ')')
            {
                count++;
                current_len++;
            }
            if (s[i] == '(')
            {
                count--;
                current_len++;
            }

            if (count == 0)
            {
                max_len = max(max_len, current_len);
            }
            if (count < 0)
            {
                count = 0;
                current_len = 0;
            }
        }

        return max_len;
    }
}