#pragma once
#include "stdafx.h"

//There is a fence with n posts, each post can be painted with one of the k colors.
//
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//
//Return the total number of ways you can paint the fence.
namespace leetcode
{
    // DP solution
    // For each fence, there are two sub problems: 
    // - it has the same color with previous 
    // - different color with previous one.
    // So, use two variable:
    // S(i): indicate the painting ways number of i if i has the same color with i-1
    // D(i): the painting ways number of i if i has the different color with i-1
    // - S(i) = D(i-1).
    // - D(i) = (S(i-1) + D(i-1))*(k-1).
    int NumWays(int n, int k)
    {
        if (n == 0 || k == 0)
            return 0;

        if (n == 1)
            return k;

        int S = k;  // there are only k ways to paint the first two fences with same colors.
        int D = k*(k - 1);

        for (int i = 2; i < n; i++)
        {
            auto temp = D;
            D = (S + D)*(k - 1);
            S = temp;
        }

        return D + S;
    }
}