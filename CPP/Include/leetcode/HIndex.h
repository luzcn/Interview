#pragma once
#include "stdafx.h"
#include <functional>

//  Given an array of citations(each citation is a non - negative integer) of a researcher, 
// write a function to compute the researcher's h-index.
//
// According to the definition of h - index on Wikipedia : 
//  "A scientist has index h if h of his/her N papers have at least h citations each, 
//   and the other N ? h papers have no more than h citations each."
//
// For example, given citations = [3, 0, 6, 1, 5], 
// which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
// 
//  Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, 
//  his h - index is 3.
//
//Note : If there are several possible values for h, the maximum one is taken as the h - index.
namespace leetcode
{
    // f = [3,0,6,1,5] 
    // 1. sort in decreasing order
    // 2. for each i in 0... n, we have citation f(i) and papters i + 1, 
    //  find max of (min(f(i), i+1)) for each i.
    // https://en.wikipedia.org/wiki/H-index
    int hIndex(vector<int>& citations)
    {
        if (citations.empty())
            return 0;

        std::sort(citations.begin(), citations.end(), std::greater<int>());

        int h = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            h = max(h, min(citations[i], i + 1));
            if (h < i + 1)
                break;
        }

        return h;
    }

    // the input is ascending ordered.
    // find in O(logn)
    int hIndex(vector<int>& citations)
    {
        if (citations.empty())
            return 0;

        int n = citations.size();
        int low = 0;
        int high = citations.size() - 1;

        while (low + 1 < high)
        {
            int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid)
            {
                return citations[mid];
            }
            else if (citations[mid] < n - mid)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        if (citations[low] >= n - low)
            return n - low;

        if (citations[high] >= n - high)
            return n - high;

        return 0;
    }
}