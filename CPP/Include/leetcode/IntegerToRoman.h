#pragma once
#include "stdafx.h"

// String[] roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
// int[] value = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.
// Roman Chart:
// 1 -> I
// 4 -> IV   
// 5 -> V
// 10 -> X
// 40 -> XL
// 50 -> L
// 90 -> XC
// 100 -> C
// 400 -> CD
// 500 -> D
// 900 -> CM
// 1000 -> M
//
// 4, 9, 40, 90, 400 and 900 are special numbers, they are using minus-1 (put I on left side) notation.
namespace leetcode
{
    string intToRoman(int num)
    {
        vector<string> roman{ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> value{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        string result;

        int index = 0;
        while (index < value.size())
        {
            if (num >= value[index])
            {
                result.append(roman[index]);
                num -= value[index];
            }
            else
            {
                index++;
            }
        }

        return result;
    }


    // 1 -> I
    // 4 -> IV   
    // 5 -> V
    // 10 -> X
    // 40 -> XL
    // 50 -> L
    // 90 -> XC
    // 100 -> C
    // 400 -> CD
    // 500 -> D
    // 900 -> CM
    // 1000 -> M
    //
    //unordered_map<string, int> mapRomanInt{
    //    { "M",   1000 },
    //    { "CM",  900 },
    //    { "D",   500 },
    //    { "CD",  400 },
    //    { "C",   100 },
    //    { "XC",  90 },
    //    { "L",   50 },
    //    { "XL",  40 },
    //    { "X",   10 },
    //    { "IX",  9 },
    //    { "V",   5 },
    //    { "IV",  4 },
    //    { "I",   1 }
    //};
    int romanToInt(string s)
    {
        vector<string> roman{ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> value{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };

        unordered_map<string, int> mapRomanInt;
        for (int i = 0; i < roman.size(); i++)
        {
            mapRomanInt.emplace(roman[i], value[i]);
        }

        int result = 0;
        int i = 0;
        while (i < s.size() - 1)
        {
            // check the first two Roman characters first
            // if exits, use this number
            if (mapRomanInt.find(s.substr(i, 2)) != mapRomanInt.end())
            {
                result += mapRomanInt[s.substr(i, 2)];
                i++;
            }
            else
            {
                result += mapRomanInt[s.substr(i, 1)];
            }
            i++;
        }

        // add the last Roman number
        if (i == s.size() - 1)
        {
            result += mapRomanInt[s.substr(i, 1)];
        }

        return result;
    }
}