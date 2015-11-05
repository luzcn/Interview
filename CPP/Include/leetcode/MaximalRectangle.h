#pragma once

#include "stdafx.h"

/**
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/
namespace MaximalRectangle
{
#pragma region BF solution
	bool allones(const vector<vector<int>>& M, int i, int j, int k, int l)
	{
		for (; i <= k; i++)
		{
			for (; j <= l; j++)
			{
				if (M[i][j] != 1)
					return false;
			}
		}
		return true;
	}

	int area(int i, int j, int k, int l)
	{
		if (i > k || j > l)
			return 0;

		return (k - i + 1)*(l - j + 1);
	}
	// Brutal force O(n^6) solution.
	int maximalRectangleBF(vector<vector<int>>& matrix)
	{
		if (matrix.empty())
			return 0;

		int m = matrix.size();
		int n = matrix[0].size();

		int max_area = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = i; k < m; k++)
				{
					for (int l = j; l < n; l++)
					{
						if (allones(matrix, i, j, k, l) && area(i, j, k, l) > max_area)
							max_area = area(i, j, k, l);
					}
				}
			}
		}
		return max_area;
	}

#pragma endregion

#pragma region DP solution

#pragma endregion

}