#pragma once

#include "stdafx.h"
#include <unordered_map>
#include <limits>

struct Point
{
    int x;
    int y;

    Point()
        :x(0), y(0)
    {}

    Point(int a, int b)
        :x(a), y(b)
    {}
};
namespace MaxPointsOnLine
{
    /***
     *	Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
     *  
     *  If two points(x1,y1) (x2,y2) are on the same line(Of course).
     *  Consider the gap between two points.
     *  
     *  We have (y2-y1)=a(x2-x1),a=(y2-y1)/(x2-x1) a is a rational, b is canceled since b is a constant
     *  If a third point (x3,y3) are on the same line. So we must have y3=ax3+b
     *  
     *  Thus,(y3-y1)/(x3-x1)=(y2-y1)/(x2-x1)=a
     *  Since a is a rational, there exists y0 and x0, y0/x0=(y3-y1)/(x3-x1)=(y2-y1)/(x2-x1)=a
     *  So we can use y0&x0 to track a line;
     *
     *  http://www.cnblogs.com/TenosDoIt/p/3444086.html
     */

    int maxPoints(vector<Point> &points)
    {
        using hash_map = std::unordered_map < double, int >;

        if (points.empty())
        {
            return 0;
        }

        int result = 0;
        int n = points.size();
        hash_map map;

        for (int i = 0; i < n; i++)
        {
            map.clear();
            int duplicate = 0;
            int current_max = 1;

            for (int j = i + 1; j < n; j++)
            {
                auto p1 = points[i];
                auto p2 = points[j];
                // init the slope to infinity.
                double slope = std::numeric_limits<double>::infinity();

                if (p1.x != p2.x)
                {
                    double dx = p1.x - p2.x;
                    double dy = p1.y - p2.y;

                    slope = dy / dx;
                }
                else if (p1.y == p2.y) // find duplicate points.
                {
                    duplicate++;
                    continue;
                }

                map[slope]++;
                current_max = max(current_max, map[slope] + 1);
            }
            result = max(result, current_max + duplicate);
        }
        return result;
    }
}
