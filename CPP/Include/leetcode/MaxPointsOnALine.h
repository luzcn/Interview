#pragma once

#include "stdafx.h"
#include <unordered_map>
#include <limits>

namespace leetcode
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
    int maxPoints(vector<Point>& points)
    {
        std::unordered_map<double, int> map;
        int res = 0;
        int n = points.size();
        double inf = std::numeric_limits<double>::infinity();

        for (int i = 0; i < n; i++)
        {
            map.clear();
            int dup = 0;
            int current_max = 1;
            auto p1 = points[i];
            for (int j = i + 1; j < n; j++)
            {
                auto p2 = points[j];
                if (p1.x != p2.x)
                {
                    double dx = p1.x - p2.x;
                    double dy = p1.y - p2.y;
                    double slope = dy / dx;
                    if (map.find(slope) == map.end())
                        map.emplace(slope, 2);
                    else
                        map[slope]++;

                    current_max = std::max(current_max, map[slope]);
                }
                else if (p1.y != p2.y)
                {
                    // the slope is infinity
                    if (map.find(inf) == map.end())
                        map.emplace(inf, 2);
                    else
                        map[inf]++;

                    current_max = std::max(current_max, map[inf]);
                }
                else
                {
                    // duplicate points
                    dup++;
                }
            }
            res = std::max(res, current_max + dup);
        }

        return res;
    }

}
