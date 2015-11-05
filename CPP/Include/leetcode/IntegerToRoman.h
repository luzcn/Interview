#pragma once
#include "stdafx.h"

// 		String[] roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        //int[] value = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.
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
        vector<string> roman { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> value { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        string res = "";

        int index = 0;
        while (num > 0 && index < value.size())
        {
            if (num >= value[index])
            {
                res += roman[index];
                num -= value[index];
            }
            else
                index++;
        }

        return res;
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
    int romanToInt(string s)
    {
        vector<string> roman{ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        vector<int> value{ 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        unordered_map<string, int> map;
        for (int i = 0; i < roman.size(); i++)
        {
            map.emplace(roman[i], value[i]);
        }

        int res = 0;
        int index = 0;
        while (!s.empty())
        {
            string first = s.substr(0, 1);
            string second = "";

            if (s.size() > 1)
                second = s.substr(1, 1);

            if (map.find(first + second) != map.end())
            {
                res += map[first + second];
                if (second != "")
                    s = s.substr(2);
                else
                    s = s.substr(1);
            }
            else if (map.find(first) != map.end())
            {
                res += map[first];
                s = s.substr(1);
            }
        }

        return res;
    }
}