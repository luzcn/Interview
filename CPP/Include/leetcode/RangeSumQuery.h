#pragma once
#include "stdafx.h"

namespace leetcode
{
    class NumArray {
    public:
        NumArray(vector<int> &nums)
        {
            totalSums.resize(nums.size() + 1);
            totalSums[0] = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                totalSums[i + 1] = totalSums[i] + nums[i];
            }
        }

        int sumRange(int i, int j)
        {
            return totalSums[j + 1] - totalSums[i];
        }
    private:
        vector<int> totalSums;
    };


    // Your NumArray object will be instantiated and called as such:
    // NumArray numArray(nums);
    // numArray.sumRange(0, 1);
    // numArray.sumRange(1, 2);
}