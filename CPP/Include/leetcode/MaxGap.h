#pragma once
#include "stdafx.h"

//Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
//Try to solve it in linear time / space.
//
//Return 0 if the array contains less than 2 elements.
//
//You may assume all elements in the array are non - negative integers and fit in the 32 - bit signed integer range.
namespace leetcode
{
    // Thought:
    // Assume there are N elements, we can find max and min element in O(n) time.
    // There are N-1 difference values, so construct N buckets, each bucket has interval = (max-min) / (N-1).
    // For each element nums[i], map to the corresponding bucket by computing the loc = (nums[i]- min)/interval.

    struct Bucket
    {
        int low, high;
        Bucket()
            :low(-1), high(-1), size(0)
        {}

        void put(int val)
        {
            if (size == 0)
            {
                low = val;
                high = val;
            }
            else
            {
                low = min(low, val);
                high = max(high, val);
            }
            size++;
        }

        int size;
    };
    int maximumGap(vector<int>& nums)
    {
        if (nums.size() < 2)
            return 0;

        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        double interval = (double) (maxValue - minValue) / (nums.size() - 1);
        if (interval == 0)
            return maxValue - minValue;

        vector<Bucket> buckets(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            int pos = (nums[i] - minValue) / interval;
            buckets[pos].put(nums[i]);
        }

        int i = buckets.size() - 1;
        while (i >= 0 && buckets.size() == 0)
        {
            i--;
        }

        int maxGap = buckets[i].high - buckets[i].low;
        int gap = 0;
        int j = i - 1;
        while (j >= 0)
        {
            if (buckets[j].size != 0)
            {
                gap = buckets[i].low - buckets[j].high;
                maxGap = max(maxGap, gap);
                i = j;
            }
            j--;
        }

        return maxGap;
    }
}
