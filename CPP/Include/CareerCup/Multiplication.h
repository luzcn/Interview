#pragma once

#include "stdafx.h"

namespace Multiplication
{
    int getProduct(int a, int b)
    {
        int result;

        while (b != 0)
        {
            if (b & 1) // b is odd nubmer
            {
                result = result + a;
            }

            a = a >> 1;  // means a = a*2
            b = b << 1;  // b will decrease by b/2
        }
        return result;
    }

}