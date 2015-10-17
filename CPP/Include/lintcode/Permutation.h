#pragma once
#include "stdafx.h"

//Given a list of numbers, return all possible permutations.
//Example
//
//For nums = [1, 2, 3], the permutations are :
//
//[
//    [1, 2, 3],
//    [1, 3, 2],
//    [2, 1, 3],
//    [2, 3, 1],
//    [3, 1, 2],
//    [3, 2, 1]
//]
//
//Challenge
//
//Do it without recursion.
namespace lintcode
{
    void permuteRec(vector<int>& nums, vector<vector<int>>& res,
        vector<int>& current)
    {
        if (nums.size() == 0)
        {
            res.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            current.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            permuteRec(nums, res, current);
            nums.insert(nums.begin() + i, current.back());
            current.pop_back();
        }
    }

    // Another solution
    void permuteRec2(vector<int>& nums, vector<vector<int>>& res, int index)
    {
        if (index >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            //swap i, index
            if (i != index)
            {
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }
            permuteRec2(nums, res, index + 1);

            if (i != index)
            {
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
            }

        }
    }

    vector<vector<int>> permute(vector<int> nums)
    {
        vector<vector<int>> res;
        vector<int> current;

        permuteRec(nums, res, current);
        return res;
    }

    //Given a list of numbers with duplicate number in it.Find all unique permutations.
    //    For numbers[1, 2, 2] the unique permutations are :
    //[
    //    [1, 2, 2],
    //    [2, 1, 2],
    //    [2, 2, 1]
    //]
    void permuteNoDupRec(vector<int>& nums, vector<bool>& visited,
        vector<vector<int>>& res, vector<int>& current, int index)
    {
        if (index >= nums.size())
        {
            res.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == false)
                    continue;

                visited[i] = true;
                current.push_back(nums[i]);
                permuteNoDupRec(nums, visited, res, current, index + 1);
                current.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());

        permuteNoDupRec(nums, visited, res, current, 0);

        return res;
    }
}