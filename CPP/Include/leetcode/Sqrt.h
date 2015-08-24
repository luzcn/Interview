#pragma once
#include "stdafx.h"

// implement sqrt(x)
namespace leetcode
{
    int mySqrt_NewtonIterative(int x) 
    {
        double g = x/2;
        for (int i = 0; i < 100; i++)
        {
            g = (g + x / g) / 2;
        }

        return g;
    }

    // binary search solution
    int mySqrt(int x)
    {
        if (x < 2)
            return x;
        int l = 0, r = x, mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (x / mid == mid)
                return mid;
            else if (x / mid > mid)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
}