#pragma once
#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//You may assume no duplicate exists in the array.
//Example
//
//For[4, 5, 1, 2, 3] and target = 1, return 2.
//For[4, 5, 1, 2, 3] and target = 0, return -1.
namespace leetcode
{
    int search(vector<int> &A, int t)
    {
        if (A.empty())
            return -1;

        int l = 0, r = A.size() - 1;
        while (l <= r)
        {
            // this is important
            // because the following steps do not check equivalence.
            if (A[l] == t)
                return l;
            if (A[r] == t)
                return r;

            int m = l + (r - l) / 2;
            if (A[m] == t)
                return m;
            else if (A[l] < A[m])
            {
                if (t > A[m])
                    l = m + 1;
                else if (t > A[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else    // A[l] > A[m]
            {
                if (t < A[m])
                    r = m - 1;
                else if (t > A[l])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        return -1;
    }
}
