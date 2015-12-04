#pragma once
#include "stdafx.h"

//  Given a string of numbers and operators, return all possible results from computing all 
//  the different possible ways to group numbers and operators.The valid operators are + , -and *.
//
//  Example 1
//  Input: "2-1-1".
//
//    ((2 - 1) - 1) = 0
//    (2 - (1 - 1)) = 2
//
//    Output : [0, 2]
//
//    Example 2
//    Input : "2*3-4*5"
//
//    (2 * (3 - (4 * 5))) = -34
//    ((2 * 3) - (4 * 5)) = -14
//    ((2 * (3 - 4)) * 5) = -10
//    (2 * ((3 - 4) * 5)) = -10
//    (((2 * 3) - 4) * 5) = 10
//
//    Output: [-34, -14, -10, -10, 10]
//
// divide conquer
// scan the string, each time finds an operator
// split the string into two parts and compute separately
// Assume there is no whitespace between numbers and operators
namespace leetcode
{
    int compute(int n1, int n2, char c)
    {
        switch (c)
        {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1*n2;
        default:
            break;
        }

        return 0;
    }

    vector<int> dfs(string& input, int l, int r)
    {
        if (l > r)
            return{};

        int i = l, num = 0;
        while (i <= r && isdigit(input[i]))
        {
            num = num * 10 + input[i] - '0';
            i++;
        }
        if (i > r)
            return{ num };

        vector<int> left;
        vector<int> right;
        vector<int> result;

        for (int i = l; i <= r; i++)
        {
            if (isdigit(input[i]))
                continue;

            left = dfs(input, l, i - 1);
            right = dfs(input, i + 1, r);

            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    result.push_back(compute(left[j], right[k], input[i]));
                }
            }
        }

        return result;
    }
    vector<int> diffWaysToCompute(string input)
    {
        if (input.empty())
            return{};

        return dfs(input, 0, input.size() - 1);
    }
}
