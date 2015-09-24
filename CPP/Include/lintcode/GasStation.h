#pragma once
#include "stdafx.h"

//  There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).
//  You begin the journey with an empty tank at one of the gas stations.
//
//  Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.
//
//  O(n) time and O(1) extra space


namespace lintcode
{
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int tank = 0;
        int n = gas.size();

        // find the first position which has enough gas, gas[i]>=cost[i]
        while (start < n && gas[start] < cost[start])
        {
            start++;
        }
        if (start == n)
            return -1;

        tank = gas[start] - cost[start];
        int end = start + 1;

        while (end % n != start)
        {
            tank = tank + gas[end%n] - cost[end%n];
            if (tank >= 0)
            {
                end++;
            }
            else
            {
                start++;
                while (start < n && gas[start] < cost[start])
                {
                    start++;
                }

                // no solution.
                if (start == n)
                    return -1;

                end = start + 1;
                tank = gas[start] - cost[start];
            }
        }

        return start;
    }
}