#pragma once
#include "stdafx.h"

/***
 *	 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2].
 */
namespace RemoveDuplicatesFromSortedArray
{
    int removeDuplicates(int A [], int n)
    {
        if (n <= 1)
            return n;

        int start = 0;
        int end = 1;

        while (end < n)
        {
            if (A[start] != A[end])
            {
                start++;
                A[start] = A[end];
            }
            end++;
        }

        return start + 1;
    }

    /***
     *	 Follow up for "Remove Duplicates":
        What if duplicates are allowed at most twice?

        For example,
        Given sorted array A = [1,1,1,2,2,3],

        Your function should return length = 5, and A is now [1,1,2,2,3]. 
     */
    int removeDuplicates2(int A [], int n)
    {
        if (n <= 1)
        {
            return n;
        }

        int s = 0;
        int e = 1;
        int count = 1;

        while (e < n)
        {
            if (A[s] != A[e])
            {
                A[++s] = A[e];
                count = 1;
            }
            else
            {
                if (count < 2)
                {
                    count++;
                    s++;
                    A[s] = A[e];
                }
            }
            e++;
        }
        return s + 1;
    }
}