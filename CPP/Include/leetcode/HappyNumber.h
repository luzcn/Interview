#pragma once
#include "stdafx.h"


/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Thoughts: if the number n is unhappy number, it will produce a repeated number from the sequence.
*/
namespace HappyNumber
{
    int compute_square(int n)
    {
        int sum = 0;
        auto t = to_string(n);
        for (int i = 0; i < t.size(); i++)
        {
            auto d = t[i] - '0';
            sum += d*d;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        std::unordered_set<int> set;
        while (n > 1)
        {
            if (set.find(n) == set.end())
            {
                set.emplace(n);
                n = compute_square(n);
                if (n == 1)
                    return true;
            }
            else
                break;
        }
        return false;
    }
}
