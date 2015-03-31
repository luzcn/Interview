#pragma once
#include "stdafx.h"

/***
 *	 Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.
 */

namespace FindFirstMissingPositiveNumber
{
    using namespace std;

    // O(1) space solution,
    // Reuse the input array.
    int firstMissingPositive(int A[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            auto t = A[i];
            while (t > 0 && t <= n && A[t - 1] != t) // in the range of 1...n
            {
                //save the A[t-1] and set A[t-1] as t.
                auto temp = A[t - 1];
                A[t - 1] = t;
                t = temp;
            }
        }

        int i = 0;
        for (i = 0; i < n; ++i)
        {
            if (A[i] != i + 1)
                break;
        }

        return i + 1;
    }

#pragma region O(n) Space Solution
    /***
     *	O(n) time, O(n) space solution.
     *	simillar to counting sourt.
     *	create a new array with size n, for
     */
    int firstMissingPositive2(int A[], int n)
    {

        vector<int> C(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (A[i] > 0 && A[i] <= n)  // in the range of 1...n
            {
                C[A[i] - 1] = A[i];
            }
        }

        for (int i = 0; i < C.size(); ++i)
        {
            if (C[i] == 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
#pragma endregion 

}