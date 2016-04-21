#pragma once
#include "stdafx.h"

/**
*  Given n non-negative integers representing an elevation map where the width of each bar is 1,
    compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
namespace TrappingRainingWater
{
    /*
    for input: A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] N = sizeof(A)
    *
    * compute B[] where B[i] = Max(A[0..i]) Calculate Max bar height from node 0 - i
    * B = [0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
    *
    * compute C[] where C[i] = Max(A[i..N]) Calculate Max bar height from node i - n
    * C = [3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
    *
    * compute D[] where D[i] = Min(B[i], C[I]) Calculate Min bar height between bar
    * before Vs after i, coz only this much water could fill
    * D = [0, 1, 1, 2, 2, 2, 2, 3, 2, 2, 2, 1]
    *
    * compute E[] where E[i] = D[i] - A[i] Subtract the height of bar i from Max water
    * bars could hold before Vs after E[i] = [0, 0, 1, 0, 1, 2, 1, 0, 0, 1, 0, 0]
    *
    * the answer is sum(E[i]) the complexity is O(N)
    **/
    int trap(vector<int>& height)
    {
        if (height.empty())
        {
            return 0;
        }

        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(height[i], left[i - 1]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i], right[i + 1]);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += (min(left[i], right[i]) - height[i]);
        }

        return result;
    }
}