#pragma once
#include "stdafx.h"
#include <stack>

namespace leetcode
{
    /**
     * A simple calculator, only "(", ")", "+", "-" on non-negative integers.
     * Thought:
     * for '(' ')', we do not need to compute first as the general expression evaluation,
     * because 2-(3+4) => 2 - 3 - 4. So all we need to is to record the numbers (2, 3,,4) and the sign of each number.
     **/
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

                res += num * g ;
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
}