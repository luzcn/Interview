#pragma once
#include "stdafx.h"

namespace careercup
{
    int sum = 0;
    int sum2 = 0;
    int rec(vector<int>& nums, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == r)
            return nums[l];

        return max(rec(nums, l + 1, r) + nums[l], rec(nums, l, r - 1) + nums[r]);
    }

    int maxSum(vector<int>& nums)
    {

        return 0;
    }
}
