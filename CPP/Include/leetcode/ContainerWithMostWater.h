#pragma once
#include "stdafx.h"

// Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
// Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container.
namespace leetcode
{
    // brute force solution O(n^2)
    int maxAreaBF(vector<int>& height)
    {
        int max_area = 0;

        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                max_area = max(max_area, min(height[i], height[j])* (j - i));
            }
        }

        return max_area;
    }

    // https://leetcode.com/discuss/37631/simple-and-clear-proof-explanation
    int maxArea(vector<int>& height)
    {
        if (height.size() <= 1)
            return 0;

        int max_area = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            int current_area = (j - i)*min(height[i], height[j]);
            max_area = max(max_area, current_area);

            if (height[i] >= height[j])
                j--;
            else
                i++;
        }

        return max_area;
    }
}