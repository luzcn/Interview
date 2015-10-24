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
    vector<Activity> activitySelection(vector<Activity>& S)
    {

        if (S.empty())
            return{};

        vector<Activity> res;
        auto a = S[0];
        res.push_back(a);

        for (int i = 1; i < S.size(); i++)
        {
            if (a.finish <= S[i].start)
            {
                res.push_back(S[i]);
                a = S[i];
            }
        }
        return res;
    }
}