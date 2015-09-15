#pragma once
#include "stdafx.h"

namespace lintcode
{
    int maxTwoSubArrays(vector<int> nums)
    {
        // write your code here
        if (nums.empty())
            return 0;

        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        int current_sum = 0;
        int left_max = nums[0];
        for (int i = 0; i < n; i++)
        {
            left[i] = left_max;
            current_sum += nums[i];
            left_max = max(current_sum, left_max);
            if (current_sum < 0)
                current_sum = 0;
        }

        int right_max = nums[n - 1];
        current_sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = current_sum;
            current_sum += nums[i];
            current_sum = max(current_sum, current_sum);
            if (current_sum < 0)
                current_sum = 0;
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            res = max(res, left[i] + right[i]);
        }

        return res;
    }
}