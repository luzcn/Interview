#pragma once
#include "stdafx.h"

namespace leetcode
{
    struct Interval
    {
        int start, end;
        Interval()
            :start(0), end(0)
        {}

        Interval(int s, int e)
            :start(s), end(e)
        {}
    };
    // Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), 
    // determine if a person could attend all meetings.
    // For example,
    //  Given[[0, 30], [5, 10], [15, 20]],
    //  return false.
    // 
    //   Activity schedule problem, sort the intervals by finish time
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        if (intervals.size() <= 1)
            return true;

        // sort by end time
        std::sort(intervals.begin(), intervals.end(), [&](const Interval& i1, const Interval& i2) {
            return i1.end < i2.end;
        });

        auto current = intervals[0];
        //vector<Interval> meetingsCanAtttend{ current };

        for (int i = 1; i < intervals.size(); i++)
        {
            auto temp = intervals[i];
            // temp interval start time larger or equal than current finish time
            // this meeting can attend.
            if (temp.start < current.end)
            {
                //meetingsCanAtttend.push_back(temp);
                return false;
            }
        }

        return true;

    }

    // Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), 
    // find the minimum number of conference rooms required.
    //  For example,
    //    Given[[0, 30], [5, 10], [15, 20]],
    //    return 2.
    //    [[2,15],[36,45],[9,29],[16,23],[4,9]] => {[4,9],[9,29],[36,45]}, {[2,15], [16,23]}
    //  Thought: find the maximun number of overlap interverl .
    int minMeetingRooms(vector<Interval>& intervals)
    {
        if (intervals.size() <= 1)
            return 1;

        int n = intervals.size();
        vector<int> startList;
        vector<int> endList;

        for (auto i : intervals)
        {
            startList.push_back(i.start);
            endList.push_back(i.end);
        }

        std::sort(startList.begin(), startList.end());
        std::sort(endList.begin(), endList.end());

        int overlap = 0;
        int maxOverlap = 0;

        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (startList[i] < endList[j])
            {
                overlap++;
                i++;
            }
            else
            {
                overlap--;
                j++;
            }
            maxOverlap = max(maxOverlap, overlap);
        }

        return maxOverlap;
    }
}