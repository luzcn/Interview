#pragma once
#include "stdafx.h"

namespace lintcode
{
    class Solution
    {
    public:
        vector<vector<int>> consistentHashing(int n)
        {
            // Write your code here
            if (n == 1)
            {
                return{ { 0,359,1 } };
            }

            vector<vector<int>> range = consistentHashing(n - 1);

            int i = range.size() - 1;
            while (i > 0)
            {
                if (range[i][1] - range[i][0] > range[i - 1][1] - range[i - 1][0])
                    break;

                i--;
            }

            int endPoint = range[i][1];
            range[i][1] = (range[i][0] + endPoint) / 2;

            //range.insert(range.begin() + i + 1, { range[i][1] + 1, endPoint, n });
            range.push_back({ range[i][1] + 1, endPoint, i + 1 });

            return range;
        }

    };
}