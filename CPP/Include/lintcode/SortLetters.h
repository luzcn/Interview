#pragma once
#include "stdafx.h"
namespace lintcode
{
    void sortLetters(string& letter)
    {
        int lower = 'a';
        int upper = 'A';

        int l = 0, r = letter.size() - 1;

        while (r >= 0 && letter[r] >= upper && letter[r] < lower)
        {
            r--;
        }

        while (l <= r)
        {
            if (letter[l] >= upper && letter[l] < lower)    // upper case
            {
                //swpa l, r
                char t = letter[l];
                letter[l] = letter[r];
                letter[r] = t;
                while (r >= l && letter[r] >= upper && letter[r] < lower)
                {
                    r--;
                }
            }
            l++;
        }
    }
}