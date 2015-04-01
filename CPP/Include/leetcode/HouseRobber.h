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

    }


    int rob(vector<int> &num)
    {
        if (num.size() == 0)
            return 0;

        return robRec(num, 0);
    }
}
