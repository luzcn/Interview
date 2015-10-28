#pragma once
#include "stdafx.h"

namespace careercup
{
    void permute(vector<int>& nums, vector<vector<int>>& result, 
        vector<int>& current, vector<bool>& visited)
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
                // nums must be sorted
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                    continue;

                visited[i] = true;
                current.push_back(nums[i]);
                permute(nums, result, current, visited);
                current.pop_back();
                visited[i] = false;
            }
        }
    }

    void combination(vector<int>& nums, int k, vector<vector<int>>& result, vector<int>& current,
        vector<bool>& visited, int index)
    {
        if (current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])   // remove duplicate
                continue;

            current.push_back(nums[i]);
            combination(nums, k, result, current, visited, i + 1);
            current.pop_back();
        }
    }
}

#if 0
int main()
{
    vector<int> nums{ 1,2,3,4,5,6 };
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);

    combination(nums, 3, result, current, visited, 0);

    return 0;
}
#endif