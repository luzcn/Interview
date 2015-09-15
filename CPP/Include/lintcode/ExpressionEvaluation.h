#pragma once
#include "stdafx.h"
#include <stack>

//Hard Expression Evaluation
//
//Given an expression string array, return the final result of this expression
//Have you met this question in a real interview ?
//Example
//
//For the expression 2 * 6 - (23 + 7) / (1 + 2), input is
//
//[
//    "2", "*", "6", "-", "(",
//    "23", "+", "7", ")", "/",
//    (", "1", " + ", "2", ")"
//],
//
//return 2
//The expression contains only integer, +, -, *, / , (, ).

namespace lintcode
{
    bool isOperator(string& s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        return false;
    }

    // return true, if op1 has higher or eaqual processing order than op2
    bool isHigherOrEquel(string& op1, string& op2)
    {
        if (op1 == "*" || op1 == "/")
            return true;
        if ((op1 == "+" || op1 == "-") && (op2 == "+" || op2 == "-"))
        {
            return true;
        }
        return false;
    }

    int compute(int n1, int n2, string& op)
    {
        if (op == "*")
            return n1*n2;
        if (op == "/")
        {
            _ASSERT(n2 != 0);
            return n1 / n2;
        }
        if (op == "+")
            return n1 + n2;
        if (op == "-")
            return n1 - n2;

        return 0;
    }

    void process(stack<int>& nums, stack<string>& ops)
    {
        string op = ops.top();
        ops.pop();

        int n2 = nums.top();
        nums.pop();

        int n1 = nums.top();
        nums.pop();

        int result = compute(n1, n2, op);
        nums.push(result);
    }


    int evaluateExpression(vector<string> &expression)
    {
        if (expression.empty())
            return 0;

        stack<int> nums;
        stack<string> ops;

        int i = 0;
        while (i < expression.size())
        {
            string str = expression[i];
            if (str == "(")
            {
                ops.push("(");
            }
            else if (str == ")")
            {
                while (!ops.empty() && ops.top() != "(")
                {
                    process(nums, ops);
                }
                ops.pop();
            }
            else if (isOperator(str))
            {
                while (!ops.empty() && isHigherOrEquel(ops.top(), str))
                {
                    process(nums, ops);
                }
                ops.push(str);
            }
            else
            {
                // INT
                nums.push(stoi(str));
            }
            i++;
        }

        while (!ops.empty())
        {
            process(nums, ops);
        }

        return nums.empty() ? 0 : nums.top();
    }
}
