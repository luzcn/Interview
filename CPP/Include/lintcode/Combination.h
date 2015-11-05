#pragma once
#include "stdafx.h"

//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is :
//[[2, 4], [3, 4], [2, 3], [1, 2], [1, 3], [1, 4]]

namespace lintcode
{
    void combineRec(int n, vector<vector<int>>& res,
        vector<int>& current, int k, int index)
    {
        if (current.size() == k)
        {
            res.push_back(current);
            return;
        }

        for (int i = index; i < n; i++)
        {
            current.push_back(i + 1);
            combineRec(n, res, current, k, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > res;
        vector<int> current;

        combineRec(n, res, current, k, 0);
        return res;
    }

    // Given a set of candidate numbers(C) and a target number(T), 
    // find all unique combinations in C where the candidate numbers sums to T.
    // The same repeated number may be chosen from C unlimited number of times.
    //    For example, given candidate set 2, 3, 6, 7 and target 7,
    //    A solution set is :
    //      [7]
    //      [2, 2, 3]
    void combinationSumRec(const vector<int> &candidates, const int target, vector<vector<int>>& res,
        vector<int>& current, int sum, int index)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            combinationSumRec(candidates, target, res, current, sum + candidates[i], i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> current;

        combinationSumRec(candidates, target, res, current, 0, 0);

        return res;
    }
}