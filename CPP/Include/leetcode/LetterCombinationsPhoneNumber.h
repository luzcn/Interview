#pragma once
#include "stdafx.h"

namespace leetcode
{
    //  Given a digit string, return all possible letter combinations that the number could represent.
    //    A mapping of digit to letters(just like on the telephone buttons) is given below.
    //    Input:Digit string "23"
    //    Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    void dfs(unordered_map<char, string>& letters, string& digits, int index,
        vector<string>& result, string& current)
    {
        if (index >= digits.size())
        {
            result.push_back(current);
            return;
        }

        for (char c : letters[digits[index]])
        {
            current.push_back(c);

            dfs(letters, digits, index + 1, result, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return{};

        unordered_map<char, string> letters{
            { '0', " " },
            { '1', "" },
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8',  "tuv" },
            { '9', "wxyz" },
            { '*',  "+" },
            { '#',  "#" }
        };

        vector<string> result;
        string current;

        dfs(letters, digits, 0, result, current);

        return result;
    }
}