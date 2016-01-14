#pragma  once

#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.
//For example, given s = "aab",
//Return
//
//[
//    ["aa", "b"],
//    ["a", "a", "b"]
//]
namespace leetcode
{
    bool isPalindrome(const string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    // DFS 
    void partitionRec(string s, int start, vector<vector<string>>& solutions, vector<string>& current)
    {
        if (start == s.size()) // find a solution
        {
            solutions.push_back(current);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (isPalindrome(s, start, i))
            {
                current.push_back(s.substr(start, i - start + 1));
                partitionRec(s, i + 1, solutions, current);
                current.pop_back();
            }
        }
    }

    //We can use DFS to solve these find all the solutions problems. similar to wordbreak
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> sol;
        vector<string> current;

        partitionRec(s, 0, sol, current);

        return sol;
    }

    //  Given a string s, partition s such that every substring of the partition is a palindrome.
    //
    //  Return the minimum cuts needed for a palindrome partitioning of s.
    //
    //  For example, given s = "aab",
    //  Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.
    // 
    //  http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html
    //int minCut(string s)
    //{
    //    int len = s.size();
    //    vector<int> D(len + 1, 0);
    //    vector<vector<bool>> P(len, vector<bool>(len, false));

    //    // The worst case is 
    //    for (int i = 0; i <= len; i++)
    //    {
    //        D[i] = len - i - 1;
    //    }

    //    for (int i = len - 1; i >= 0; i--)
    //    {
    //        for (int j = i; j < len; j++)
    //        {
    //            if (s[i] == s[j] && (i == j || i + 1 == j || P[i + 1][j - 1]))
    //            {
    //                P[i][j] = true;
    //                D[i] = min(D[i], 1 + D[j + 1]);
    //            }
    //        }
    //    }

    //    return D[0];
    //}

    int minCut(string s)
    {
        if (s.size() <= 1)
            return 0;

        vector<int> D(s.size() + 1, 0);
        vector<vector<bool>> P(s.size(), vector<bool>(s.size(), false));

        for (int i = 0; i < s.size(); i++)
        {
            D[i + 1] = i;
        }
        D[0] = -1;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (s[i] == s[j] && (i == j || j + 1 == i || P[j + 1][i - 1]))
                {
                    P[j][i] = true;

                    D[i + 1] = min(D[i + 1], 1 + D[j]);
                }
            }
        }

        return D[s.size()];
    }

}
