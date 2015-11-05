#pragma once
#include "stdafx.h"

// Given n pieces of wood with length L[i](integer array).
// Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
// What is the longest length you can get from the n pieces of wood? 
// Given L & k, return the maximum length of the small pieces.
// Example:
// For L=[232, 124, 456], k=7, return 114.
namespace lintcode
{
    int woodCut(vector<int> L, int k)
    {
        // write your code here
        if (L.empty() || k == 0)
            return 0;

        int shortest = *std::max_element(L.begin(), L.end());
        int res = 0;

        int l = 1;
        int r = shortest;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            int sum = 0;
            for (auto n : L)
            {
                sum += n / m;
            }
            if (sum >= k)
            {
                res = m;    // keeps searching to find the maximum length
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return res;
    }
}