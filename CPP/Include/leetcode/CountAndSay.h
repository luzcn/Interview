#pragma once
#include "stdafx.h"

//The count - and-say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
namespace leetcode
{
    string countAndSay(int n)
    {
        string res = "1";

        for (int i = 2; i <= n; i++)
        {
            int j = 0;
            string temp = "";

            while (j < res.size())
            {
                int count = 0;
                char current = res[j];

                while (j < res.size() && res[j] == current)
                {
                    count++;
                    j++;
                }
                temp += to_string(count) + current;
            }
            res = temp;
        }

        return res;
    }
}