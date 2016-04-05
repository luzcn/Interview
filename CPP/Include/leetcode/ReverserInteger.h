#pragma  once

#include "stdafx.h"
#include <math.h>

namespace ReverserInteger
{
    //  Cannot handle the overflow problem.
    int reverse(int x)
    {
        int n = std::abs(x);
        if (n < 10)
            return x;

        bool isNegative = x < 0 ? true : false;
        int result = 0;

        while (n > 0)
        {
            int last_digit = n % 10;
            result = result * 10 + last_digit;
            n = n / 10;
        }

        if (isNegative)
            return 0 - result;
        else
            return result;
    }

    // can handle the overflow
    int reverse_with_overflow(int x)
    {
        int ret = 0;
        while (x != 0)
        {
            // the INT_MAX is 2147483647, if abs(ret) > 214748364, ret*10 will be at least 2147483650 overflow.
            // we do not need to compare == 214748364, because number between 2147483641...2147483647 is still valid.
            if (abs(ret) > 214748364)
                return 0;

            ret = ret * 10 + x % 10;
            x /= 10;
        }

        return ret;
    }
}


/*
int _tmain(int argc, _TCHAR* argv [])
{
    auto r = ReverserInteger::reverse(-1222223);

    std::cout << r << std::endl;
    return 0;
}*/