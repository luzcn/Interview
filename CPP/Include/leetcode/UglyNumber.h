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

            // to avoid the duplicates, should not use "else"
            // i.e. 12 can come from 4*3 and 6*2
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

    // follow up: if the number is computed by this formular: 2^i * 5^j
    int nthUglyNumber2(int n)
    {
        vector<int> v;
        v.push_back(1);

        int i = 0, j = 0;

        while (v.size() < n)
        {
            int minElement = min(v[i] * 2, v[j] * 5);

            if (minElement == v[i] * 2)
                i++;
            if (minElement == v[j] * 5)
                j++;

            v.push_back(minElement);
        }

        return v.back();
    }


    //Super Ugly Number
    // Write a program to find the nth super ugly number.
    // Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
    // For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers 
    // given primes = [2, 7, 13, 19] of size 4.
    //    Note:
    //  - 1 is a super ugly number for any given primes.
    //  - The given numbers in primes are in ascending order.
    //  - 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        if (n <= 0 || primes.empty())
            return 0;

        unordered_map<int, int> map;

        for (int& factor : primes)
        {
            map[factor] = 0;
        }

        vector<int> result{ 1 };

        while (result.size() < n)
        {
            int m = INT_MAX;
            for (int& factor : primes)
            {
                if (result[map[factor]] * factor < m)
                {
                    m = result[map[factor]] * factor;
                }
            }

            for (int& factor : primes)
            {
                if (result[map[factor]] * factor == m)
                {
                    map[factor]++;
                }
            }

            result.push_back(m);
        }

        return result.back();
    }
}