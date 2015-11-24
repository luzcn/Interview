#pragma once
#include "stdafx.h"

// Additive number is a positive integer whose digits can form additive sequence.
//
// A valid additive sequence should contain at least three numbers.
// Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
//
//For example :
// "112358" is an additive number because the digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
// 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
// "199100199" is also an additive number, the additive sequence is : 1, 99, 100, 199.
// 1 + 99 = 100, 99 + 100 = 199
//
// Note : Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
// Given a string represents an integer, write a function to determine if it's an additive number.
// 
// Follow up :
// How would you handle overflow for very large input integers ?
// Thought:
// 1. dfs solution
// 2. "000" is valid, however, "1023" is not valid.
// 3. use stoull (unsigned long long) to represent the integer or implement the add two strings function.
namespace leetcode
{
    // Add two strings directly, avoid to use unsigned long long
    string add(string s1, string s2)
    {
        vector<char> result;
        std::reverse(s1.begin(), s1.end());
        std::reverse(s2.begin(), s2.end());

        int carry = 0;

        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size())
        {
            int n1 = s1[i] - '0';
            int n2 = s2[j] - '0';

            int sum = (n1 + n2 + carry) % 10;
            carry = (n1 + n2 + carry) / 10;

            result.push_back(sum + '0');
            i++;
            j++;
        }

        while (i < s1.size())
        {
            int n1 = s1[i] - '0';

            int sum = (n1 + carry) % 10;
            carry = (n1 + carry) / 10;

            result.push_back(sum + '0');
            i++;
        }

        while (j < s2.size())
        {
            int n2 = s2[j] - '0';

            int sum = (n2 + carry) % 10;
            carry = (n2 + carry) / 10;

            result.push_back(sum + '0');
            j++;
        }
        if (carry > 0)
        {
            result.push_back('1');
        }

        return string(result.rbegin(), result.rend());
    }

    bool dfs(string s, string n1, string n2, int start)
    {
        if (add(n1, n2) == s.substr(start, s.size()))
        {
            return true;
        }

        for (int i = start; i < s.size(); i++)
        {
            string sum = s.substr(start, i - start + 1);
            if (sum.size() > 1 && sum[0] == '0' || sum.size() > n1.size() + n2.size())
            {
                return false;
            }

            if (add(n1, n2) == sum)
            {
                if (dfs(s, n2, sum, i + 1))
                {
                    return true;
                }
            }
        }
        return false;
    }


    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3)
        {
            return false;
        }

        for (int i = 0; i < num.size() - 2; i++)
        {
            string n1 = num.substr(0, i + 1);
            if (n1.size() > 1 && n1[0] == '0')
                break;

            for (int j = i + 1; j < num.size() - 1; j++)
            {
                string n2 = num.substr(i + 1, j - i);
                if (n2.size() > 1 && n2[0] == '0')
                    break;

                if (dfs(num, n1, n2, j + 1))
                {
                    return true;
                }
            }
        }

        return false;
    }
}