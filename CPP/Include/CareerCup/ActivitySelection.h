#pragma once
#include "stdafx.h"

namespace careercup
{
    // Activity selection problem
    struct Activity
    {
        int start;
        int finish;
    };

    // Greedy, the earlist finished activity is always included in some optimal solution
    // The proof is simple: 
    // Assume a0 is the earlist finished activity in the total input set,
    // OPT is the optimal solution,
    // a1 is the earlist finished activity in this OPT solution.
    // by "cut-and-paste", we can replace this a1 with a0 without breaking the mutual comaptibility.
    vector<Activity> activitySelection(vector<Activity>& activityList)
    {

        if (activityList.empty())
            return{};

        // sort the list of activities by finish time
        sort(activityList.begin(), activityList.end(), [&](const Activity& lhs, const Activity& rhs) {
            return lhs.finish < rhs.finish;
        });

        vector<Activity> result;
        Activity first = activityList[0];
        result.push_back(first);

        for (int i = 1; i < activityList.size(); i++)
        {
            if (first.finish <= activityList[i].start)
            {
                result.push_back(activityList[i]);
                first = activityList[i];
            }
        }
        return result;
    }
}