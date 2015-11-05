#pragma once
#include "stdafx.h"

//  Given string A representative a positive integer which has N digits, remove any k digits of the number, 
//  the remaining digits are arranged according to the original order to become a new positive integer.
//  Find the smallest integer after remove k digits.
// 
//  Given an integer A = "178542", k = 4
//  return a string "12"
namespace lintcode
{

    // Greedy solution
    // start from the left to right, find the first digit which is greater than it's successor.
    // 178512 -> delete 8
    // 123456789 -> delete 9
    string DeleteDigits(string A, int k)
    {
        if (A.size() <= k)
            return "";

        int i = 0;
        for (int count = 0; count < k; count++)
        {
            for (i = 0; i < A.size(); i++)
            {
                if (i == A.size() - 1 || A[i] > A[i + 1])
                {
                    // delete A[i]
                    A = A.substr(0, i) + A.substr(i + 1);
                    break;
                }
            }
        }

        i = 0;
        while (i < A.size() && A[i] == '0')
            i++;

        return A.substr(i);
    }
}