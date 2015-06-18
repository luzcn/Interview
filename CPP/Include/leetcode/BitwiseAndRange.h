#pragma once
#include "stdafx.h"

namespace leetcode
{
    /**
    Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

    For example, given the range [5, 7], you should return 4.

    http://math.stackexchange.com/questions/1073532/how-to-find-bitwise-and-of-all-numbers-for-a-given-range

    Thoughts:
    1. The only bits which can be 1 are the bits that are common in m and n
    2. If we find k that bit(m,k) != bit(n,k), then all the bits from k, k-1, k-2 ...0 will be 0
    Solution:
    1. check if bit(m,k) == bit(n,k), we can use x = m ^ n, so the highest 1 is the first position (k) that should set 0.
    2. x | x>> 1 || x >>2 |... will set all the k,k-1,k-2 to 1, so ~x will set all the k,k-1,k-2 to 0
    3. so we can return m & n & ~x.
    **/
    int RangeBitwiseAnd(int m, int n)
    {
        auto x = m ^ n;
        auto s = x >> 1;

        while (s > 0)
        {
            x = x | s;
            s >>= 1;
        }

        return m&n&~x;
    }
}