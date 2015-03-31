#pragma  once
#include "stdafx.h"

namespace Candy
{
    using namespace std;

    int candy(vector<int> &ratings)
    {
        size_t n = ratings.size();
        vector<int> candies(n, 1);

        // Start from the begining, find the contiguous increasing subarray.
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (ratings[i] < ratings[i + 1])
            {
                candies[i + 1] = candies[i] + 1;
            }
        }

        // Starting form the end, find the contiguous increasing subarray.
        for (size_t i = n - 1; i > 0; --i)
        {
            if (ratings[i] < ratings[i - 1])
            {
                if (candies[i - 1] < candies[i] + 1)  // If it is already large enough, no need to change.
                {
                    candies[i - 1] = candies[i] + 1;
                }
            }
        }

        // find the summary.
        int sum = 0;
        for (const auto& c : candies)
        {
            sum += c;
        }

        return sum;
    }
}