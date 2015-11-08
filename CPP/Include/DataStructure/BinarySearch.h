#pragma once
#include "stdafx.h"

class BinarySearch
{
public:
    bool binary_search(std::vector<int> sl, int target)
    {
        if (sl.empty())
            return false;
        if (target == sl[0] || target == sl[sl.size() - 1])
        {
            return true;
        }
        return binary_search_recursive(sl, 0, sl.size() - 1, target);
    }

private:
    /// <summary>
    ///  The recursive binary search solution
    /// </summary>
    /// <param name="sl"> The input sorted array </param>
    /// <param name="left"> The left point of search range </param>
    /// <param name="right"> The right point of search range </param>
    /// <param name="target"> The searching target </param>
    /// <returns> True if found. </return>
    bool binary_search_recursive(std::vector<int> sl, int left, int right, int target)
    {
        if (right <= left)
            return false;

        int middle = (right - left) / 2;
        if (target == sl[middle])
            return true;
        else if (target < sl[middle])
            binary_search_recursive(sl, left, middle - 1, target);
        else
            binary_search_recursive(sl, middle + 1, right, target);
    }

    /// <summary>
    ///  The non-recursive binary search solution
    /// </summary>
    /// <param name="sl"> The input sorted array </param>
    /// <param name="left"> The left point of search range </param>
    /// <param name="right"> The right point of search range </param>
    /// <param name="target"> The searching target </param>
    /// <returns> True if found. </return>
    bool binary_search_nonrecursive(std::vector<int> sl, int left, int right, int target)
    {
        while (right >= left)
        {
            int middle = (right - left) / 2;
            if (target == sl[middle])
                return true;
            else if (target < sl[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        return false;
    }
};