// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>

using namespace std;

bool isHappy(int n)
{
    std::unordered_set<int> set;
    while (set.find(n) == set.end())
    {
        if (n == 1)
            return true;

        set.emplace(n);

        // compute sqrt of each digit
        int sum = 0;
        while (n > 0)
        {
            auto t = n % 10;
            n = n / 10;
            sum += t*t;
        }
        n = sum;
    }

    return false;
}
int _tmain(int argc, _TCHAR* argv[])
{
    
    return 0;
}