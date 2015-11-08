#pragma once

#include "stdafx.h"

/*
 *	Given two strings, s1, s2.
 *	s1 represents a binary number e.g. 1110 => 14.
 *	s2 represents the Hex of a number e.g. E => 14.
 *
 *	write a function to compare are these two input strings represnet the same number.
 */
namespace CompareBinaryToHex
{
    int charToDigit(char c)
    {
        if (c <= '9' && c >= '0')
        {
            return c - '0';
        }
        else if (c >= 'a' && c <= 'f')
        {
            return 10 + c - 'a';
        }
        else if (c >= 'A' && c <= 'F')
        {
            return 10 + c - 'A';
        }

        return 0;
    }

    int convertToDec(const string& s, int base)
    {
        auto len = s.size();
        int num = 0;

        if (base == 2)
        {
            for (int i = 0; i < len; ++i)
            {
                if (s[i] == '1')
                    num += std::pow(2, len - i - 1);
            }
        }
        else if (base == 16)
        {
            for (int i = 0; i < len; ++i)
            {
                int digit = charToDigit(s[i]);
                num += digit*std::pow(16, len - i - 1);
            }
        }
        else
        {
            throw std::exception("invalid base !");
        }
        return num;
    }


    bool compareBinToHex(string s1, string s2)
    {
        
        return convertToDec(s1,2) == convertToDec(s2, 16);
    }
}