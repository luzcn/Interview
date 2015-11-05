#pragma once

#include "stdafx.h"

namespace RegularExpressMatching
{
    bool isMatch(const char *s, const char *p)
    {
        if (*p == '\0')
            return *s == '\0';

        // if next character is not "*", current pattern character must match string character
        if (*(p + 1) != '*')
        {
            return (*s == *p || (*p == '.' && *s != '\0')) && isMatch(s + 1, p + 1);
        }

        // next character is "*" and *p can match *s
        while ((*p == *s) || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s, p + 2))
                return true;
            s++;
        }

        // the next character is "*", but *p cannot match *s, 
        // consider the pattern character has 0 appearance.
        return isMatch(s, p + 2);
    }
}