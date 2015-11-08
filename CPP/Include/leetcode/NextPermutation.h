#pragma once
#include "stdafx.h"

//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left hand column and its corresponding outputs are in the right hand column.
//1, 2, 3 ? 1, 3, 2
//3, 2, 1 ? 1, 2, 3
//1, 1, 5 ? 1, 5, 1

namespace leetcode
{
    void swap(vector<int>& nums, int i, int j)
    {
        auto t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return;

        if (nums[nums.size() - 1] > nums[nums.size() - 2])
        {
            swap(nums, nums.size() - 1, nums.size() - 2);
            return;
        }

        int i = nums.size() - 2;
        for (i = nums.size() - 2; i > 0; i--)
        {
            // find the first element that larger than both left and right elemnts.
            if (nums[i] >= nums[i + 1] && nums[i] > nums[i - 1])
            {
                auto leftValue = nums[i - 1];
                int index = i;
                // in the right side of this element, find the smallest but larger than left element.
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] < nums[index] && nums[j] > leftValue)
                    {
                        index = j;
                    }
                }
                swap(nums, i - 1, index);
                break;
            }
        }

        // sort the rest.
        std::sort(nums.begin() + i, nums.end());
    }
}