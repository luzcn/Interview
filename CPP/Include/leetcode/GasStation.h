#pragma once

#include "stdafx.h"

namespace GasStation
{

    /// <summary>
    ///   There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
    ///   You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i + 1).
    ///   
    ///   You begin the journey with an empty tank at one of the gas stations.
    ///   Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
    ///   
    ///   Note: The solution is guaranteed to be unique.
    ///   
    ///   Solution:
    ///   The idea is if we start at any ith station, where ith station has positive gas-cost,and we fail at kth station(total gas < 0), 
    ///   starting from any station between ith and kth will not be possible. 
    ///   
    ///   Thus, when we fail at k, next time we try to start at a station after k, where the station has positive gas-cost, and see if we can finish the circuit from there. 
    ///   If at the end of the gas/cost array the gas - cost value is still negative or starting at the end of the array is still not a valid solution, we return -1;
    ///   
    /// </summary>
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        size_t n = gas.size();

        size_t start = 0;
        size_t end = 0;
        int tank = 0;

        // Find first valid starting position.
        while (start < n && gas[start] - cost[start] < 0)
        {
            start++;
        }
        if (start >= n)
            return -1;

        tank = gas[start] - cost[start];
        end = start + 1;

        while (end%n != start && start < n)
        {
            tank += gas[end%n] - cost[end%n];
            if (tank < 0) // not valid path
            {
                // find another valid starting position.
                start = end + 1;
                while (start < n && gas[start] - cost[start] < 0)
                {
                    start++;
                }
                if (start >= n)
                    return -1;

                // reset the tank.
                tank = gas[start] - cost[start];
                end = start + 1;
            }
            else
            {
                end++;
            }
        }
        return start < n ? start : -1;
    }
}