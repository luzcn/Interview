#pragma once
#include "stdafx.h"

namespace leetcode
{
    namespace helper
    {
        // sort the array solution, O(nlogn) time, O(1) space
        // but cannot guarantee there is always a majority element.
        int majority_sort(vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());

            return nums[nums.size() / 2];
        }

        // O(n) time, O(1) space, Moore's voting algorithm
        int majority_voting(const vector<int>& nums)
        {
            // Find the candicate element which has the most occurance
            int maj_index = 0;
            int count = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[maj_index] == nums[i])
                    count++;
                else
                    count--;

                if (count == 0)
                {
                    maj_index = i;
                    count = 1;
                }
            }

            // check if it is the majority
            count = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[maj_index] == nums[i])
                    count++;

                if (count > nums.size() / 2) 
                    return nums[maj_index];
            }

            return -1;
        }
    }
    // Find the majority element from an array
    // majority means the element occurs more than n/2 times.
    int majority(vector<int>& nums)
    {
        return helper::majority_voting(nums);
    }
    
    // Find the majority element from an array, which has more than n/3 occurance
    vector<int> majority2(vector<int>& A)
    {
        vector<int> res;

        return res;
    }
}