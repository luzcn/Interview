#pragma once
#include "stdafx.h"

// Write a method to replace all spaces in a string with %20. 
// The string is given in a characters array.
// you can assume it has enough space for replacement and you are given the true length of the string.
//
// Example
// Given "Mr John Smith", length = 13.
// The string after replacement should be "Mr%20John%20Smith".

namespace lintcode
{
    int replaceBlank(char str[], int length)
    {
        if (length == 0)
            return 0;

        // count how many whitespace in the input string
        int nums = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] == ' ')
                nums++;
        }

        // we can easily get the new length after replacement
        int newLen = length + 2 * nums;

        str[newLen] = '\0';
        int j = newLen - 1;
        for (int i = length - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                str[j] = str[i];
                j--;
            }
            else
            {
                str[j] = '0';
                j--;
                str[j] = '2';
                j--;
                str[j] = '%';
                j--;
            }
        }

        return newLen;

    }
}
