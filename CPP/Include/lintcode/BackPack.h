#pragma once
#include "stdafx.h"

// Given n items with size Ai, an integer m denotes the size of a backpack.How full you can fill this backpack ?
// Example
//
// If we have 4 items with size[2, 3, 5, 7], the backpack size is 11, we can select[2, 3, 5], 
// so that the max size we can fill this backpack is 10. If the backpack size is 12.
// we can select[2, 3, 7] so that we can fulfill the backpack.
// You function should return the max size we can fill in the given backpack.

namespace lintcode
{
    int backPackRec(vector<int>& A, int m, int i)
    {
        if (i == A.size())
            return 0;
        if (A[i] > m)
            return backPackRec(A, m, i + 1);

        return std::max(A[i] + backPackRec(A, m - A[i], i + 1), backPackRec(A, m, i + 1));
    }

    int backPackDP(vector<int>& A, int m)
    {
        int n = A.size();
        vector<vector<int>> M(m + 1, vector<int>(A.size() + 1));
        M[0][0] = 0;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= A.size(); j++)
            {
                if (i >= A[j - 1])
                {
                    M[i][j] = std::max((A[j - 1] + M[i - A[j - 1]][j - 1]), M[i][j - 1]);
                }
                else
                    M[i][j] = M[i][j - 1];
            }
        }
        return M[m][A.size()];
    }
    int backPack(int m, vector<int> A)
    {
        // write your code here
        if (A.empty())
            return 0;

        return backPackRec(A, m, 0);
    }
}
