#pragma once

#include "stdafx.h"
#include <stack>

namespace ExpressionEvaluation
{
    using namespace std;

    // return true if op1 has higher precedence than op2
    bool hasPrecedence(char op1, char op2)
    {
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        {
            return true;
        }
        if (op1 == '(' || op1 == ')')
            return false;

        return false;
    }

    int compute(char op, int num1, int num2)
    {
        if (op == '+')
        {
            return num1 + num2;
        }
        else if (op == '-')
        {
            return num1 - num2;
        }
        else if (op == '*')
        {
            return num1 * num2;
        }
        else if (op == '/')
        {
            if (num2 != 0)
            {
                return num1 / num2;
            }
            else
            {
                throw std::exception("Not valid! ");
            }
        }
        return 0;
    }
    /**
     * Assume the input express is a avalid expression.
     * 
     *	Test Cases:
     "10 + 2 * 6"            ---> 22
     "100 * 2 + 12"          ---> 212
     "100 * ( 2 + 12 )"      ---> 1400
     "100 * ( 2 + 12 ) / 14" ---> 100

     notes:
     1. parsing the tokens, not single characters.
     2. atoi, convert to interger, not directly using string
     3. handling whitespace.
     4. remember handling parenthesis.
     */
    int evaluate(const string& expression)
    {
        stack<int> values;
        stack<char> ops;

        for (int i = 0; i < expression.size(); ++i)
        {
            if (expression[i] == ' ')  // skip the whitespace
                continue;

            if (expression[i] >= '0' && expression[i] <= '9') // if digits, get the number
            {
                string str("");
                while (i < expression.size() && expression[i] >= '0' && expression[i] <= '9')  
                {
                    str.append(std::to_string(expression[i] - '0'));
                    i++;
                }
                values.push(std::atoi(str.c_str()));
            }
            else if (expression[i] == '(')  // if "(", push to the ops stack.
            {
                ops.push(expression[i]);
            }
            else if (expression[i] == '+' || expression[i] == '-'
                || expression[i] == '*' || expression[i] == '/')
            {
                // if operators in the stack have higher priority than current one, 
                // need to pop out and compute first.
                while (!ops.empty() && hasPrecedence(ops.top(), expression[i])) 
                {
                    auto op = ops.top();
                    ops.pop();
                    auto num1 = values.top();
                    values.pop();
                    auto num2 = values.top();
                    values.pop();

                    auto val = compute(op, num2, num1);
                    values.push(val);
                }
                ops.push(expression[i]);
            }
            else if (expression[i] == ')')
            {
                while (ops.top() != '(')
                {
                    auto op = ops.top();
                    ops.pop();
                    auto num1 = values.top();
                    values.pop();
                    auto num2 = values.top();
                    values.pop();

                    auto val = compute(op, num2, num1);
                    values.push(val);
                }
                ops.pop();
                
            }
        }

        while (!ops.empty())
        {
            auto op = ops.top();
            ops.pop();
            auto num1 = values.top();
            values.pop();
            auto num2 = values.top();
            values.pop();

            auto val = compute(op, num2, num1);
            values.push(val);
        }

        return values.top();
    }
}

#if 0
#include "stdafx.h"
#include "CareerCup/ExpressionEvaluation.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    string exp("100 * ( 2 + 12 )");
    cout << ExpressionEvaluation::evaluate(exp) << endl;

    return 0;
}
#endif