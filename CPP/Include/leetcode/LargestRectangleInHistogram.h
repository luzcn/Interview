#pragma once
#include "stdafx.h"

// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
// find the area of largest rectangle in the histogram. 
namespace leetcode
{
    // for each bar, extends in left and right two directions, 
    // keep increasing the index if found a larger height, stops if smaller.

    // for example:
    // input:   2 1 5 6 2 3
    // left:    0 5 3 3 5 5
    // right:   0 0 2 3 2 5
    // the area = height[i]*(abs(left[i] - right[i]) + 1) 

    // The problem is how to compute these two left/right array?
    // brute force takes O(n^2) time
    // we can use a stack to save the left bound of each height

    // if the stack is empty, push in the current index
    // if the stack top is larger than the current height[i], pop the stack.
    // repeat the previous steps, until either stack is empty (the left[i] is i)
    //  or top is smaller than current height the (left[i] is i - top)

    // similar  to compute the right array

    int largestRectangleArea(vector<int>& heights) 
    {
        if (heights.empty())
            return 0;

        stack<int> st;  // the index
        int n = heights.size();

        vector<int> leftDistance(n, 0);
        vector<int> rightDistance(n, 0);

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                leftDistance[i] = i;
            }
            else
            {
                leftDistance[i] = i - st.top() - 1;
            }

            st.push(i);
        }

        // clear the stack
        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                rightDistance[i] = (n - 1) - i;
            }
            else
            {
                rightDistance[i] = st.top() - i - 1;
            }

            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (leftDistance[i] + rightDistance[i] + 1));
        }

        return maxArea;
    }

    // An elegant solution, no need to scan twice and O(1) space
    //int largestRectangleArea2(vector<int>& heights)
    //{
    //    if (heights.empty())
    //        return 0;

    //    int maxArea = 0;
    //    stack<int> st;

    //    int i = 0;

    //    while (i < heights.size())
    //    {
    //        if (st.empty() || heights[st.top()] <= heights[i])
    //        {
    //            st.push(i);
    //            i++;
    //        }
    //        else
    //        {
    //            // the previous smaller height
    //            int t = heights[st.top()];
    //            maxArea = max(maxArea, t * (i - st.top() + 1));
    //            st.pop();
    //        }
    //    }


    //    return maxArea;
    //}
}