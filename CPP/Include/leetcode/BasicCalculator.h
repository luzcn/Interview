#pragma once
#include "stdafx.h"
#include <stack>

namespace leetcode
{
    // A simple calculator, only "(", ")", "+", "-" on non-negative integers.
    // Thought:
    //  for '(' ')', we do not need to compute first as the general expression evaluation,
    //  because 2-(3+4) => 2 - 3 - 4. So all we need to is to record the numbers (2, 3,,4) and the sign of each number.
    int calculate(string s)
    {
        stack<int> sign;
        sign.push(1); // the sign out side of "()"
        sign.push(1); // the sign inside "()"

        int i = 0;
        int res = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                int num = s[i] - '0';
                while (isdigit(s[++i]))
                {
                    num = num * 10 + s[i] - '0';
                }
                int g = sign.top();
                sign.pop();

                res += num * g;
            }
            else if (s[i] == '+' || s[i] == '(')
            {
                sign.push(sign.top());
                i++;
            }
            else if (s[i] == '-')
            {
                sign.push(-1 * sign.top());
                i++;
            }
            else if (s[i] == ')')
            {
                sign.pop();
                i++;
            }
            else
                i++;
        }

        return res;
    }

    //Basic Calculator 2
    // Implement a basic calculator to evaluate a simple expression string.
    //
    // The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
    // The integer division should truncate toward zero.
    //
    // You may assume that the given expression is always valid.
    //
    // Some examples:
    //   "3+2*2" = 7
    //   " 3/2 " = 1
    //   " 3+5 / 2 " = 5
#pragma region Basic Calculator 2
    class Solution
    {
    public:
        int calculate(string s)
        {
            stack<char> ops;
            stack<int> nums;

            int i = 0;
            while (i < s.size())
            {
                if (isdigit(s[i]))
                {
                    nums.push(getNumber(s, i));
                }
                else if (iswspace(s[i]))
                {
                    i++;
                }
                else
                {
                    while (!ops.empty() && isHigher(ops.top(), s[i]))
                    {
                        // need to compute first
                        evaluate(ops, nums);
                    }

                    // push the operator to the operator stack.
                    ops.push(s[i]);
                    i++;
                }
            }

            while (!ops.empty())
            {
                evaluate(ops, nums);
            }

            return nums.top();
        }
    private:
        int getNumber(string& s, int& i)
        {
            int result = 0;

            while (i < s.size() && isdigit(s[i]))
            {
                result = result * 10 + s[i] - '0';
                i++;
            }

            return result;
        }

        // return true if op1 higher calculate order than op2
        bool isHigher(char op1, char op2)
        {
            if (op1 == '*' || op1 == '/')
            {
                return true;
            }

            if ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))
            {
                return true;
            }
            return false;
        }

        int compute(char op, int num1, int num2)
        {
            switch (op)
            {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
            default:
                break;
            }

            return 0;
        }

        void evaluate(stack<char>& ops, stack<int>& nums)
        {
            int num1 = nums.top();
            nums.pop();

            int num2 = nums.top();
            nums.pop();

            char op = ops.top();
            ops.pop();

            nums.push(compute(op, num2, num1));
        }
    };
#pragma endregion

    /*
    * Basic Calculator 3
    * with paranthesis 2+(3-5)*4-(3+2)/2
    */
#pragma region Basic Calculator 3
    // Helper function
    // op1 is higher than op2
    bool higher(char op1, char op2)
    {
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return true;

        return false;
    }

    int compute(char op, int num1, int num2)
    {
        switch (op)
        {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            break;
        }

        return 0;
    }

    void evaluate(stack<int>& nums, stack<char>& ops)
    {
        int num1 = nums.top();
        nums.pop();

        int num2 = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();

        nums.push(compute(op, num2, num1));
    }
    int calculate3(string s)
    {
        stack<int> numbers;
        stack<char> ops;

        int i = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                int num = s[i] - '0';
                while (isdigit(s[++i]))
                {
                    num = num * 10 + s[i] - '0';
                }
                numbers.push(num);
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                while (!ops.empty() && ops.top() != '(' &&!higher(s[i], ops.top()))
                {
                    // current operator is not higher order than the previous one
                    // need to compute the previous first.
                    evaluate(numbers, ops);
                }
                ops.push(s[i]);
                i++;
            }
            else if (s[i] == '(')
            {
                ops.push(s[i]);
                i++;
            }
            else if (s[i] == ')')
            {
                while (!ops.empty() && ops.top() != '(')
                {
                    evaluate(numbers, ops);
                }
                if (!ops.empty())
                {
                    ops.pop();
                }
                i++;
            }
            else
                i++;
        }

        while (!ops.empty())
        {
            evaluate(numbers, ops);
        }

        return numbers.empty() ? 0 : numbers.top();
    }
#pragma endregion


}