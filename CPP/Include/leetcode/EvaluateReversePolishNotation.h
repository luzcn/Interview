#pragma once

#include "stdafx.h"
#include <stack>

/***
 *	 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:

 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

 The idea is using a stack.
 1. Read from the begining of the input list, if current token is an operand, push it to the stack.
 2. If current token is operator, pop out the top two items in the stack as two operands,
 evaluate the arithmetic expression, push the result back to the stack.
 */

namespace EvaluateReversePolishNotation
{
    using namespace std;

    namespace details
    {
        bool isOprator(string c)
        {
            if (c == "+" || c == "-"
                || c == "*" || c == "/")
            {
                return true;
            }

            return false;
        }

        int evaluate(string op, int val1, int val2)
        {
            if (op == "+")
            {
                return val1 + val2;
            }
            else if (op == "-")
            {
                return val2 - val1;
            }
            else if (op == "*")
            {
                return val1*val2;
            }
            else if (op == "/")
            {
                if (val1 == 0)
                {
                    throw std::exception("Divid by 0 is invalid");
                }
                else
                {
                    return val2 / val1;
                }
            }

            return 0;
        }
    }

    int evalRPN(vector<string> &tokens)
    {
        if (tokens.empty())
        {
            return 0;
        }

        stack<int> s;
        int val1;
        int val2;

        for (auto it = tokens.begin(); it != tokens.end(); ++it)
        {
            string current_token = *it;
            if (!details::isOprator(current_token))
            {
                s.push(std::atoi(current_token.c_str()));
            }
            else
            {
                // pop the stack twice.
                if (!s.empty())
                {
                    val1 = s.top();
                    s.pop();
                }
                else
                {
                    throw std::exception("Invalid expression");
                }

                if (!s.empty())
                {
                    val2 = s.top();
                    s.pop();
                }
                else
                {
                    throw std::exception("Invalid expression");
                }

                s.push(details::evaluate(current_token, val1, val2));
            }
        }

        return s.top();
    }
}

#if 0
#include "leetcode\EvaluateReversePolishNotation.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    vector<string> v = { "2", "1", "+", "*", "*" };

    try
    {
        cout << EvaluateReversePolishNotation::evalRPN(v) << endl;
    }
    catch (std::exception& ex)
    {
        cout << ex.what() << endl;
    }
    catch (...){}

    return 0;
}

#endif