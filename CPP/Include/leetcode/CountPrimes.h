#pragma once
#include "stdafx.h"

namespace leetcode
{
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> isPrime(n + 1, true);

        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                count++;
                for (int j = 2; j*i < n; j++)
                {
                    isPrime[j*i] = false;
                }
            }
        }
        return count;
    }

    //Sieve of Eratosthenes
    vector<int> getPrimes(int n)
    {
        vector<int> result;
        vector<bool> is_prime(n + 1, true);

        for (int i = 2; i < n; i++)
        {
            if (is_prime[i])
            {
                result.push_back(i);
                // The multiplies of i are not prime numbers.
                // i.e. 2*i , 3*i, 4*i ... are not prime.
                for (int j = 2; j * i < n; j++)
                {
                    is_prime[j*i] = false;
                }
            }
        }

        return result;
    }
}