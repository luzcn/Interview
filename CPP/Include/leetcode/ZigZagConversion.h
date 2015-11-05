#pragma once

#include "stdafx.h"

namespace ZigZag
{
    string convert(string s, int nRows)
    {
        if (nRows <= 0)
        {
            return s;
        }

        string result;
        int step = (nRows - 1) * 2;

        for (int i = 0; i < nRows; i++)
        {
            // thses tow rows, has no single character column
            if (i == 0 || i == nRows - 1)
            {
                for (int j = i; j < s.size(); j = j + step)
                {
                    result.append(s.substr(j, 1));
                }
            }
            // rows which have single character columns
            else
            {
                int j = i;
                bool flag = true;
                int step1 = 2 * (nRows - 1 - i);
                int step2 = step - step1;

                while (j < s.size())
                {
                    result.append(s.substr(j, 1));
                    if (flag)
                    {
                        j += step1;
                    }
                    else
                    {
                        j += step2;
                    }
                    flag = !flag;
                }
            }
        }
        return result;
    }
}