#pragma once

#include "stdafx.h"

/*
 *	Write a function to add two numbers, without using "+" and any other operators.
 */
namespace BitsManipulation
{
    // the input number is non-negative
    vector<int> splitNumToDigits(int num)
    {
        vector<int> sol;
        if (num <= 9)
        {
            sol.push_back(num);
        }
        else
        {
            int div = 1;
            while (num / div >= 10)
            {
                div *= 10;
            }

            while (num > 0)
            {
                auto first = num / div;
                sol.push_back(first);
                num = num % div;
                div /= 10;
            }
        }

        return sol;
    }

    int plus(int m, int n)
    {
        if (n == 0)
            return m;

        auto sum = m ^ n;// Add without include carries.
        auto carry = (m&n) << 1;  // carry, but not added yet.
        return plus(sum, carry);
    }
}