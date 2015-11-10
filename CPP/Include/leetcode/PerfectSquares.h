#pragma once
#include "stdafx.h"

// Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
// BFS solution
namespace leetcode
{
    bool isPerfectSqureNumber(int n)
    {
        int sq = std::sqrt(n);
        if (sq * sq == n)
            return true;
        else
            return false;
    }

    int numSquares(int n)
    {
        if (isPerfectSqureNumber(n))
            return 1;

        std::queue<int> que;
        std::queue<int> que_temp;
        que.push(n);
        int distance = 0;

        while (!que.empty())
        {
            int current = que.front();
            que.pop();

            for (int i = 1; i <= current / 2; i++)
            {
                if (isPerfectSqureNumber(i) && isPerfectSqureNumber(current - i))
                {
                    return distance + 2;
                }
                else if (isPerfectSqureNumber(i))
                {
                    que_temp.push(current - i);
                }
            }

            if (que.empty())
            {
                distance++;
                que = que_temp;
                que_temp = std::queue<int>();
            }
        }

        return distance;
    }
}