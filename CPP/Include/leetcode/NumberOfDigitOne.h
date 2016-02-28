#pragma once
#include "stdafx.h"

//Given an integer n, count the total number of digit 1 appearing in all non - negative integers less than or equal to n.
//
//For example :
//Given n = 13,
//Return 6, because digit 1 occurred in the following numbers : 1, 10, 11, 12, 13.
//
//Hint :
//
//    Beware of overflow.

// The idea is to calculate occurrence of 1 on every digit.There are 3 scenarios, for example
//
// if n = xyzdabc
//
// and we are considering the occurrence of one on thousand, it should be :
//
// (1) xyz * 1000                     if d == 0
// (2) xyz * 1000 + abc + 1           if d == 1
// (3) xyz * 1000 + 1000              if d > 1

namespace leetcode
{
    int countDigitOne(int n)
    {
        if (n <= 0)
            return 0;

        int result = 0;
        int pos = 1;
        int q = n;

        while (q > 0)
        {
            int digit = q % 10;
            q /= 10;

            // q is the value on the left side of the pos.
            result += q * pos;

            if (digit == 1)
            {
                result += (n % pos) + 1;
            }
            else if (digit > 1)
            {
                result += pos;
            }

            pos *= 10;
        }

        return result;
    }
}