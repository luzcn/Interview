#pragma once
#include "stdafx.h"

namespace HouseRobber
{
    void robRec(vector<int>& num, vector<bool>& canRob, int index, int& res)
    {
        if (index >= num.size())
        {
            return;
        }

        for (int i = index; i < num.size() - 1; i++)
        {
            if (canRob[i] && canRob[i + 1])
            {
                if (num[i] > canRob[i + 1])
                {
                    res += num[i];
                    canRob[i] = false;
                    canRob[i + 1] = false;
                    robRec(num, canRob, i + 1, res);
                }
                else
                {
                    res += num[i + 1];
                    canRob[i] = false;
                    canRob[i + 1] = false;
                    if (i + 2 < num.size())
                    {
                        canRob[i + 2] = false;
                    }
                    robRec(num, canRob, i + 3, res);
                }
            }
        }
    }

    int rob(vector<int> &num)
    {
        if (num.size() == 0)
            return 0;
        int res = 0;
        vector<bool> canRob(num.size(), { true });

        robRec(num, canRob, 0, res);

        return res;
    }
}
