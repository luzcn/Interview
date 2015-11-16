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
}