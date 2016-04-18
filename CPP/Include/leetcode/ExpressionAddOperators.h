#pragma once
#include "stdafx.h"

//Given a string that contains only digits 0 - 9 and a target value, 
//return all possibilities to add binary operators(not unary) + , -, or *between the digits 
// so they evaluate to the target value.
//
//Examples:
//
//"123", 6 ->["1+2+3", "1*2*3"]
//"232", 8 ->["2*3+2", "2+3*2"]
//"105", 5 ->["1*0+5", "10-5"]
//"00", 0 ->["0+0", "0-0", "0*0"]
//"3456237490", 9191 ->[]

// https://segmentfault.com/a/1190000003797204

#if 0
namespace leetcode
{
    // return true if op1 is '*' and op2 is '+' or '-'
    bool higherOrder(char op1, char op2)
    {
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return true;

        if ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/'))
            return true;

        return false;
    }

    int compute(stack<char>& ops, stack<int>& nums)
    {
        int n2 = nums.top();
        nums.pop();

        int n1 = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();

        if (op == '+')
            return n1 + n2;
        if (op == '-')
            return n1 - n2;
        if (op == '*')
            return n1*n2;

        return 0;
    }
    // no prenthesis, only + - *
    int evaluateExpression(string s)
    {
        size_t i = 0;
        stack<int> nums;
        stack<char> ops;

        while (i < s.size())
        {
            int num1 = 0;
            char op = ' ';

            while (i < s.size() && isdigit(s[i]))
            {
                num1 = num1 * 10 + s[i] - '0';
                i++;
            }
            nums.push(num1);
            if (i < s.size())
            {
                op = s[i];
                i++;
            }
            while (!ops.empty() && op != ' ' && higherOrder(ops.top(), op))
            {
                int newValue = compute(ops, nums);
                nums.push(newValue);
            }
            if (op != ' ')
            {
                ops.push(op);
            }
        }

        while (!ops.empty())
        {
            int newValue = compute(ops, nums);
            nums.push(newValue);
        }

        return nums.top();
    }

    void getExpressions(string& num, vector<char>& ops, vector<string>& res, string& current, int start, int target)
    {
        if (start >= num.size() - 1)
        {
            auto substr = num.substr(start);
            current.append(substr);

            if (evaluateExpression(current) == target)
            {
                res.push_back(current);
            }
            current.resize(current.size() - substr.size());

            return;
        }

        for (int j = 0; j < ops.size(); j++)
        {
            for (int i = start; i < num.size() - 1; i++)
            {
                string prefix = num.substr(start, i - start + 1);
                if (stoi(prefix) > target && ops[j] != '-')
                    continue;

                current.append(prefix).push_back(ops[j]);
                getExpressions(num, ops, res, current, i + 1, target);
                current.resize(current.size() - prefix.size() - 1);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<char> ops{ '+', '-', '*' };
        vector<string> res;
        string current = "";
        getExpressions(num, ops, res, current, 0, target);

        return res;
    }
}
#endif

namespace leetcode
{
    // value: the current expression value
    // diff: the value that has been changed in previous recursive call
    // for example: 2+3, the current is 5, diff is 3
    // 2-3, the current is -1, diff is -3
    // 2+3*4, if we have 5*4, it is wrong. We should make it 5-3+3*4.
    void dfs(string& num, int target, vector<string>& result,
        long long int value, long long int diff, string current, int start)
    {
        if (start >= num.size())
        {
            if (value == target)
            {
                result.push_back(current);
            }
            return;
        }

        for (int i = start; i < num.size(); i++)
        {
            string prefix = num.substr(start, i - start + 1);

            if (prefix.size() > 1 && prefix[0] == '0')
            {
                return;
            }

            if (current.empty())
            {
                // "+1+2+3" the first "+1" is redundant.
                dfs(num, target, result, stoll(prefix), stoll(prefix), prefix, i + 1);
            }
            else
            {
                dfs(num, target, result, value + stoll(prefix), stoll(prefix), current + "+" + prefix, i + 1);
                dfs(num, target, result, value - stoll(prefix), -stoll(prefix), current + "-" + prefix, i + 1);
                dfs(num, target, result, (value-diff) + diff*stoll(prefix), diff*stoll(prefix), current + "*" + prefix, i + 1);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> result;

        dfs(num, target, result, 0, 0, "", 0);

        return result;
    }
}