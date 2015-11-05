#pragma once
#include "stdafx.h"

namespace leetcode
{
    bool verifyPreorder(vector<int>& preorder)
    {
        if (preorder.size() <= 1)
            return true;

        int n = preorder.size();
        int minValue = INT_MIN;

        stack<int> stack;
        stack.push(preorder[0]);

        int i = 1;
        while (i < n)
        {
            if (preorder[i] < minValue)
            {
                return false;
            }
            if (preorder[i] > preorder[i - 1])
            {
                while (!stack.empty() && preorder[i] > stack.top())
                {
                    minValue = stack.top();
                    stack.pop();
                }
            }

            stack.push(preorder[i]);
        }


        return true;
    }
}