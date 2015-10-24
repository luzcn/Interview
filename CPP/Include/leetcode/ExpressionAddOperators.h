#pragma once
#include "stdafx.h"

//Given a string that contains only digits 0 - 9 and a target value, 
//return all possibilities to add binary operators(not unary) + , -, or *between the digits so they evaluate to the target value.
//
//Examples:
//
//"123", 6 ->["1+2+3", "1*2*3"]
//"232", 8 ->["2*3+2", "2+3*2"]
//"105", 5 ->["1*0+5", "10-5"]
//"00", 0 ->["0+0", "0-0", "0*0"]
//"3456237490", 9191 ->[]

namespace leetcode
{
    void getExpressions(string& num, vector<char>& ops, unordered_set<string>& res, string& current, int start)
    {
        if (start == num.size())
        {
            res.insert(current.substr(0, current.size() - 1));
            //res.push_back(current);
            return;
        }

        for (int j = 0; j < ops.size(); j++)
        {
            for (int i = start; i < num.size(); i++)
            {
                string prefix = num.substr(start, i - start + 1);
                current.append(prefix).push_back(ops[j]);
                getExpressions(num, ops, res, current, i + 1);
                current = current.substr(0, current.size() - prefix.size() - 1);
            }
        }
    }

    unordered_set<string> addOperators(string num, int target)
    {
        vector<char> ops{ '+', '-', '*' };
        unordered_set<string> res;
        string current = "";
        getExpressions(num, ops, res, current, 0);


        return res;
    }
}