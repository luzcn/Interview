#pragma once
#include "stdafx.h"

//Given an unsorted array nums, reorder it in - place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is[1, 6, 2, 5, 3, 4].
namespace leetcode
{
    // sort then swap, O(nlogn)
    void wiggleSort(vector<int>& nums)
    {
        if (nums.size() < 2)
            return;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size() - 1; i = i + 2)
        {
            // swap i and i+1
            int temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
        }
    }

    // O(n) solution
    void wiggleSort2(vector<int>& nums)
    {
        if (nums.size() < 2)
            return;

        bool increase = true;

        for (int i = 1; i < nums.size(); i++)
        {
            if ((increase && nums[i] < nums[i - 1])
                || (!increase && nums[i - 1] < nums[i]))
            {
                // swap
                int temp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = temp;

            }
            increase = !increase;
        }
    }

    // follow up 1: the constratins changed to nums[0] < nums[1] > nums[2] ...
    // no contiguous equavelent number
    // the problem is you cannot guarantee there is always a solution.
    void wiggleSortII(vector<int>& nums)
    {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        //for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
        //{
        //    nums[i] = sorted[i & 1 ? k++ : j++];
        //}

        int s = (nums.size() + 1) / 2;
        int k = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if ((i & 1) == 0)
            {
                nums[i] = sorted[--s];
            }
            else
            {
                nums[i] = sorted[--k];
            }
        }
    }


    // follow up2,
    // given an unsorted array and one array contains only 0 and 1 used to indicate increasing or decreasing.
    // reorder the given array in place based on the second array.
    // for example: given nums = [3, 5, 2, 1, 6, 4], 
    // and the second array orders=[0,0,1,1,1] indicating nums[0] >= nums[1] >= nums[2] <= nums[3] <= nums[4] <= nums[5], 
    // one solution is [6,4,1,2,3,5]
    void wiggleSort4(vector<int>& nums, vector<int>& orders)
    {
        if (nums.size() < 2)
            return;

        if (orders.size() < nums.size() - 1)
            return;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if ((orders[i] == 0 && nums[i] < nums[i + 1])
                || (orders[i] == 1 && nums[i] > nums[i+1]))
            {
                // swap
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
    }
}