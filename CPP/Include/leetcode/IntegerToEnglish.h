#pragma once
#include "stdafx.h"
//#include <unordered_map>

//Convert a non - negative integer to its english words representation.Given input is guaranteed to be less than 231 - 1.
//
//For example,
//
//123 -> "One Hundred Twenty Three"
//12345 -> "Twelve Thousand Three Hundred Forty Five"
//1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//
//Hint:
//
//Did you see a pattern in dividing the number into chunk of words ? For example, 123 and 123000.
//Group the number by thousands(3 digits).You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
//There are many edge cases.What are some good test cases ? Does your code work with input such as 0 ? Or 1000010 ? (middle chunk is zero and should not be printed out)

namespace leetcode
{
    class Solution
    {
    public:
        Solution()
        {
            map_num_word = {
                {1," One"},
                {2," Two"},
                {3, " Three"},
                {4, " Four"},
                {5, " Five"},
                {6, " Six"},
                {7, " Seven"},
                {8, " Eight"},
                {9, " Nine"},
                {10, " Ten"},
                {11, " Eleven"},
                {12, " Twelve"},
                {13, " Thirteen"},
                {14, " Forteen"},
                {15, " Fifteen"},
                {16, " Sixteen"},
                {17, " Seventeen"},
                {18, " Eighteen"},
                {19, " Nineteen"},
                {20, " Twenty"},
                {30, " Thirty"},
                {40, " Forty"},
                {50, " Fifty"},
                {60, " Sixty"},
                {70, " Seventy"},
                {80, " Eighty"},
                {90, " Ninety"},
            };
        }

        string numberToWords(int num)
        {
            if (num == 0)
                return "Zero";

            string result;
            int count = 0;
            while (num > 0)
            {
                int remains = num % 1000;
                num /= 1000;

                result = processing(remains) + result;
                if (num > 0)
                {
                    switch (++count)
                    {
                    case 1:
                        if (num % 1000 > 0)
                            result = " Thousand" + result;
                        break;
                    case 2:
                        if (num % 1000 > 0)
                            result = " Million" + result;
                        break;
                    case 3:
                        if (num % 1000 > 0)
                            result = " Billion" + result;
                        break;
                    default:
                        break;
                    }
                }
            }
            return result.substr(1);
        }
    private:
        string processing(int n)
        {
            int m = n % 100;
            n /= 100;
            string result;

            if (n > 0)
            {
                string temp = map_num_word[n];
                result.append(temp + " Hundred");
            }

            if (m > 0)
            {
                if (map_num_word.find(m) != map_num_word.end())
                {
                    result.append(map_num_word[m]);
                }
                else
                {
                    int t = m % 10;
                    m = m - t;

                    result.append(map_num_word[m]);
                    if (t > 0)
                    {
                        result.append(map_num_word[t]);
                    }
                }
            }

            return result;
        }

        std::unordered_map<int, string> map_num_word;
    };
}