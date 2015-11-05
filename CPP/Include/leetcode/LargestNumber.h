#pragma once
#include "stdafx.h"

namespace LargestNumber
{
    string largestNumber(vector<int>& num)
    {
        std::sort(num.begin(), num.end(), [&](int a, int b) {
            auto s = to_string(a) + to_string(b);
            auto t = to_string(b) + to_string(a);

            return s > t;
        });

        string res;
        for (auto s : num)
        {
            res += to_string(s);
        }

        return res[0] == '0' ? "0" : res;
    }
}
