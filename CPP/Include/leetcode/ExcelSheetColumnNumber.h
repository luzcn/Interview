#pragma once
#include "stdafx.h"

/**
    Given a column title as appear in an Excel sheet, return its corresponding column number.

    For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    **/
namespace ExcelSheetColumnNumber
{
    int titleToNumber(string s)
    {
        if (s.empty())
            return 0;

        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res *= 26;
            res += s[i] - 'A' + 1;
        }

        return res;
    }
}