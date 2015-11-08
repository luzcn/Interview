#pragma once
#include "stdafx.h"

namespace careercup
{
    // convert integer (both negative or non-negative) represented as a string to binary
    // Assume, the input string is always valid.
    // "+1234", "-12", "34"
    string convert(string s)
    {
        if (s.empty())
            return "";
        bool isNeg = false;

        int n = stoi(s);
        if (n < 0)
        {
            isNeg = true;
            n = 0 - n;
        }
        string res(32, '0');

        int i = 0;
        while (n != 0)
        {
            int temp = n % 2;
            res[i] = temp + '0';
            i++;
            n >>= 1;
        }

        std::reverse(res.begin(), res.end());
        if (isNeg)
        {
            res[0] = '1';
            for (int i = 1; i < 32; i++)
            {
                if (res[i] == '0')
                {
                    res[i] = '1';
                }
                else if (res[i] == '1')
                {
                    res[i] = '0';
                }
            }
        }

        int start = 0;
        while (start < 32 && res[start] == '0')
        {
            start++;
        }

        return res.substr(start);
    }
}