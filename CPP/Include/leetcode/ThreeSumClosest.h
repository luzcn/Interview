#pragma once
#include "stdafx.h"

// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
// For example, given array S = { -1 2 1 - 4 }, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

namespace leetcode
{
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int result = 0;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }

                // compute the closest
                int distance = abs(target - sum);
                if (distance < closest)
                {
                    closest = distance;
                    result = sum;
                }
            }
        }

        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            // now two sum problem
            int l = i + 1;
            int r = nums.size() - 1;
            int t = target - nums[i];

            // similar to binary search
            while (l < r)
            {
                if (nums[l] + nums[r] == t)
                {
                    vector<int> current;
                    current.push_back(i);
                    current.push_back(l);
                    current.push_back(r);
                    result.push_back(current);

                    l++;
                    r--;

                    // remove the duplicates
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                }
                else if (nums[l] + nums[r] < t)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        return result;
    }


    //  Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
    //  Find all unique quadruplets in the array which gives the sum of target.
    //  Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ? b ? c ? d)
    //  The solution set must not contain duplicate quadruplets.
    //  For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.
    //  A solution set is :
    //  (-1, 0, 0, 1)
    //  (-2, -1, 1, 2)
    //  (-2, 0, 0, 2)
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if (nums.size() <= 3)
            return result;

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++)
        {
            // remove duplicate result
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                // remove duplicate result.
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // now two sum problem.
                //int t = target - nums[i] - nums[j];
                int l = j + 1;
                int r = nums.size() - 1;

                while (l < r)
                {
                    if (nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        vector<int> current{ i,j, l, r };
                        result.push_back(current);
                        l++;
                        r--;

                        // remove duplicates
                        while (l < r && nums[l] == nums[l - 1])
                        {
                            l++;
                        }

                        while (l < r && nums[r] == nums[r + 1])
                        {
                            r--;
                        }
                    }
                    else if (nums[i] + nums[j] + nums[l] + nums[r] < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }

        return result;
    }


    //3Sum Smaller
    // Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
    // that satisfy the condition nums[i] + nums[j] + nums[k] < target.
    // 
    // For example, given nums = [-2, 0, 1, 3], and target = 2.
    // Return 2. Because there are two triplets which sums are less than 2:
    //[-2, 0, 1]
    //[-2, 0, 3]
    int threeSumSmaller(vector<int>& nums, int target)
    {
        if (nums.size() < 3)
            return 0;

        int result = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] >= target)
                {
                    r--;
                }
                else
                {
                    result += r - l;
                    l++;
                }
            }
        }

        return result;
    }
}