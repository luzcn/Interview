#pragma once
#include "stdafx.h"

//The set[1, 2, 3, …, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"
//
//    Given n and k, return the kth permutation sequence.
//
//    Note: Given n will be between 1 and 9 inclusive.
// http://en.wikipedia.org/wiki/Lehmer_code?
namespace leetcode
{
    // DFS solution
    void dfs(const int& n, const int& k, string& result,
        string& current, vector<bool>& visited, int& count)
    {
        if (current.size() == n)
        {
            if (++count == k)
            {
                result = current;
                return;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                current.push_back(i + '0');

                dfs(n, k, result, current, visited, count);

                current.pop_back();
                visited[i] = false;
            }
        }
    }

    // math solution
    int factorial(int n)
    {
        if (n <= 1)
            return 1;

        return factorial(n - 1)*n;
    }

    string getPermutation(int n, int k)
    {
        string result;
        k--;
        vector<int> nums;

        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        for (int i = n; i >= 1; i--)
        {
            int base = factorial(i - 1);
            int index = k / base;
            k = k % base;

            result.append(to_string(nums[index]));
            nums.erase(nums.begin() + index);
        }

        return result;
    }
}