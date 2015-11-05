#pragma once
#include "stdafx.h"

namespace leetcode
{
    //  Given a digit string, return all possible letter combinations that the number could represent.
    //    A mapping of digit to letters(just like on the telephone buttons) is given below.
    //    Input:Digit string "23"
    //    Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
    namespace helper
    {
        void combineRec(vector<string>& inputs, vector<string>& res, string& current, int index)
        {
            if (index == inputs.size())
            {
                res.push_back(current);
                return;
            }

            auto in = inputs[index];
            for (int i = 0; i < in.size(); i++)
            {
                current += in[i];
                combineRec(inputs, res, current, index + 1);
                current.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> letters{ "","abc","def","ghi","jkl","mno",
            "pqrs","tuv","wxyz","+", " ", "#" };

        vector<string> inputs;
        vector<string> res;
        for (int i = 0; i < digits.size(); i++)
        {
            inputs.push_back(letters[digits[i] - '1']);
        }

        string current = "";
        helper::combineRec(inputs, res, current, 0);
        return res;
    }
}