#pragma once
#include "stdafx.h"

/***
 *	 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
 (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character

 http://www.programcreek.com/2013/12/edit-distance-in-java/

 the idea is: ed("", s) || ed(s,"") = s.size();
 ed(s1,s2) = ed(s1+x, s2+y)
 1. = ed(s1, s2) if ch1 == ch2
 2. if ch1 != ch2
 - Insert ch1 to s2, 1 + ed(s1, s2+ch2)
 - Delete ch2 from s2, 1+ ed(s1, s2
 */
namespace leetcode
{
    /***
     *	Recursive solution
     */
    int minDistanceRec(string& s, string& t)
    {
        if (s.empty())
        {
            return t.size();
        }
        if (t.empty())
        {
            return s.size();
        }

        if (s[0] == t[0])
        {
            return minDistanceRec(s.substr(1), t.substr(1));
        }

        return min(min(1 + minDistanceRec(s.substr(1), t), 1 + minDistanceRec(s, t.substr(1))), 1 + minDistanceRec(s.substr(1), t.substr(1)));
    }


    int minDistance_DP(string& s, string& t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));

        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else
                {
                    if (s[i - 1] == t[j - 1])  // if the two character are equavelent.
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = min(min(1 + dp[i - 1][j], 1 + dp[i][j - 1]), 1 + dp[i - 1][j - 1]);
                    }
                }

            }
        }

        return dp[s.size()][t.size()];
    }

    int minDistance(string s, string t)
    {

    }
}