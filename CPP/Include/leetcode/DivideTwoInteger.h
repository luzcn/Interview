#pragma  once

#include "stdafx.h"
#include <limits>

namespace leetcode
{
    // compute dividend/divisor
    int divide(int dividend, int divisor)
    {
        if (dividend == 0 || divisor == 1)
            return dividend;

        if (divisor == 2)
            return dividend >> 1;

        // INT_MAX/INT_MIN = 0
        if (dividend == INT_MAX && divisor == INT_MIN)
            return 0;

        bool isNegative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
        {
            isNegative = true;
        }

        size_t m = abs(dividend), n = abs(divisor);

        // abs(INT_MIN) == INT_MIN
        if (dividend == INT_MIN)
            m = INT_MAX;

        if (divisor == INT_MIN)
            n = INT_MAX;

        size_t d = n;
        size_t c = 1;
        while (m > d)
        {
            d <<= 1;
            c <<= 1;
        }

        int result = 0;
        while (m >= n)
        {
            while (m >= d)
            {
                m -= d;
                result += c;
            }

            d >>= 1;
            c >>= 1;
        }

        return isNegative ? 0 - result : result;
    }
}