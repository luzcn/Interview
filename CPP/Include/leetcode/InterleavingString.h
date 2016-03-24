#pragma once
#include "stdafx.h"

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.
namespace leetcode
{
    // Recursive solution
    bool isInterleaveRec(string& s1, string& s2, string& s3, int i, int j, int k)
    {
        if (k >= s3.size())
            return true;

        if (i < s1.size() && s3[k] == s1[i] && j < s2.size() && s3[k] == s2[j])
        {
            return isInterleaveRec(s1, s2, s3, i + 1, j, k + 1) || isInterleaveRec(s1, s2, s3, i, j + 1, k + 1);
        }
        else if (i < s1.size() && s3[k] == s1[i])
        {
            return isInterleaveRec(s1, s2, s3, i + 1, j, k + 1);
        }
        else if (j < s2.size() && s3[k] == s2[j])
        {
            return isInterleaveRec(s1, s2, s3, i, j + 1, k + 1);
        }
        else
        {
            return false;
        }
    }

    bool isInterleaveDP(string& s1, string& s2, string& s3)
    {
        int m = s1.size();
        int n = s2.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // base condition
        // s1, s2 both empty, we can always interleaving an empty string
        dp[0][0] = true;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                {
                    dp[i][j] = true;
                }
                else if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }

        return dp[m][n];
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.empty())
        {
            return s2 == s3;
        }

        if (s2.empty())
        {
            return s1 == s3;
        }

        //return isInterleaveRec(s1, s2, s3, 0, 0, 0);
        return isInterleaveDP(s1, s2, s3);
    }


#pragma region Get All Interleaving Strings
    // Recursive solution, find all interleaving string.
    void getAllInterleavingString(string& s1, string& s2,
        vector<string>& res, int index, int pos)
    {
        if (pos >= s2.size())
        {
            res.push_back(s1);
            return;
        }

        for (int i = index; i <= s1.size(); i++)
        {
            char c = s2[pos];
            auto s = s1.substr(0, i) + c + s1.substr(i);
            getAllInterleavingString(s, s2, res, i + 1, pos + 1);
        }
    }

    vector<string> interleaving(string s1, string s2)
    {
        vector<string> res;
        getAllInterleavingString(s1, s2, res, 0, 0);

        return res;
    }
#pragma endregion
}