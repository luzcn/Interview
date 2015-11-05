#pragma once
#include "stdafx.h"

namespace lintcode
{
    // pow(a, n) % b
    int fastPow(int a, int b, int n)
    {
        if (n == 0)
            return 1 % b;
        if (n == 1)
            return a % b;

        // (a*b)%p = ((a%p)*(b%p))%p
        long product = fastPow(a, b, n / 2);
        product = (product*product)%b;
        if (n % 2 == 1)
        {
            product = (product*a)%b;
        }

        return product;
    }
}