#pragma once
#include "stdafx.h"

namespace leetcode
{
    vector<string> generatePossibleNextMoves(string s)
    {
        if (s.size() <= 1)
            return{};

        vector<string> result;
        bool hasNextMove = false;

        for (int i = 1; i < s.size(); i++)
        {
            string str = "";
            if (s[i] == '+' && s[i - 1] == '+')
            {
                str = s.substr(0, i - 1);
                str += "--";
                hasNextMove = true;
                str += s.substr(i + 1);
                result.push_back(str);
            }
        }

        if (!hasNextMove)
            return{};

        return result;
    }
}