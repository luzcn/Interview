#pragma once
#include "stdafx.h"

// Implement pow
namespace leetcode
{
    // Naive solution O(n) time
    // Assume n is non negative, we can simpley return x*x*x...*x for n times.
    double myPow2(double x, int n)
    {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;

        double res = 1;
        for (int i = 0; i < n; i++)
        {
            res = res*x;
        }

        return res;
    }

    // Recurvie solution
    // As we know, x^n = x^(n/2) * x^(n/2) * x^(n%2)
    namespace helper
    {
        // This also takes O(nlog(n)) time.
        // Consider this recursive function generates a binary tree,
        // it needs to check all the n leaf nodes with log(n) height.
        double myPowRec(double x, int n)
        {
            if (n == 0)
                return 1;
            if (n == 1)
                return x;

            int half = n / 2;
            int remainder = n % 2;

            if (remainder == 0)
                return myPowRec(x, half) * myPowRec(x, half);
            else
                return myPowRec(x, half) * myPowRec(x, half) * x;
        }

        // In previous function, we can easily see there is duplicate computation
        // with "mypowRec(x, half) * mypowRec(x, half)" 
        // because these two recursive call actually returns identical result.
        double myPowRecImproved(double x, int n)
        {
            if (n == 0)
                return 1;

            double res = myPowRecImproved(x, n / 2);

            if (n % 2 == 0)
                return res*res;
            else
                return res*res*x;
        }
    }

    double myPow(double x, int n)
    {
        if (n < 0)
            return 1 / helper::myPowRecImproved(x, -n);
        else
            return helper::myPowRecImproved(x, n);
    }
}