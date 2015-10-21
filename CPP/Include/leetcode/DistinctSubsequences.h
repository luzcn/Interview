#pragma once
#include "stdafx.h"


//  Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//  A subsequence of a string is a new string which is formed from the original string 
//  by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. 
//  (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//  Here is an example :
//  S = "rabbbit", T = "rabbit"
//
//  Return 3.
// Thoughts: the dynamic programming transfer function is : 
//  for i in range [1.. s.size()], j in range [1...t.size()]
//  dp[i][j] = dp[i-1][j]                   if s[i-1] != t[j-1]
//           = dp[i-1][j] + dp[i-1][j-1]    if s[i-1] == t[j-1]
// it has only changed from dp[i-1][*], so we can use a singe array to store the immediate data
namespace leetcode
{

    void print(vector<vector<int>>& dp)
    {
        for (auto i : dp)
        {
            for (auto t : i)
            {
                cout << t << " ";
            }
            cout << endl;
        }
    }
    int numDistinct(string s, string t)
    {
        if (t.empty())
            return 1;

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for (int i = 0; i <= s.size(); i++)
        {
            dp[i][0] = 1;
        }

        print(dp);
        for (int j = 1; j <= t.size(); j++)
        {
            for (int i = 1; i <= s.size(); i++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }


        return dp[s.size()][t.size()];
    }

    // using single array
    // here we need to use the reverse order of t
    int numDistinct2(string s, string t)
    {
        if (t.empty())
            return 1;

        vector<int> dp(t.size() + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = t.size(); j >= 1; j--)
            {
                // if i < j, there is no subsequence available for s(0...i) => t(0...j), since we can only delete.
                if (i >= j)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[j] = dp[j - 1] + dp[j];
                    }
                }
            }
        }

        return dp[t.size()];
    }
}