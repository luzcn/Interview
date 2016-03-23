#pragma once
#include "stdafx.h"

// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 
// with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem. 
namespace leetcode
{
    class Solution
    {
    public:
        void sortColors(vector<int>& nums)
        {
            if (nums.empty())
                return;

            int head = 0;
            int tail = nums.size() - 1;
            int p = head;

            while (p <= tail)
            {
                switch (nums[p])
                {
                case 0:
                    swap(nums, head, p);
                    head++;
                    p++;
                    break;
                case 2:
                    swap(nums, p, tail);
                    tail--;
                    break;
                default:
                    p++;
                    break;
                }
            }

        }
    private:
        void swap(vector<int>& A, int i, int j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    };
}

