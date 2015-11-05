#pragma  once

#include "stdafx.h"
#include <ctype.h>
/**
 *	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example,
 Given s = "Hello World",
 return 5.
 */
namespace LengthofLastWord
{
    int lengthOfLastWord(const char *s)
    {
        string str = std::string(s);

        // trim the tail 
        while (!str.empty() && isspace(str.back()))
        {
            str.pop_back();
        }

        if (str.empty())
            return 0;

        int r = str.size() - 1;
        int count = 0;

        while (r >= 0)
        {
            if (!isspace(str[r]))
            {
                r--;
                count++;
            }
            else
                break;
        }
        return count;
    }
}