#pragma once
#include "stdafx.h"

//Given an array with integers.
//
//Find two non - overlapping subarrays A and B, which | SUM(A) - SUM(B) | is the largest.
//
//Return the largest difference.
//Example
//
//For[1, 2, -3, 1], return 6
//Note
//
//The subarray should contain at least one number
//Challenge
//
//O(n) time and O(n) space.
namespace lintcode
{
    // 1. for each position i in nums, find the max sub array sum from 0 to i and save in an auxiliary array "LeftMax"
    // 2. find the min sub array sum from n-1 to i and save in in an auxiliary array "rightMin"
    // 3. compute the max value as max1 = max of (LeftMax[i] - rightMin[i]) for i in [0, n);
    // 4. do these two steps reversely, find the rightMax sub array sum and leftMin sub array sum, 
    //      compute max2 = max of (rightMax[i]- leftMin[i]) for i in [0,n).
    // 5. return the max of (max1, max2)
    int maxDiffSubArrays(vector<int>& A)
    {
        if (A.empty())
            return 0;

        int n = A.size();

        vector<int> leftMaxSum(n);
        vector<int> leftMinSum(n);

        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currentMax = 0;
        int currentMin = 0;
        for (int i = 0; i < n; i++)
        {
            currentMax += A[i];
            maxSum = max(maxSum, currentMax);
            leftMaxSum[i] = maxSum;
            if (currentMax < 0)
                currentMax = 0;

            currentMin += A[i];
            minSum = min(minSum, currentMin);
            leftMinSum[i] = minSum;
            if (currentMin > 0)
                currentMin = 0;
        }

        currentMax = 0;
        currentMin = 0;
        maxSum = INT_MIN;
        minSum = INT_MAX;
        vector<int> rightMaxSum(n);
        vector<int> rightMinSum(n);
        for (int i = n - 1; i >= 0; i--)
        {
            currentMax += A[i];
            maxSum = max(maxSum, currentMax);
            rightMaxSum[i] = maxSum;
            if (currentMax < 0)
                currentMax = 0;

            currentMin += A[i];
            minSum = min(minSum, currentMin);
            rightMinSum[i] = minSum;
            if (currentMin > 0)
                currentMin = 0;
        }

        int max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            max1 = max(max1, abs(leftMaxSum[i] - rightMinSum[i + 1]));
        }

        for (int i = n - 1; i > 0; i--)
        {
            max2 = max(max2, abs(rightMaxSum[i] - leftMinSum[i - 1]));
        }

        return max(max1, max2);
    }
}