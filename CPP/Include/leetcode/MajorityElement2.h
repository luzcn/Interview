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
            // Find the candidate element which has the most occurance
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
    class Solution {
    private:
        void split(vector<int>& nums, int left, int right, int len, vector<int>& ans)
        {
            if (left >= right)
                return;

            int idx = (left + right) / 2;

            int val = nums[idx];
            int i = left + 1;
            int j = left;
            int k = left;

            swap(nums[idx], nums[left]);

            while (i < nums.size())
            {
                if (nums[i] < val)
                {
                    swap(nums[k++], nums[i]);
                    swap(nums[++j], nums[i++]);
                }
                else if (nums[i] == val)
                {
                    swap(nums[i++], nums[++j]);
                }
                else i++;
            }

            if (j - k + 1 >= len)
                ans.push_back(nums[k]);

            if (k - left >= len)
                split(nums, left, k, len, ans);

            if (right - j >= len)
                split(nums, j + 1, right, len, ans);
        }
    public:
        vector<int> majorityElement(vector<int>& nums)
        {
            vector<int> ans;
            if (nums.empty())
                return ans;

            split(nums, 0, nums.size(), 1 + nums.size() / 3, ans);

            return ans;
        }
    };
}