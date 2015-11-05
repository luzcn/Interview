#pragma once
#include "stdafx.h"

namespace leetcode
{
    struct Point
    {
        int x, y;
        Point(int v1, int v2)
            :x(v1), y(v2)
        {}
    };

    // helper function
    // return true of (l1,r2) and (l2, r2) overlap
    bool isOverlap(Point l1, Point r1, Point l2, Point r2)
    {
        // one rectangle is on left side of another one
        if (r1.x < l2.x || r2.x < l1.x)
            return false;

        // one rectangle is on top side of another one
        if (r2.y < l1.y || r1.y < l2.y)
            return false;

        return true;
    }

    // Find the total area covered by two rectilinear rectangles in a 2D plane.
    // Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
    // Rectangle Area
    // Assume that the total area is never beyond the maximum possible value of int.
    // (A,B) is the left bottom point of rectangle1, (C, D) is the right top point of rectangle1.
    // (E,F) is the left bottom point of rectangle2, (G, H) is the right top point of rectangle2.
    int computeOverlapArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        Point l1(A, B);
        Point r1(C, D);
        Point l2(E, F);
        Point r2(G, H);

        if (!isOverlap(l1, r1, l2, r2))
        {
            return 0;
        }

        int leftMax = max(l1.x, l2.x);
        int rightMax = min(r1.x, r2.x);
        int bottomMax = max(l1.y, l2.y);
        int topMax = min(r1.y, r2.y);
                
        return (rightMax - leftMax)*(topMax-bottomMax); 
    }
}