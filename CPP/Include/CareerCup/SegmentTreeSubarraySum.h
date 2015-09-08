#pragma once
#include "stdafx.h"

// using segment tree to compute the sub array sum.
namespace careercup
{
    int constructRec(vector<int>& arr, int start, int end, vector<int>& res, int i)
    {
        //if (start > end)
        //    return 0;

        if (start == end)
        {
            res[i] = arr[start];
            return arr[start];
        }

        int mid = start + (end - start) / 2;
        // construct the internal nodes as sum of leaf nodes.
        res[i] = constructRec(arr, start, mid, res, 2 * i + 1) + constructRec(arr, mid + 1, end, res, 2 * i + 2);

        return res[i];
    }

    // construct a segment tree by using array.
    // for each node at index i, the parent node is (i-1)/2, left child is 2*i-1, right child is 2*i+2
    vector<int> constructSegmentTree(vector<int>& arr)
    {
        if (arr.empty())
            return{};

        vector<int> segment(2 * arr.size() + 1, 0);

        constructRec(arr, 0, arr.size() - 1, segment, 0);

        return segment;
    }



    int getSubArraySumRec(vector<int>& segment, int query_start, int query_end, int range_start, int range_end, int i)
    {
        // if the current node range is part of the query range, return this value.
        if (range_start >= query_start && range_end <= query_end)
            return segment[i];

        if (query_end < range_start || query_start>range_end)
            return 0;

        int mid = range_start + (range_end - range_start) / 2;

        return getSubArraySumRec(segment, query_start, query_end, range_start, mid, 2 * i + 1)
            + getSubArraySumRec(segment, query_start, query_end, mid + 1, range_end, 2 * i + 2);
    }

    // compute the sub array sum.
    // query_start: the subarray start index
    // query_end: the subarray end index
    // segment: the segment tree 
    // size: the input array size
    int getSubArraySum(vector<int>& segment, int query_start, int query_end, int size)
    {
        return getSubArraySumRec(segment, query_start, query_end, 0, size - 1, 0);
    }
}