#pragma once
#include "stdafx.h"

namespace leetcode
{
    void dfs(vector<int>& digits, vector<int>& result, vector<int>& current, int start)
    {
        if (start >= digits.size())
        {
            return;
        }
    }

    int integerBreak(int n) 
    {
        vector<int> digits;
        int m = n;

        while (m > 0)
        {
            digits.push_back(m % 10);
            m /= 10;
        }

        reverse(digits.begin(), digits.end());

        return 0;
    }
}