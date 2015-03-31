#pragma  once

#include "stdafx.h"
#include <limits>

namespace DivideTwoInteger
{
    /**
     *	O(n) solution
     *	the idea is simply keep on minus the divisor, until the dividen is less than divisor.
     */
    int divide_helper(int d1, int d2)
    {
        if (d1 == 0 || d2 == 1) { return d1; }
        if (d2 == 2) { return d1 >> 1; }

        int count = 0;
        while (d1 >= d2)
        {
            d1 -= d2;
            count++;
        }

        return count;      
    }

    /**
     *	O(log(n)) soltion
     *	the idea is divisor << 1
     */
    int divide_helper2(int d1, int d2)
    {
        if (d1 == 0 || d2 == 1) { return d1; }
        if (d2 == 2) { return d1 >> 1; }

        int result = 0;
        auto temp = d2;

        while (d1 > temp)
        {

        }
        return result;
    }

    int divide(int dividend, int divisor)
    {
        bool isNegative = false;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
        {
            isNegative = true;
        }

        auto result = divide_helper(abs(dividend), abs(divisor));

        return isNegative ? 0 - result : result;
    }
}