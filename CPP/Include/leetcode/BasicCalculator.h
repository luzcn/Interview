#pragma once
#include "stdafx.h"
#include <stack>

namespace leetcode
{
    // helper function
    bool isHigherOperand(char op1, char op2)
    {
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return true;

        return false;
    }

    int compute(char operand, int num1, int num2)
    {
        if (operand == '+')
            return num1 + num2;

        if (operand == '-')
            return num1 - num2;

        if (operand == '*')
            return num1 * num2;

        if (operand == '/')
            return num1 / num2;

        return 0;
    }

    // helper function to parse number
    int parseNumber(string s, int& i)
    {
        int num = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
            i++;
        }

        return num;
    }

    bool isDigit(char c)
    {
        if (c <= '9' && c >= '0')
            return true;

        return false;
    }

    int calculateWithStack(const string& s)
    {
        stack<int> numbers;
        stack<char> ops;

        int i = 0;
        while (i < s.size())
        {
            char c = s[i];

            if (isDigit(s[i]))
            {
                numbers.push(parseNumber(s, i));
            }
        }

        return numbers.empty() ? 0 : numbers.top();
    }

    /**
     * A simple calculator, only "(", ")", "+", "-" on non-negative integers.
     **/
    int calculate(string s)
    {
        return calculateWithStack(s);
    }
}