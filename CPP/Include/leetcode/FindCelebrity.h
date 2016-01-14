#pragma once
#include "stdafx.h"
//Find the Celebrity
//
// Suppose you are at a party with n people(labeled from 0 to n - 1) and among them, there may exist one celebrity.
// The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
//
// Now you want to find out who the celebrity is or verify that there is not one.
// The only thing you are allowed to do is to ask questions like : "Hi, A. Do you know B?" to get information of whether A knows B.
// You need to find out the celebrity(or verify there is not one) by asking as few questions as possible(in the asymptotic sense).
//
// You are given a helper function bool knows(a, b) which tells you whether A knows B.
// Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.
//
// Note : There will be exactly one celebrity if he/she is in the party.
// Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1. 
// http://www.geeksforgeeks.org/the-celebrity-problem/
namespace leetcode
{
    class Solution
    {
    public:
        unordered_map<int, int> relations;

        // the given helper function
        bool knows(int a, int b)
        {
            if (relations[a] == b)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int findCelebrity(int n)
        {
            return findCelebrityStack(n);
        }
    private:
        int findCelebrityBestSolution(int n)
        {
            if (n <= 0)
                return -1;

            int A = 1;
            int B = 2;

            while (B <= n)
            {
                if (knows(A, B))
                {
                    A = B;
                }
                B++;
            }

            for (int i = 1; i <= n; i++)
            {
                if (A != i)
                {
                    if (knows(A, i) || !knows(i,A))
                        return -1;
                }
            }

            return A;
        }
        // stack solution
        // - if A knows B, A cannot be celebrity, discard A, save B as candidate
        // - if A does not know B, B cannot be celebrity, discard B keep use A as candidate.
        int findCelebrityStack(int n)
        {
            stack<int> stack;
            for (int i = 1; i <= n; i++)
            {
                stack.push(i);
            }

            while (stack.size() > 1)
            {
                int a = stack.top();
                stack.pop();

                int b = stack.top();
                stack.pop();

                if (knows(a, b))
                {
                    stack.push(b);
                }
                else
                {
                    stack.push(a);
                }
            }

            return stack.top();
        }


        // recursive solution
        // assume we alreay have an optimal solution for (1...n-1) people, 
        // what happens if we add the nth person to this solution?
        // 1. OPT(n-1) knows n, then we need to check if n knows any one in these (1...n-1)
        // 2. OPT(n-1) does not know n, then OPT(n-1) is the celebrity.
        // T(n) = T(n-1) + O(n), so O(n^2) time 
        int findRec(int n)
        {
            if (n == 1)
                return n;

            if (n == 2);
            {
                if (knows(1, 2) && !knows(2, 1))
                    return 2;

                if (knows(2, 1) && !knows(1, 2))
                    return 1;
            }

            auto OPT = findRec(n - 1);
            if (OPT != -1 && !knows(OPT, n))
            {
                return OPT;
            }
            else
            {
                for (int i = 1; i < n; i++)
                {
                    if (knows(n, i))
                        return -1;
                }
                return n;
            }
        }

        // member
    };
}