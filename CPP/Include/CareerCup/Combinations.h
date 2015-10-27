#pragma once
#include "stdafx.h"

namespace careercup
{
	/**
		 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

		 For example,
		 If n = 4 and k = 2, a solution is:

		 [
		 [2,4],
		 [3,4],
		 [2,3],
		 [1,2],
		 [1,3],
		 [1,4],
		 ]
		 */
    void combineRec(const int& n, const int& k, vector<vector<int>>& result,
        vector<int>& current, int index)
    {
        if (current.size() == k)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i <= n; i++)
        {
            current.push_back(i);
            combineRec(n, k, result, current, i + 1);
            current.pop_back();
        }
    }

	vector<vector<int>> combine(int n, int k)
	{
        vector<vector<int>> result;
        vector<int> current;

        combineRec(n, k, result, current, 1);

        return result;

	}
}