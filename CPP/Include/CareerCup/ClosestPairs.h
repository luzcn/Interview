#pragma once
#include "stdafx.h"

// Given a set of points, find a pair of points that the distance is smallest.
// The brute force solution is O(n^2).
// The divide conqure solution should be O(nlogn).
// http://www.geeksforgeeks.org/closest-pair-of-points/
namespace careercup
{
    // helper function
    float getDistance(const Point& p1, const Point& p2)
    {
        return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    }

    // brute force solution
    float closestPairBruteForce(const vector<Point>& p, int size)
    {
        if (size <= 0)
            return 0;

        float res = numeric_limits<float>::max();
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                auto dis = getDistance(p[i], p[j]);
                if (dis < res)
                {
                    res = dis;
                }
            }
        }

        return res;
    }

    // A helper function to find the distance beween the closest points of
    // strip of given size. 
    //
    // All points in strip[] are sorted accordint to y coordinate. 
    // They all have an upper bound on minimum distance as d.
    // 
    // Note that this method seems to be a O(n^2) method, but it's a O(n)
    // method as the inner loop runs at most 6 times
    float stripClosest(vector<Point>& strip, float d)
    {
        auto minDistance = d;
        std::sort(strip.begin(), strip.end(), [&](const Point& p1, const Point& p2){ return p1.y >= p2.y; });
        for (int i = 0; i < strip.size() - 1; i++)
        {
            for (int j = i + 1; j < strip.size(); j++)
            {
                auto dis = getDistance(strip[i], strip[j]);
                if (dis < minDistance)
                    minDistance = dis;
            }
        }

        return minDistance;
    }

    // Divide-Conquer solution
    float closestPairRec(const vector<Point>& p, int l, int r)
    {
        int n = r - l;
        if (n <= 3)
            return closestPairBruteForce(p, n);

        int mid = l + (r - l) / 2;
        auto dl = closestPairRec(p, l, mid);
        auto dr = closestPairRec(p, mid + 1, r);

        auto d = min(dl, dr);

        vector<Point> strip;
        auto midPoint = p[mid];
        for (int i = 0; i <= n; i++)
        {
            if (p[i].x <= d)
                strip.push_back(p[i]);
        }

        return min(d, stripClosest(strip, d));
    }

    float closestPair(const vector<Point>& p)
    {
        //return closestPairBruteForce(p, p.size());
        return closestPairRec(p, 0, p.size() - 1);
    }
}