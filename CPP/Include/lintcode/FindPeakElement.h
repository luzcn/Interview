#pragma once
#include "stdafx.h"

//Find Peak Element
//There is an integer array which has the following features :
//
//The numbers in adjacent positions are different.
//A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
//
//We define a position P is a peek if :
//    A[P] > A[P - 1] && A[P] > A[P + 1]
//    Find a peak element in this array.Return the index of the peak.
//    Example:
//    Given[1, 2, 1, 3, 4, 5, 7, 6]
//    Return index 1 (which is number 2) or 6 (which is number 7)
namespace lintcode
{
    int findPeak(vector<int>& A)
    {
        if (A.size() < 3)
            return 0;

        int l = 0;
        int r = A.size() - 1;
        while (l + 1 < r)
        {
            int m = l + (r - l) / 2;
            if (A[m] > A[m - 1] && A[m] > A[m + 1])  // Am-1 < Am > Am+1
                return m;
            else if (A[m - 1] < A[m] && A[m] < A[m + 1])    // Am-1 < Am < Am+1
                l = m;
            else
                r = m;  // Am-1 > Am > Am+1 or Am-1 > Am < Am+1
        }
        return -1;
    }
}