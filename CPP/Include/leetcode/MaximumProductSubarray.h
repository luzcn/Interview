#pragma once

#include "stdafx.h"

namespace MaximumProductSubarray
{
    /***
     * Find the contiguous subarray within an array (containing at least one number) which has the largest product.

     For example, given the array [2,3,-2,4],
     the contiguous subarray [2,3] has the largest product = 6.
     *	examle: (-2,3,-4) the result should be 24.
     *
     */
    int maxProduct(int A [], int n)
    {
        if (n <= 0)
            return 0;

        vector<int> max_sofar(n);
        vector<int> min_sofar(n);

        int maxProduct = A[0];
        max_sofar[0] = A[0];
        min_sofar[0] = A[0];

        for (int i = 1; i < n; ++i)
        {
            max_sofar[i] = max(max(max_sofar[i - 1] * A[i], A[i]), min_sofar[i - 1] * A[i]);
            min_sofar[i] = min(min(max_sofar[i - 1] * A[i], A[i]), min_sofar[i - 1] * A[i]);

            maxProduct = max(maxProduct, max_sofar[i]);
        }

        return maxProduct;
    }
}