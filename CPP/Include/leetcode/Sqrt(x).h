#pragma once
#include "stdafx.h"

//Compute and return the square root of x.
namespace leetcode
{
    // Newton Iteration method
    int mySqrt(int x)
    {
        if (x <= 0)
            return 0;

        double g = x / 2.0;

        for (int i = 0; i < 100; i++)
        {
            g = (g + x / g) / 2;
        }

        return g;
    }
}