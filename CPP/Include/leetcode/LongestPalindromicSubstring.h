#pragma once

#include "stdafx.h"

/**
 *	Given a string S, find the longest palindromic substring in S.
 *
 *	You may assume that the maximum length of S is 1000,
 *	and there exists one unique longest palindromic substring.
 */
namespace LongestPalindromicSubstring
{
    bool isPalidrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    /**
     *	brutal force O(n^3) solution
     */
    string longestPalindrome_Naive(string s)
    {
        if (s.empty())
            return s;

        string result;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isPalidrome(s, i, j))
                {
                    auto current = s.substr(i, j - i + 1);
                    if (current.size() > result.size())
                    {
                        result = current;
                    }
                }
            }
        }

        return result;
    }

#pragma region DP solution, O(n^2) time and space
    //  DP solution, O(n^2) time, O(n^2) space.
    //  Defin DP[i][j] = true, if the substring s[i]...s[j] is palidrom.
    //  So, the transform function is:
    //  DP[i][i] = true;
    //  DP[i][i+1] = true; if s[i] == s[i+1]
    //  DP[i][j] = DP[i+1][j-1] && s[i] == s[j], j-i>1
    string longestPalindrome_DP(string s)
    {
        if (s.empty())
            return s;

        int maxlen = 1;
        int begin = 0;
        int n = s.size();
        vector<vector<bool>> dp(1000, vector<bool>(1000, false));

        // initialze the value
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        // consider the two contigouse character first.
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                begin = i;
                maxlen = 2;
            }
        }

        // We only used half of the DP table.
        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (maxlen > j - i + 1)
                    {
                        maxlen = j - i + 1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin, maxlen);
    }
#pragma endregion



#pragma region O(1) space, O(n^2) time solution
    string extend_from_center(const string& s, int c1, int c2)
    {
        int l = c1, r = c2;
        int n = s.size();

        while (l >= 0 && r <= n - 1 && s[l] == s[r])
        {
            l--;
            r++;
        }

        return s.substr(l + 1, (r - 1) - (l + 1) + 1);
    }
    /**
     *	We observe that a palindrome mirrors around its center.
     *	Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.
     *	 2N-1 but not N centers, the reason is the center of a palindrome can be in between two letters
     *	 "abba" the center can be "bb"
     */
    string longestPalindrome_extend(string s)
    {
        if (s.empty())
            return s;

        int n = s.size();
        string result = s.substr(0, 1);  // a single character slef is a palindrome
        for (int i = 0; i < n - 1; i++)
        {
            auto p1 = extend_from_center(s, i, i);
            if (p1.size() > result.size())
            {
                result = p1;
            }

            auto p2 = extend_from_center(s, i, i + 1);
            if (p2.length() > result.size())
            {
                result = p2;
            }
        }

        return result;
    }
#pragma endregion


#pragma region O(n) solution (Manacher’s algorithm)

    /**
     *	http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
     */
#pragma  endregion
}