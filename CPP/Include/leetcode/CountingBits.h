#pragma once
#include "stdafx.h"

// Given a non negative integer number num.
// For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation 
// and return them as an array.
//
// Example:
// For num = 5 you should return[0, 1, 1, 2, 1, 2].
//
// Follow up :
//
// It is very easy to come up with a solution with run time O(n*sizeof(integer)).
// But can you do it in linear time O(n) / possibly in a single pass ?
// Space complexity should be O(n).


namespace leetcode
{
    vector<int> countBits(int num)
    {
        vector<int> result{ 0 };

        for (int i = 1; i <= num; i++)
        {
            int toMinus = 0;
            int n = i - 1;
            
            while (n > 0 && (n & 1))
            {
                toMinus++;
                n = n >> 1;
            }

            result.push_back(result.back() - toMinus + 1);
        }
        
        return result;
    }
}