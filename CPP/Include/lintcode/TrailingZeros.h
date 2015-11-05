#pragma once
#include "stdafx.h"

//Trailing Zeros
//
//Write an algorithm which computes the number of trailing zeros in n factorial.
//Example
//11!= 39916800, so the out should be 2
//  Thoughts: 
//  only pairs of (2,5) will genenrate a trailing zero in n!, 
//  and we can find 2 or multiplies of 2 are always more than 5, all we need is to find how many 5 from 1..n. 
//  If we simply use n/5, then we need to count extra 5 from 25,125...since 25=5*5, there is one extra 5.
//  so we need to keep divide by 5 to count these extra 5.
namespace lintcode
{
    long long trailingZeros(long long n)
    {
        long long res = 0;
        while (n >= 5)
        {
            res += n / 5;
            n /= 5;
        }

        return res;
    }
}