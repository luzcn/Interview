#pragma once

#include "stdafx.h"

namespace SubSet
{
    using namespace std;

    void getAllSubSetRec(vector<int>& set, vector<vector<int>>& sol, vector<int>& current_sol, int index)
    {
        sol.push_back(current_sol);

        if (index >= set.size())
        {
            return;
        }

        for (int i = index; i < set.size(); ++i)
        {
            current_sol.push_back(set[i]);
            getAllSubSetRec(set, sol, current_sol, i + 1);
            current_sol.pop_back();
        }
    }


    // Get all the sub set
    vector<vector<int>> getAllSubSet(vector<int>& set)
    {
        vector<vector<int>> sol;
        vector<int> current_sol;
        getAllSubSetRec(set, sol, current_sol, 0);

        return sol;
    }
}