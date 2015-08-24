#pragma once
#include "stdafx.h"

namespace leetcode
{
    //Given a non - negative integer num, repeatedly add all its digits until the result has only one digit.
    //    For example :
    //Given num = 38, the process is like : 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
    //    Follow up :
    //Could you do it without any loop / recursion in O(1) runtime ?
    int addDigits(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            int x = num % 10;
            sum += x;
            num /= 10;
            if (num == 0 && sum > 9)
            {
                num = sum;
                sum = 0;
            }
        }
        return sum;
    }

}
