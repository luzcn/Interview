#pragma once
#include "stdafx.h"

// Remove the minimum number of invalid parentheses in order to make the input string valid.
// Return all possible results.
//
// Note: The input string may contain letters other than the parentheses(and).
//
//    Examples :
//
//    "()())()" ->["()()()", "(())()"]
//    "(a)())()" ->["(a)()()", "(a())()"]
//    ")(" ->[""]
//
namespace leetcode
{
    void dfs(string& s, vector<string>& result, string current, int start, int open)
    {
        if (open < 0)
            return;

        // Always save the longest current string
        if (!result.empty() && current.size() + s.size() - start < result.back().size())
            return;

        if (start == s.size())
        {
            // Always save the longest current string
            if (open == 0 && (result.empty() || current.size() == result.back().size()))
            {
                result.push_back(current);
            }
            return;
        }

        char c = s[start];
        if (c != '(' && c != ')')
        {
            dfs(s, result, current + c, start + 1, open);
        }
        else
        {
            if (c == '(')
            {
                dfs(s, result, current + c, start + 1, open + 1);
            }
            else
            {
                dfs(s, result, current + c, start + 1, open - 1);
            }

            // Remove the duplicates
            while (start < s.size() - 1 && s[start + 1] == s[start])
            {
                start++;
            }

            // we can choose do not use these '(' or ')' characters
            dfs(s, result, current, start + 1, open);
        }
    }


       vector<string> removeInvalidParentheses(string s)
    {
        if (s.empty())
            return{};

        vector<string> result;
        string current;

        dfs(s, result, "", 0, 0);

        return result;
    }
}