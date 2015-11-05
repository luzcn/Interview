#pragma once
#include "stdafx.h"

/**
*  Given n non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
namespace TrappingRainingWater
{
	/*
	for input: A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] N = sizeof(A)
	*
	* compute B[] where B[i] = Max(A[0..i]) Calculate Max bar height from node 0 - i
	* B = [0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
	*
	* compute C[] where C[i] = Max(A[i..N]) Calculate Max bar height from node i - n
	* C = [3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
	*
	* compute D[] where D[i] = Min(B[i], C[I]) Calculate Min bar height between bar
	* before Vs after i, coz only this much water could fill
	* D = [0, 1, 1, 2, 2, 2, 2, 3, 2, 2, 2, 1]
	*
	* compute E[] where E[i] = D[i] - A[i] Subtract the height of bar i from Max water
	* bars could hold before Vs after E[i] = [0, 0, 1, 0, 1, 2, 1, 0, 0, 1, 0, 0]
	*
	* the answer is sum(E[i]) the complexity is O(N)
	**/
	int trap(int A[], int n)
	{
		int result = 0;
		if (n <= 0)
			return 0;

		vector<int> left(n);
		vector<int> right(n);
		left[0] = A[0];
		right[n - 1] = A[n - 1];

		// for ith element, find the maximun value from 0...i
		for (int i = 1; i < n; i++)
		{
			if (A[i] > left[i - 1])
			{
				left[i] = A[i];
			}
			else
			{
				left[i] = left[i - 1];
			}
		}

		// // for ith element, find the maximun value from n-1 ... i
		for (int i = n - 2; i >= 0; i--)
		{
			if (A[i] > right[i + 1])
			{
				right[i] = A[i];
			}
			else
			{
				right[i] = right[i + 1];
			}
		}

		vector<int> min_list(n);
		for (int i = 0; i < n; i++)
		{
			min_list[i] = std::min(left[i], right[i]);
		}

		//vector<int> sum(n);
		for (int i = 0; i < n; i++)
		{
			//sum[i] = A[i] - min_list[i];
			result += min_list[i] - A[i];
		}


		return result;
	}
}