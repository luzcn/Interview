#pragma once
#include "stdafx.h"

namespace leetcode
{
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits.empty())
            return digits;

        vector<int> res;

        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9)
        {
            res.push_back(0);
            i--;
        }

        if (i < 0)
        {
            res.push_back(1);
        }
        else
        {
            res.push_back(digits[i] + 1);
            i--;
            while (i >= 0)
            {
                res.push_back(digits[i]);
                i--;
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
}

