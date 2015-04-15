#pragma once
#include "stdafx.h"

namespace FindPeakElement
{
    int findPeakElement(const vector<int> &num)
    {
        int n = num.size();
        // check first element & last element
        if (n == 1 || num[0] > num[1]) {
            return 0;
        }
        else if (num[n - 1] > num[n - 2]) {
            return n - 1;
        }

        // Binary search O(log(n))            
        int l = 1;
        int r = num.size() - 2;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) 
            {
                return mid;
            }
            else if (num[mid] < num[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
}
