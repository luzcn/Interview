#pragma once
#include "stdafx.h"
// Validate if a given string is numeric.
//
// Some examples :
// "0" = > true
// " 0.1 " = > true
// "abc" = > false
// "1 a" = > false
// "2e10" = > true
//
// Note: It is intended for the problem statement to be ambiguous.
// You should gather all requirements up front before implementing one.

// 3. -> true
// e23 -> false
// 2e3.23 -> false
namespace leetcode
{
bool isNumber(string s)
{
    if (s.empty())
        return false;

    int i = 0;
    bool has_sign = false;
    int count_dot = 0;
    int count_e = 0;
    int status = 0;

    while (i < s.size() && iswspace(s[i]))
    {
        i++;
    }
    if (i == s.size())
        return false;

    int j = s.size() - 1;
    while (j >= 0 && iswspace(s[j]))
    {
        j--;
    }

    // 1 -> digits
    // 2 -> '+/-'
    // 3 -> '.'    .23
    // 4 -> '.'    23.
    // 5 -> 'e|E'
    for (; i <= j; i++)
    {
        char c = s[i];
        switch (status)
        {
        case 0:
            if (isdigit(c))
                status = 1;
            else if (c == '+' || c == '-')
                status = 2;
            else if (c == '.')
            {
                if (++count_dot > 1)
                    return false;

                status = 3;
            }
            else
                return false;
            break;
        case 1: // digit, end state
            if (isdigit(c))
                status = 1;
            else if (c == '.')
            {
                if (++count_dot > 1)
                    return false;

                status = 4;
            }
            else if (c == 'e' || c == 'E')
            {
                if (++count_e > 1)
                    return false;

                status = 5;
            }
            else
                return false;
            break;
        case 2: // +/-
            if (isdigit(c))
                status = 1;
            else if (c == '.')
            {
                if (++count_dot > 1)
                    return false;

                status = 3;
            }
            else
                return false;
            break;
        case 3:
            if (isdigit(c))
                status = 1;
            else
                return false;
            break;
        case 4:     // can be end state
            if (isdigit(c))
                status = 1;
            else if (c == 'e' || c == 'E')
            {
                if (++count_e > 1)
                    return false;

                status = 5;
            }
            else
                return false;
            break;
        case 5:     // e
            count_dot = 1;
            if (isdigit(c))
                status = 1;
            else if (c == '+' || c == '-')
                status = 2;
            else
                return false;
            break;
        }
    }
    return status == 1 || status == 4;
}
}