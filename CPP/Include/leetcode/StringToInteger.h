#pragma once
#include "stdafx.h"

// atoi problem
// need to consider the input valid and overflow problem.
// some testcase: "    12", "111","+12340","2147483647" "-2147483648","-1230dx"
namespace leetcode
{
    int myAtoi(string s)
    {
        if (s.empty())
            return 0;

        int i = 0;
        while (i < s.size() && iswspace(s[i]))
        {
            i++;
        }

        bool isNeg = false;
        if (s[i] == '-')
        {
            isNeg = true;
            i++;
        }
        else if (s[i] == '+')
        {
            isNeg = false;
            i++;
        }

        int res = 0;
        while (i < s.size())
        {
            if (!isdigit(s[i]))
                break;

            // if res > int_max/10, then res*10 must > int_max, so overflow
            // if res == int_max/10 but ths s[i] is larger than int_max % 10,
            //  res*10+s[i] should larger than int_max.
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
            {
                return isNeg ? INT_MIN : INT_MAX;
            }

            res = res * 10 + s[i] - '0';
            i++;
        }

        return isNeg ? 0 - res : res;
    }
}