#pragma once
#include "stdafx.h"

//Numbers can be regarded as product of its factors.For example,
//
//8 = 2 x 2 x 2;
//  = 2 x 4.
//
//Write a function that takes an integer n and return all possible combinations of its factors.
//
//Note:
//
//Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
//You may assume that n is always positive.
//Factors should be greater than 1 and less than n.
//
//Examples :
//input : 1
//output :
//
//[]
//
//input : 37
//output :
//
//[]
//
//input : 12
//output :
//
//[
//    [2, 6],
//    [2, 2, 3],
//[3, 4]
//]
//
//input: 32
//output :
//
//[
//    [2, 16],
//    [2, 2, 8],
//[2, 2, 2, 4],
//[2, 2, 2, 2, 2],
//[2, 4, 4],
//[4, 8]
//]
//

namespace leetcode
{
    class Solution {
    public:
        vector<vector<int>> getFactors(int n)
        {
            if (n <= 2)
                return{};

            vector<vector<int>> result;
            vector<int> current;

            dfs(n, result, current, 2);

            return result;
        }

    private:
        void dfs(int n, vector<vector<int>>& result, vector<int>& current, int index)
        {
            if (n == 1)
            {
                if (current.size() > 1)
                    result.push_back(current);

                return;
            }

            for (int i = index; i <= n; i++)
            {
                if (n % i)
                    continue;

                current.push_back(i);
                dfs(n / i, result, current, i);
                current.pop_back();
            }
        }
    };
}