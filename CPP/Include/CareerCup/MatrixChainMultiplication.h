#pragma once
#include "stdafx.h"

// Given a chain of matrix dimension, find out the minimum cost of matrix chain multiplication.
// Adding parenthesis will change the multiplication cost. 
// find out a way to add parenthesis to minimize the cost.
// 
// The matrix multiplication is defined as: 
// if A1 is p*q dimension, A2 is q*r dimension. the cost A1*A2 is p*q*r

// thought: define m[i...j] as the minimum cost of multiplication A[i]A[i+1]..A[j]. 
// if i == j, the cost is trivially 0.
// split the problem to subproblems, A[i]A[i+1]...A[k] and A[k+1]...A[j], where i<=k<j
// then m[i..j] is the minimum cost of computing the sub multiplication of A[i...k]  and A[k+1...j] 
// plus the cost of multiply these two matrics.
// so m[i..j] = the min of "getcost(i,k)+getcost(k+1, j) + p[i-1]*p[k]*p[j] " for each k in [i...j).
namespace careercup
{
    int getMinCostRec(vector<int>&p, int i, int j)
    {
        if (i == j)
            return 0;

        int q = INT_MAX;
        for (int k = i; k < j; k++)
        {
            q = min(q, getMinCostRec(p, i, k) + getMinCostRec(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
        }
        return q;
    }

   /* int getMinCostDP(vector<int>&p)
    {
        vector<vector<int>> M(p.size(), vector<int>(p.size(), 0));
        vector<vector<int>> S(p.size(), vector<int>(p.size(), 0));


    }*/
    int getMinCost(vector<int>& p)
    {

    }
}