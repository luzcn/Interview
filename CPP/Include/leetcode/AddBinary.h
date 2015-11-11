#pragma once

#include "stdafx.h"

//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".
//
//http://fisherlei.blogspot.com/2013/01/leetcode-add-binary.html
namespace leetcode
{
    string addBinary(string a, string b)
    {
        int carry = 0;
        string result("");
        for (int i = a.size() - 1, int j = b.size() - 1; i >= 0 || j >= 0; --i, --j)
        {
            int value_i = i >= 0 ? a[i] - '0' : 0;
            int value_j = j >= 0 ? b[j] - '0' : 0;

            auto sum = (value_i + value_j + carry) % 2;
            carry = (value_i + value_j + carry) / 2;

            result.insert(result.begin(), sum + '0');
        }

        if (carry == 1)
        {
            result.insert(result.begin(), '1');
        }

        return result;
    }
}