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
// http://articles.leetcode.com/2011/04/the-painters-partition-problem.html
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
#if 0
    int partitionRec(vector<int>& A, int start, int k)
    {
        if (k == 1)
            return sum(A, start, A.size() - 1);

        int best = INT_MAX;
        for (int i = start; i < A.size(); i++)
        {
            auto leftSum = sum(A, start, i);
            auto rightOPT = partitionRec(A, i + 1, k - 1);

            best = min(best, max(leftSum, rightOPT));
        }

        return best;
    }
#endif

    void print(vector<vector<int>>& M)
    {
        for (auto v : M)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    // DP solution
    int partitionDP(vector<int> A, int k)
    {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(k));
        vector<int> sum(A.size());
        sum[0] = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            sum[i] = sum[i - 1] + A[i];
        }

        // dp[0][k] is always A[0]
        for (int j = 0; j < k; j++)
        {
            dp[0][j] = sum[0];
        }

        // dp[n][0] is sum of {A0, A1,..., An}
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = sum[i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < k; j++)
            {
                int best = INT_MAX;
                for (int p = 0; p < i; p++)
                {
                    auto LastSum = sum[i] - sum[p]; // the sum of {Ap, Ap+1...Ai}
                    auto LeftOPT = dp[p][j - 1];
                    best = std::min(best, max(LastSum, LeftOPT));

                }
                dp[i][j] = best;
            }
        }
        return dp[n - 1][k - 1];
    }


    // compute how many workers required, 
    // if the array is partitioned as the sum of each subarray has maximun value of "maxInPartition" 
    int getRequireWorks(vector<int>& A, int maxInPartition)
    {
        int nums = 1;
        int total = 0;
        for (int i = 0; i < A.size(); i++)
        {
            total += A[i];

            if (total > maxInPartition)
            {
                nums++;
                total = A[i];
            }
        }

        return nums;
    }

    // O(Nlogc), c is the range [max_element(A)... sum(A)].
    // From observation, we can easily see:
    // - if k == 1, the result is sum(A).
    // - if k >= n, the result is max_element(A).
    int partitionBinarySearch(vector<int>& A, int k)
    {
        int low = *max_element(A.begin(), A.end());
        int high = sum(A, 0, A.size() - 1);

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int workers = getRequireWorks(A, mid);
            if (workers <= k)
            {
                high = mid;
            }
            else
            {
                // if wokers > k, the value "mid" is not a valid solution, so must discard it.
                low = mid + 1;
            }
        }

        return low;
    }

    int partition(vector<int> boards, int k)
    {
        return partitionDP(boards, k);
        //return partitionRec(boards, boards.size(), k);
    }
}