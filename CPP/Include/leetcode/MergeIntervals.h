#pragma once
#include "stdafx.h"

//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].
namespace leetcode
{
    struct Interval
    {
        int start;
        int end;

        Interval()
            :start(0), end(0)
        {}

        Interval(int s, int e)
            :start(s), end(e)
        {}
    };

    vector<Interval> merge(vector<Interval>& intervals)
    {
        if (intervals.empty())
            return{};

        vector<Interval> res;
        std::sort(intervals.begin(), intervals.end(), [&](Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        });

        auto first = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            auto second = intervals[i];
            if (first.start <= second.end && second.start <= first.end)
            {
                first.start = min(first.start, second.start);
                first.end = max(first.end, second.end);
            }
            else
            {
                res.push_back(first);
                first = second;
            }
        }
        res.push_back(first);
        return res;
    }
}