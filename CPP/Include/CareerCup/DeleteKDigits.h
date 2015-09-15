#pragma once

#include "stdafx.h"

/**

Given a number, can you remove k digits from the number so that the new formatted number is smallest possible.
input: n = 1432219, k = 3
output: 1219
*/

namespace careercup
{
    // greedy solution,
    // assume the the length of digits > k, and n > 0.
    // from left to right, if find any digit greater than the first digit, delete this digit otherwise delete the first digit.
    // 
    // This solution does not work for negative numbers.
    // http://xinpeng.me/?p=402
    int removeK(int n, int k)
    {
        // put the digits of n to an array
        vector<int> list;

#if 0  // we can push back the last element, then reverse the vector
        int div = 10;
        while (n / div > 10)
        {
            div *= 10;
        }
        while (n != 0)
        {
            auto first = n / div;
            n = n %div;
            div /= 10;
            list.push_back(first);
        }
#endif // 0 
        while (n != 0)
        {
            list.push_back(n % 10);
            n /= 10;
        }

        std::reverse(list.begin(), list.end());
        int count = 0;
        while (count < k)
        {
            bool find_large = false;
            for (int i = 1; i < list.size(); i++)
            {
                auto t = list.front();

                if (list[i] > t)
                {
                    find_large = true;
                    list.erase(list.begin() + i);
                    break;
                }
            }
            if (!find_large)
            {
                list.erase(list.begin());
            }
            count++;
        }

        int result = 0;
        for (auto e : list)
        {
            result = result * 10 + e;
        }
        return result;
    }
}