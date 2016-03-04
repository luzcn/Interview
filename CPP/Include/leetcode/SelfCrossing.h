#pragma once
#include "stdafx.h"
//You are given an array x of n positive numbers.
//You start at point(0, 0) and moves x[0] metres to the north, 
//then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on.
//
//In other words, after each move your direction changes counter - clockwise.
//
//Write a one - pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
namespace leetcode
{
    bool isSelfCrossing(vector<int>& x)
    {
        if (x.size() < 4)
            return false;

        int previousDistance = 0;
        int t1 = x[0];
        int t2 = x[1];
        int t3 = x[2];
        int t4 = 0;


        for (int i = 3; i < x.size(); i++)
        {
            t4 = x[i];

            // check if it is increasing 
            bool increase = false;
            if (t3 > t1)
                increase = true;

            if (increase && t2 >= t4) 
            {
                // start to decrease
                if (t4 + previousDistance < t2 || (i < x.size() - 1) && x[i+1] < t3 - t1)
                {
                    increase = false;
                }
                else if (i < x.size() - 1)
                {
                    // t4 >= t2- prev && x[i+1] >= t3-1, we can guarantee it is corssing
                    return true;
                }
            }
            else if (!increase && t4 >= t2)
            {
                // if it is decreasing, and suddently trying to increase, 
                // absolutely it is crossing
                return true;
            }

            // rotation to next round 
            previousDistance = t1;
            t1 = t2;
            t2 = t3;
            t3 = t4;
        }
        return false;
    }
}