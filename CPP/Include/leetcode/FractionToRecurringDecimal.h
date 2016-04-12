#pragma once
#include "stdafx.h"

//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".

// Thought:
// - negative number
// - INT_MIN
// - use hash map to save the fractional part and the corresponding position in final result string

namespace leetcode
{
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        if (denominator == 0)
            return "";

        string result;

        // check the sign
        // only one of the (numerator < 0) and (denominator < 0) is true
        if ((numerator < 0) ^ (denominator < 0))
        {
            result.push_back('-');
        }

        // the abs(INT_MIN) is also overflow to int, 
        // so need to convert to long long first
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        result.append(to_string(n / d));

        long long r = n % d;

        if (r == 0)
        {
            return result;
        }

        result.push_back('.');
        // use hash map to save the fractional part and the corresponding position in "result"
        unordered_map<long long, int> map;

        while (r != 0)
        {
            if (map.find(r) != map.end())
            {
                result.insert(map[r], "(");
                result.push_back(')');
                break;
            }

            map[r] = result.size();

            r *= 10;
            result.append(to_string(r / d));
            r %= d;
        }

        return result;
    }
}