#pragma once
#include "stdafx.h"

//Given two sparse matrices A and B, return the result of AB.
//
//You may assume that A's column number is equal to B's row number.
//
//Example:
//
//A = [
//    [1, 0, 0],
//        [-1, 0, 3]
//]
//
//B = [
//    [7, 0, 0],
//        [0, 0, 0],
//        [0, 0, 1]
//]
//
//
//      | 1 0 0 |       | 7 0 0 |   | 7 0 0 |
//AB =  | -1 0 3 |  x   | 0 0 0 | = | -7 0 3 |
//                      | 0 0 1 |

namespace leetcode
{
    vector<vector<int>> multiplyBF(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        if (A.empty() || B.empty())
            return{};

        //int rowA = A.size();
        //int colA = A[0].size();
        //int rowB = B.size();
        //int colB = B[0].size();

        int m = A.size();
        int n = B[0].size();

        vector<vector<int>> result(m, vector<int>(n, 0));

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < A[0].size(); j++)
                {
                    if (A[i][j] != 0)
                    {
                        result[i][k] += (A[i][j] * B[j][k]);
                    }
                }
            }
        }
        return result;
    }

    // improved
    // A sparse matrix can be represented as a sequence of rows,
    // each of which is a sequence of (column-number, value) pairs of the nonzero values in the row.
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        if (A.empty() || B.empty())
        {
            return{};
        }

        int m = A.size();
        int n = B[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        vector <vector<pair<int, int>>> non_zero;


        for (int i = 0; i < A.size(); i++)
        {
            vector<pair<int, int>> row;
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j])
                {
                    row.push_back({ j, A[i][j] });
                }
            }
            non_zero.push_back(row);
        }

        for (int i = 0; i < m; i++)
        {
            for (int k = 0; k < n; k++)
            {
                for (auto p : non_zero[i])
                {
                    int j = p.first;
                    result[i][k] += p.second * B[j][k];
                }
            }
        }

        return result;
    }
}