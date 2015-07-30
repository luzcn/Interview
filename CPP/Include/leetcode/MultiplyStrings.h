#pragma once
#include "stdafx.h"

//  Given two numbers represented as strings, return multiplication of the numbers as a string.
//  Note: The numbers can be arbitrarily large and are non-negative.
namespace leetcode
{
    string multiply(string num1, string num2)
    {
        string res(num1.size() + num2.size() + 1, '0');
        if (num1.empty() || num2.empty())
            return "";

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        int carry = 0;
        for (int i = 0; i < num1.size(); i++)
        {
            int n1 = num1[i] - '0';
            for (int j = 0; j < num2.size(); j++)
            {
                int n2 = num2[j] - '0';
                int exists = res[i + j] - '0';

                int temp = n1*n2 + carry + exists;
                res[i + j] = temp % 10 + '0';
                carry = temp / 10;
            }
            // after finished each single digit multiplication iteration, 
            // need to put the carry to the begining of the res 
            // (here is the end non-zero position) and reset carry.
            if (carry > 0)
            {
                res[i + num2.size()] = carry + '0';
                carry = 0;
            }
        }
        std::reverse(res.begin(), res.end());
        int start = 0;
        for (start = 0; start < res.size(); start++)
        {
            if (res[start] != '0')
                break;
        }
        if (start == res.size())
            return "0";

        return res.substr(start);
    }
}
