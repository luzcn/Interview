#pragma once
#include "stdafx.h"

//Given a string that contains only digits 0 - 9 and a target value, 
//return all possibilities to add binary operators(not unary) + , -, or *between the digits so they evaluate to the target value.
//
//Examples:
//
//"123", 6 ->["1+2+3", "1*2*3"]
//"232", 8 ->["2*3+2", "2+3*2"]
//"105", 5 ->["1*0+5", "10-5"]
//"00", 0 ->["0+0", "0-0", "0*0"]
//"3456237490", 9191 ->[]

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
    // diff: the value needs to change,
    // curNum: the current value
    void addOperatorsDFS(string num, int target, vector<string> &result, 
        long long diff, long long curNum, string outs)
    {
        if (num.empty() && curNum == target)
        {
            result.push_back(outs);
            return;
        }

        for (int i = 0; i < num.size(); i++)
        {
            string prefix = num.substr(0, i + 1);

            if (prefix.size() > 1 && prefix[0] == '0')    // "00" is not valid number
                return;

            string last = num.substr(i + 1);

            if (outs.empty())
            {
                addOperatorsDFS(last, target, result, stoll(prefix), stoll(prefix), prefix);
            }
            else
            {
                addOperatorsDFS(last, target, result, stoll(prefix), curNum + stoll(prefix), outs + '+' + prefix);
                addOperatorsDFS(last, target, result, -stoll(prefix), curNum - stoll(prefix), outs + '-' + prefix);
                addOperatorsDFS(last, target, result, diff * stoll(prefix), (curNum - diff) + diff*stoll(prefix), outs + '*' + prefix);
            }
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> result;

        addOperatorsDFS(num, target, result, 0, 0, "");
        
        return result;
    }
}