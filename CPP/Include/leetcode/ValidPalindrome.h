#pragma once
#include "stdafx.h"
#include <ctype.h>
namespace leetcode
{
    //  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    //    For example,
    //    "A man, a plan, a canal: Panama" is a palindrome.
    //    "race a car" is not a palindrome.
    // 
    // some helpful crt libs:
    // tolower(char c), isdigit(char c), isalpha(char c)
    bool isPalindrome(string s) 
    {
        if (s.empty())
            return true;

        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (!isalpha(s[i]) && !isdigit(s[i]))
                i++;
            else if (!isalpha(s[j]) && !isdigit(s[j]))
                j--;           
            else
            {
                char h = tolower(s[i]);
                char t = towlower(s[j]);
                if (h != t)
                    return false;
                i++;
                j--;
            }
        }

        return true;
    }
}