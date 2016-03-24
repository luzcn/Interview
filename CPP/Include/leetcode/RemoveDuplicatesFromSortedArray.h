#pragma once
#include "stdafx.h"

 //Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 //Do not allocate extra space for another array, you must do this in place with constant memory.

 //For example,
 //Given input array A = [1,1,2],

 //Your function should return length = 2, and A is now [1,2].
namespace leetcode
{
    int removeDuplicates(int A[], int n)
    {
        if (n <= 1)
            return n;

        int start = 0;
        int end = 1;

        while (end < n)
        {
            if (A[start] != A[end])
            {
                start++;
                A[start] = A[end];
            }
            end++;
        }

        return start + 1;
    }

    // Follow up for "Remove Duplicates":
    //   What if duplicates are allowed at most twice?

    //   For example,
    //   Given sorted array A = [1,1,1,2,2,3],

    //   Your function should return length = 5, and A is now [1,1,2,2,3]. 
    int removeDuplicates2(vector<int>& nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }

        int start = 0;
        int end = 1;
        int count = 0;

        while (end < nums.size())
        {
            if (nums[start] == nums[end])
            {
                if (++count < 2)
                {
                    start++;
                    nums[start] = nums[end];    // here, we also need to copy 
                }
            }
            else
            {
                start++;
                nums[start] = nums[end];
                count = 0;
            }
            end++;
        }

        return start + 1;
    }
}