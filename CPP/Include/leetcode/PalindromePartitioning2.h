#pragma  once

#include "stdafx.h"

/***
 *	 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return

 [
 ["aa","b"],
 ["a","a","b"]
 ]

 */
namespace PalindromePartitioning
{
    bool isPalindrome(const string& s)
    {
        int l = 0;
        int r = s.size() - 1;

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

    void partitionRec(string s, int start, vector<vector<string>>& solutions, vector<string>& current)
    {
        if (start == s.size()) // find a solution
        {
            solutions.push_back(current);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            auto prefix = s.substr(start, i - start + 1);
            if (isPalindrome(prefix))
            {
                current.push_back(prefix);
                partitionRec(s, i + 1, solutions, current);
                current.pop_back();
            }
        }
    }
    /***
     *	We can use DFS to solve these find all the solutions problems. similar to wordbreak
     */
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> sol;
        vector<string> current;

        partitionRec(s, 0, sol, current);

        return sol;
    }
}

/*
 *	 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return the minimum cuts needed for a palindrome partitioning of s.

 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 http://fisherlei.blogspot.com/2013/03/leetcode-palindrome-partitioning-ii.html

 */
namespace PalindromePartitioning2
{

}