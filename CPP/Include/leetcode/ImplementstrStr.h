#pragma  once
#include "stdafx.h"

/*
 *	 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
namespace StrStr
{
    bool isSubStr(string s, string t)
    {
        if (s.empty() && !t.empty())
            return false;

        int m = s.size();
        int n = t.size();
        if (m < n)
            return false;

        bool issubstr = true;

        for (int i = 0; i <= m - n; ++i)
        {
            issubstr = true;
            for (int j = 0; j < n; ++j)
            {
                if (s[i + j] != t[j])
                {
                    issubstr = false;
                    break;
                }
            }
            if (issubstr)
                return true;
        }
        return false;
    }
}