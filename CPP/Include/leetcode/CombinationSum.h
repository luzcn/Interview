#pragma once
#include "stdafx.h"
namespace leetcode
{
#pragma region Combination Sum 1
    //  Given a set of candidate numbers(C) and a target number(T), 
    //  find all unique combinations in C where the candidate numbers sums to T.
    //    The same repeated number may be chosen from C unlimited number of times.
    //  All numbers(including target) will be positive integers.
    //    Elements in a combination(a1, a2, …, ak) must be in non - descending order. (ie, a1 ? a2 ? … ? ak).
    //    The solution set must not contain duplicate combinations.
    //    For example, given candidate set 2, 3, 6, 7 and target 7,
    //    A solution set is :
    //[7]
    //[2, 2, 3]
    void combinationSumRec(const vector<int>& candidates, const int& target,
        vector<vector<int>>& result, vector<int>& current, int sum)
    {
        if (sum == target)
        {
            result.push_back(current);
            return;
        }

        if (sum > target)
        {
            return;
        }

        for (int i = 0; i < candidates.size(); i++)
        {
            current.push_back(candidates[i]);
            combinationSumRec(candidates, target, result, current, sum + candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        if (candidates.empty())
            return result;

        vector<int> current;
        combinationSumRec(candidates, target, result, current, 0);

        return result;
    }
#pragma endregion

#pragma region Combination Sum 2
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
#pragma endregion
}