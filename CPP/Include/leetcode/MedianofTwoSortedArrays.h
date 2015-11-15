#pragma once
#include "stdafx.h"

//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
// http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
namespace leetcode
{
    int getMedian(int A[], int m, int B[], int n, int k)
    {
        // assert(a && b);   
        if (m <= 0) return B[k - 1];
        if (n <= 0) return A[k - 1];
        if (k <= 1) return min(A[0], B[0]);

        if (m / 2 + n / 2 + 1 >= k)
        {
            if (A[m / 2] >= B[n / 2])
            {
                // drop section 2
                return getMedian(A, m / 2, B, n, k);
            }
            else
            {
                // drop section 4
                return  getMedian(A, m, B, n / 2, k);
            }
        }
        else
        {
            if (A[m / 2] >= B[n / 2])
            {
                // drop section 3
                return getMedian(A, m, B + (n / 2 + 1), n - (n / 2 + 1), k - (n / 2 + 1));
            }
            else
            {
                // discard section 1
                return getMedian(A + (m / 2 + 1), m - (m / 2 + 1), B, n, k - (m / 2 + 1));
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        if ((m + n) % 2 == 0)
        {
            auto t1 = getMedian(nums1.data(), m, nums2.data(), n, (m + n) / 2);
            auto t2 = getMedian(nums1.data(), m, nums2.data(), n, (m + n) / 2 + 1);

            return (t1 + t2) / 2.0;
        }
        else
        {
            return getMedian(nums1.data(), m, nums2.data(), n, (m + n) / 2 + 1);
        }
    }

}