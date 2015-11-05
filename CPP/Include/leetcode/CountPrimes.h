#pragma once
#include "stdafx.h"

namespace leetcode
{
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> v(n + 1, true);

        for (int i = 2; i < n; i++)
        {
            if (v[i])
            {
                count++;
                for (int j = i * 2; j < n; j += i)
                {
                    v[j] = false;
                }
            }
        }
        return count;
    }
}

namespace Primes
{
    /**
    Sieve of Eratosthenes
    **/
    vector<int> getPrimes(int n)
    {
        vector<int> res;
        vector<bool> is_prime(n + 1, true);

        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                res.push_back(i);
                // The multiplies of i are not prime numbers.
                for (int j = i * 2; j < n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }

        return res;
    }
}