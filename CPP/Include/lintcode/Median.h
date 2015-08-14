#pragma once
#include "stdafx.h"

//Given a unsorted array with integers, find the median of it.
//A median is the middle number of the array after it is sorted.
//
//If there are even numbers in the array, return the N / 2 - th number after sorted.
//Have you met this question in a real interview ?
//Example
//
//Given[4, 5, 1, 2, 3], return 3
//Given[7, 9, 4, 5], return 5
//
//O(n) time.

namespace lintcode
{
    void swap(vector<int>& nums, int i, int j)
    {
        if (i != j)
        {
            auto t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }

    int topKth(vector<int> &nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];

        // partition
        auto m = partition(nums, l, r);

        if (m + 1 == k)
            return nums[m];
        else if (m + 1 < k)
        {
            return topKth(nums, m + 1, r, k);
        }
        else
            return topKth(nums, l, m - 1, k);
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int m = l - 1;
        int pivot = nums[r];
        for (int i = l; i < r; i++)
        {
            if (nums[i] < pivot)
            {
                m++;
                swap(nums, m, i);
            }
        }
        m++;
        swap(nums, m, r);
        return m;
    }

    int median(vector<int> &nums)
    {
        // write your code here
        int n = nums.size();
        if (n % 2 == 0)
            return topKth(nums, 0, n - 1, n / 2);
        else
            return topKth(nums, 0, n - 1, n / 2 + 1);
    }
}
