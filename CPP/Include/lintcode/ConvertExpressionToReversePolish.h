#pragma once
#include "stdafx.h"
#include <stack>

// For the expression[3 - 4 + 5](which denote by["3", "-", "4", "+", "5"]), 
// return[3 4 - 5 + ](which denote by["3", "4", "-", "5", "+"])
namespace lintcode
{
    bool isOperator(string& str)
    {
        if (str == "*" || str == "/"
            || str == "+" || str == "-")
            return true;

        return false;
    }

    bool isHigherOrEquelOrder(string& str1, string& str2)
    {
        if (str1 == "*" || str1 == "/")
            return true;
        if ((str1 == "+" || str1 == "-") && (str2 == "+" || str2 == "-"))
            return true;

        return false;
    }

    void process(std::stack<string>& nums, std::stack<string>& ops)
    {
        string n2 = "";
        string n1 = "";
        string op = "";
        n2 = nums.top();
        nums.pop();
        n1 = nums.top();
        nums.pop();

        op = ops.top();
        ops.pop();

        nums.push(n1.append(" ").append(n2).append(" ").append(op));
    }

    string convertToRPN(vector<string> &expression)
    {
        std::stack<string> nums;
        std::stack<string> ops;
        string res;

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
            else if (!isOperator(str))
            {
                nums.push(str);
            }
            else
            {
                while (!ops.empty() && isHigherOrEquelOrder(ops.top(), str))
                {
                    process(nums, ops);
                }
                ops.push(str);
            }

            i++;
        }
        while (!ops.empty())
        {
            process(nums, ops);
        }

        if (nums.empty())
            return "";

        return nums.top();
    }
}