#pragma  once

#include "stdafx.h"
/**
 *	here are 2 non-negative integers: i and j. Given the following equation, 
 *	find an (optimal) solution to iterate over i and j in such a way that the output is sorted.

 2^i * 5^j

 So the first few rounds would look like this:

 2^0 * 5^0 = 1
 2^1 * 5^0 = 2
 2^2 * 5^0 = 4
 2^0 * 5^1 = 5
 2^3 * 5^0 = 8
 2^1 * 5^1 = 10
 2^4 * 5^0 = 16
 2^2 * 5^1 = 20
 2^0 * 5^2 = 25
 */
void find_result(int k)
{
    // 2^x * 3^y * 5^z
    // find the top kth element in ascending order
    vector<int> v(k);

    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    v[0] = 1;
    for (int i = 1; i < k; ++i)
    {
        int min = std::min(std::min(2 * v[i2], 3 * v[i3]), 5 * v[i5]);
        v[i] = min;
        cout << min << endl;
        if (min == 2 * v[i2])
        {
            i2++;
        }
        if (min == 3 * v[i3])
        {
            i3++;
        }
        if (min == 2 * v[i5])
        {
            i5++;
        }
    }
}