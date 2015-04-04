#pragma once
#include "stdafx.h"

namespace HouseRobber
{
    // The recursive solution.    
    int robRec(vector<int>& num, int i)
    {
        if (i >= num.size())
            return 0;

        if (i == num.size() - 1)
            return num[i];

        return std::max(num[i] + robRec(num, i + 2), robRec(num, i + 1));
    }

    // The DP solution
    int robDP(vector<int>& num)
    {
        if (num.size() == 0)
            return 0;

        int n = num.size();
        vector<int> res(n + 1, 0);
        res[1] = num[0];  // if there is only one house, we can only rob this one.

        for (int i = 2; i <= n; i++)
        {
            res[i] = max(res[i - 2] + num[i-1], res[i - 1]);
        }

        return res[n];
    }


    int rob(vector<int> &num)
    {
        if (num.size() == 0)
            return 0;

        return robRec(num, 0);
    }
}
