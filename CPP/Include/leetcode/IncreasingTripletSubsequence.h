#pragma once
#include "stdafx.h"

//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should :
//
//Return true if there exists i, j, k
//such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n - 1 else return false.
//
//    Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//    Examples :
//    Given[1, 2, 3, 4, 5],
//    return true.
//
//    Given[5, 4, 3, 2, 1],
//    return false.
namespace leetcode
{
    bool increasingTriplet(vector<int>& nums)
    {
        if (nums.empty())
            return false;

        int n = nums.size();
        vector<int> leftSmaller(n, 0);
        vector<int> rightLarger(n, 0);

        // find the left side smaller
        leftSmaller[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < leftSmaller[i - 1])
            {
                leftSmaller[i] = nums[i];
            }
            else
            {
                leftSmaller[i] = leftSmaller[i - 1];
            }
        }

        // find the right side smaller
        rightLarger[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > rightLarger[i + 1])
            {
                rightLarger[i] = nums[i];
            }
            else
            {
                rightLarger[i] = rightLarger[i + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > leftSmaller[i] && nums[i] < rightLarger[i])
                return true;
        }

        return false;
    }

    // using c++ lower_bound
    bool increasingTriplet2(vector<int>& nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }

        vector<int> inc;

        for (int i = 0; i < nums.size(); i++)
        {
            if (inc.size() >= 3)
                return true;

            int pos = lower_bound(inc.begin(), inc.end(), nums[i]) - inc.begin();
            if (pos == inc.size())
                inc.push_back(nums[i]);
            else
                inc[pos] = nums[i];
        }

        return inc.size() >= 3;
    }
}