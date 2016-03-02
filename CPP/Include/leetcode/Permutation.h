#pragma once
#include "stdafx.h"

//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1, 1, 2] have the following unique permutations:
//[1, 1, 2], [1, 2, 1], and[2, 1, 1].
namespace leetcode
{
    void permuteNoDupRec(vector<int>& nums, 
        vector<vector<int>>& result, 
        vector<int> current, 
        vector<bool>& visited)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                if (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1])
                    continue;

                visited[i] = true;
                current.push_back(nums[i]);

                permuteNoDupRec(nums, result, current, visited);

                current.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if (nums.empty())
            return{};

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> visited(nums.size(), false);


        // Need to sort first, 
        // otherwise the comparison nums[i] == nums[i-1] in recursive does not work
        sort(nums.begin(), nums.end());

        permuteNoDupRec(nums, result, current,visited);

        return result;
    }
}