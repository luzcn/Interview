#pragma once
#include "stdafx.h"

namespace careercup
{
    // compute the factorial of large number
    // the factorial of 10 has 158 digits, even long long type cannot hold this.
    int multiply(vector<int>& res, int v, int size)
    {
        int carry = 0;
        for (int i = 0; i < size; i++)
        {
            int product = v * res[i] + carry;
            res[i] = product % 10;
            carry = product / 10;
        }
        if (carry > 0)
        {
            res[size] = carry;
            size++;
        }

        return size;
    }

    vector<int> factorial(int n)
    {
        vector<int> res(200, 0);
        res[0] = 1;
        int size = 1;
        int carry = 0;
        for (int v = 2; v <= n; v++)
        {
            for (int i = 0; i < size; i++)
            {
                int product = v * res[i] + carry;
                res[i] = product % 10;
                carry = product / 10;
            }
            if (carry > 0)
            {
                res[size] = carry;
                carry = 0;
                size++;
            }
        }

        //std::reverse(res.begin(), res.end());

        return res;
    }
}