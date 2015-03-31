#pragma once
#include <unordered_set>

/***
*	Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
namespace WordBreak
{
    using namespace std;


    // The recursive bruteforce solution
    // start from the begining of the input string, find all the substring s.substr(0,i). 
    // if this prefix substring in the dict, shrink the input string s as s.substr(i) and recursive find this suffix substring.
    // base condition: if input string s in the dict return true.
    // if input string s is empty, return false.
    // O(2^n) time
    bool wordbreak(string s, unordered_set<string>& dict)
    {
        if (dict.find(s) != dict.end())
        {
            return true;
        }

        for (int i = 1; i <= s.size(); ++i)
        {
            auto prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end())
            {
                auto result = wordbreak(s.substr(i), dict);
                if (result)
                {
                    return true;
                }
            }
        }
        return false;
    }


    /***
     *  The DP solution.
     *  we can construct an array possible[i] to indicate whether the substring s[0...i] can be segmented by space.
     *
     *  possible[i] = true
     *      1. if s.substr(0, i) in dict
     *      2. if there exists k, 0<k<i; possible[k]==true && s.substring(k, i -k) in dict.
     *
     *	http://fisherlei.blogspot.com/2013/11/leetcode-word-break-solution.html
     */
    bool wordbreak_DP(string s, unordered_set<string>& dict)
    {
        int len = s.size();
        vector<bool> possible(len + 1, false);
        possible[0] = true;

        for (int i = 1; i <= len; ++i)
        {
            for (int k = 0; k < i; ++k)
            {
                possible[i] = possible[k] && (dict.find(s.substr(k, i - k)) != dict.end());
                if (possible[i])
                    break;
            }
        }

        return possible[len];
    }
}