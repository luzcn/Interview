#pragma once
#include "stdafx.h"

// compute the greatest common divisor
// Euclid's algorithm https://en.wikipedia.org/wiki/Greatest_common_divisor
namespace careercup
{
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;

        return gcd(b, a%b);
    }
}