#pragma once

#include "stdafx.h"
#include <algorithm>

/**
 *	Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 Find the minimum element.

 You may assume no duplicate exists in the array.
 */
namespace FindMinimuminRotatedSortedArray
{
    /**
     *	Thought,
     */
    int findMin(vector<int> &num)
    {
        if (num.empty())
        {
            return 0;
        }

        int l = 0;
        int r = num.size() - 1;

        while (l != r)
        {
            int m = l + (r - l) / 2;

            // if not rotated
            if (num[l] < num[r])
            {
                return num[l];
            }
            else
            {
                // num[l] < num[r] && num[m] > num[r], search [m, r]
                if (num[m] > num[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
        }

        return num[r];
    }

    int findMinDuplicate(vector<int> &A)
    {
        return *std::min_element(A.begin(), A.end());
    }
}