#pragma once
#include "stdafx.h"
#include <numeric>

//You have to paint N boards of length{ A0, A1, A2 ... AN - 1 }.
//There are K painters available and you are also given how much time a painter takes to paint 1 unit of board.
//
//You have to get this job done as soon as possible under the constraints 
//that any painter will only paint continuous sections of board, 
//say board{ 2, 3, 4 } or only board{ 1 } or nothing but not board{ 2, 4, 5 }.

// Given an array of non-negative integers A and a positive integer k, we want to:
// Divide A into k or fewer partitions, such that the maximum sum over all the partitions is minimized.
namespace careercup
{
    int sum(vector<int>& A, int start, int end)
    {
        int total = 0;
        for (int i = start; i <= end; i++)
        {
            total += A[i];
        }

        return total;
    }

    int partitionRec(vector<int>& A, int n, int k)
    {
        if (k == 1)
            return sum(A, 0, n - 1);
        if (n == 1)
            return A[0];

        int best = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            int lastSum = sum(A, j, n - 1);
            int leftOPT = partitionRec(A, j, k - 1);

            best = min(best, max(leftOPT, lastSum));
        }

        return best;
    }

    int partition(vector<int> boards, int k)
    {
        return partitionRec(boards, boards.size(), k);
    }


    // DP solution
}