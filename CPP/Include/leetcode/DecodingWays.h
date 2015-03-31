#pragma once

#include "stdafx.h"

/***
 *	 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26

 Given an encoded message containing digits, determine the total number of ways to decode it.

 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

 The number of ways decoding "12" is 2.
 */

namespace DecodingWays
{
    using namespace std;

    /***
     *	The recursive solution.
     */
    void DecodingRec(string s, int& ways)
    {
        if (s.empty())
        {
            ways++;
            return;
        }

        auto value = s[0];
        if (value <= '9' && value > '0')
        {
            DecodingRec(s.substr(1), ways);
        }

        if (s.size() > 1)
        {
            auto value1 = s[0];
            auto value2 = s[1];

            if (value1 == '1')
            {
                DecodingRec(s.substr(2), ways);
            }
            else if (value1 == '2' && value2 <= '6' && value2 >= '0')
            {
                DecodingRec(s.substr(2), ways);
            }
        }
    }


    /***
     *	The DP solution
     *	http://blog.csdn.net/worldwindjp/article/details/19938131
     */
    int DecodingDP(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); ++i)
        {
            if (s[i - 1] != '0')
            {
                dp[i] = dp[i - 1];
            }

            if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6' && s[i - 1] >= '0')
            {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size()];
    }

    int numDecodings(string s)
    {
        if (s.empty())
            return 0;

        if (s[0] == '0')
            return 0;

        int ways = 0;
        DecodingRec(s, ways);

        return ways;
    }
}