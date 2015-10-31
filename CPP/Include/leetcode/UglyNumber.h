#pragma once
#include "stdafx.h"
#include <set>
//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note that 1 is typically treated as an ugly number.
namespace leetcode
{
    bool isUgly(int num)
    {
        if (num < 1)
            return false;

        while (num > 1)
        {
            if (num % 5 == 0)
            {
                num /= 5;
            }
            else if (num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 2 == 0)
            {
                num /= 2;
            }
            else
                return false;
        }

        return num == 1;
    }


    //Write a program to find the n - th ugly number.
    //Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
    //For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
    //Note that 1 is typically treated as an ugly number.
    //
    //Hint:
    //The naive approach is to call isUgly for every number until you reach the nth one.
    //Most numbers are not ugly.Try to focus your effort on generating only the ugly ones.
    int nthUglyNumber(int n)
    {
        vector <int> results;
        results.push_back(1);

        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            auto min_element = min(results[i] * 2, min(results[j] * 3, results[k] * 5));
            if (min_element == results[i] * 2)
                ++i;
            if (min_element == results[j] * 3)
                ++j;
            if (min_element == results[k] * 5)
                ++k;

            results.push_back(min_element);
        }
        return results.back();


    }
}