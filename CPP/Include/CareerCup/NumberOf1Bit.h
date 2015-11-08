#pragma once
#include "stdafx.h"

namespace careercup
{
    // Give a non-negative integer, find the numbers of bit "1" in the integer binary representation.
    // Thought: n&(n-1) will eliminate a single '1' each time. so we can loop this operation util all bits are '0'
    int numberOfOneBit(int n)
    {
        int count = 0;
        while (n != 0)
        {
            n = n&(n - 1);
            count++;
        }
    }

    int numberOfOneBit2(int n)
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & 1)
                count++;

            n >>= 1;
        }
    }
}