#pragma once
#include "stdafx.h"

namespace careercup
{
    // Given an array of integer, determine if it is a binary search tree post order result.
    // 5,7,6,9,11,10,8 is a valid result
    bool verifyRec(vector<int>& v, int l, int r)
    {
        if (l >= r)
            return true;

        // the last element is the root element of each subtree.
        int root = v[r];
        int i = l;

        // find the first part, which are less than the root value
        while (i < r && v[i] < root)
        {
            i++;
        }

        // The second part should be all the value that are greater than the root.
        int j = i;
        while (j < r)
        {
            if (v[j] < root)
                return false;
            j++;
        }
        bool left = true;
        bool right = true;

        left = verifyRec(v, l, i - 1);
        right = verifyRec(v, i, r - 1);

        return left && right;
    }


    bool verify(vector<int>& v)
    {
        if (v.empty())
            return false;

        return verifyRec(v, 0, v.size() - 1);
    }
}