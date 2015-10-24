#pragma once
#include "stdafx.h"

//Given a collection of candidate numbers(C) and a target number(T), 
//find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//
//All numbers(including target) will be positive integers.
//Elements in a combination(a1, a2, …, ak) must be in non - descending order.
//The solution set must not contain duplicate combinations.
//
//For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
//A solution set is :
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6]
namespace leetcode
{
    void combinationSum2Rec(const vector<int>& c, const int& target,
        vector<vector<int>>& res, vector<int>& current, int sum, int index)
    {
        if (sum > target)
            return;

        if (sum == target)
        {
            res.push_back(current);
            return;
        }

        for (int i = index; i < c.size(); i++)
        {
            if (i != index && c[i] == c[i - 1])
                continue;

            current.push_back(c[i]);
            combinationSum2Rec(c, target, res, current, sum + c[i], i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> current;    
        std::sort(candidates.begin(), candidates.end());

        combinationSum2Rec(candidates, target, res, current, 0, 0);

        return res;
    }
}