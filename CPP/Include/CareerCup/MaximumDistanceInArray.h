#pragma once

#include "stdafx.h"
#include <limits.h>

//  Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].
//  Note:
//    The max profit (best time buy and sell stock 1) solution does not work for this problem.
//  Example: [4,3,5,2,1,2,3,2,3]
//  http://leetcode.com/2011/05/a-distance-maximizing-problem.html

namespace MaximumDistance
{
    //brutal force O(n^2) solution
    int max_distance_bruteforce(vector<int>& A)
    {
        if (A.empty())
            return 0;

        int n = A.size();
        int max_len = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                auto s = A[i];
                auto t = A[j];
                if (t > s)
                {
                    max_len = max(max_len, j - i);
                }
            }
        }

        return max_len;
    }

    int max_distance(vector<int>& A)
    {
        if (A.empty())
            return 0;
        int n = A.size();

        vector<int> left_small_list(n, 0);
        vector<int> right_large_list(n, 0);
        int max_len = 0;

        // Construct left_small_list[] 
        // such that left_small_list[i] stores the minimum value from (A[0], A[1], ... A[i])
        left_small_list[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            left_small_list[i] = min(A[i], left_small_list[i - 1]);
        }

        // from right to left, construct right_large_list[], 
        // such that right_large_list[i] stores the maximum value from (A[n-1], A[n-2], ... A[i])
        right_large_list[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right_large_list[i] = max(A[i], right_large_list[i + 1]);
        }

        int i = 0;
        int j = 0;

        // Traverse both arrays from left to right to find optimum j - i
        // similar to the merge of MergeSort.
        while (i < n && j < n)
        {
            if (left_small_list[i] < right_large_list[j])
            {
                max_len = max(max_len, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }

        return max_len;
    }
}