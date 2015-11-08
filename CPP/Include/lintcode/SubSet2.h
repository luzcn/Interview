#pragma once
#include "stdafx.h"

//Given a list of numbers that may has duplicate numbers, return all possible subsets
//Example
//If S = [1, 2, 2], a solution is :
//
//[
//    [2],
//    [1],
//    [1, 2, 2],
//    [2, 2],
//    [1, 2],
//    []
//]
//
//Note
//
//Each element in a subset must be in non - descending order.
//
//The ordering between two subsets is free.
//
//The solution set must not contain duplicate subsets.
namespace lintcode
{
    void subsetRec(const vector<int>& nums, vector<vector<int>>& res,
        vector<int>& current, int index)
    {
        res.push_back(current);

        if (index >= nums.size())
            return;

        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);
            subsetRec(nums, res, current, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> subset(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> current;
        std::sort(nums.begin(), nums.end());

        subsetRec(nums, res, current, 0);

        return res;

    }
}