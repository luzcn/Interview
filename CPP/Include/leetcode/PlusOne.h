#pragma once
#include "stdafx.h"

namespace leetcode
{
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits.empty())
        {
            return digits;
        }

        vector<int> result;

        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9)
        {
            result.push_back(0);
            i--;
        }

        if (i < 0)
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(digits[i] + 1);
            i--;
            while (i >= 0)
            {
                result.push_back(digits[i--]);                
            }
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
}

