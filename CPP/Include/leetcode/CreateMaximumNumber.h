#pragma once
#include "stdafx.h"
// Given two arrays of length m and n with digits 0 - 9 representing two numbers.
// Create the maximum number of length k <= m + n from digits of the two.
// The relative order of the digits from the same array must be preserved.Return an array of the k digits.You should try to optimize your time and space complexity.
//
//  Example 1:
//
//  nums1 = [3, 4, 6, 5]
//  nums2 = [9, 1, 2, 5, 8, 3]
//  k = 5
//  return[9, 8, 6, 5, 3]
//
// First, start from creating the max number with length k from a single array.
// it is similar to largest number problem, except needs to preserve the didit order.
// 1. use stack to store the digits
// 2. for each element in the array:
//    - keep pop the top element from the stack, if the stack is not empty, the top is less than nums[i], 
//    and there are enough digits left in the array.
//    - push the nums[i] into the stack.
namespace leetcode
{
    // create the max number with length k from a single array
    vector<int> createMaxNum(vector<int>& nums, int k)
    {
        if (k <= 0)
            return{};

        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!result.empty() && result.back() < nums[i] && (result.size() - 1 + nums.size() - i) >= k)
            {
                result.pop_back();
            }

            if (result.size() < k)
            {
                result.push_back(nums[i]);
            }
        }

        return result;
    }

    // True if nums1 >= nums2
    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j)
    {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
        {
            i++;
            j++;
        }

        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.empty())
            return nums2;

        if (nums2.empty())
            return nums1;

        int i = 0;
        int j = 0;
        vector<int> result;

        while (i + j < nums1.size() + nums2.size())
        {
            if (greater(nums1, i, nums2, j))
            {
                result.push_back(nums1[i++]);
            }
            else
            {
                result.push_back(nums2[j++]);
            }
        }

        return result;
    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result;

        for (int i = max(0, k - n); i <= k && i <= m; i++)
        {
            vector<int> max1 = createMaxNum(nums1, i);
            vector<int> max2 = createMaxNum(nums2, k - i);
            vector<int> candidate = merge(max1, max2);
            if (greater(candidate, 0, result, 0))
                result = candidate;
        }

        return result;
    }
}