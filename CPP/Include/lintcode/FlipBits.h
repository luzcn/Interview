#pragma once
#include "stdafx.h"

//Determine the number of bits required to flip if you want to convert integer n to integer m.
//Example
//Given n = 31 (11111), m = 14 (01110), return 2.
//
//Both n and m are 32 - bit integers.

namespace lintcode
{
    int bitSwapRequired(int a, int b)
    {
        // write your code here
        int c = a^b;
        int count = 0;
        for (int i = 0; i < 32; i++)    // be careful negative number, cannot use while(c > 0)
        {
            if (c & 1)
                count++;

            c >>= 1;
        }
        return count;
    }
}