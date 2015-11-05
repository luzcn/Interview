#pragma once
#include "stdafx.h"

// Pattern Mathing problem.
// Given an input text string s and a string pattern, 
// find the substring that can match this pattern.
// Assume, the inputs are always valid.
namespace careercup
{
    // brute force solution O(m*n) time
    int PatternMatchingBF(string s, string p)
    {
        int i = 0; // index in s
        int j = 0; // index in p

        for (i = 0; i < s.size() - p.size(); i++)
        {
            for (j = 0; j < p.size(); j++)
            {
                if (s[i + j] != p[j])
                    break;
            }
            if (j == p.size())
                return i;
        }
        return -1;
    }

    // KMP solution
    namespace KMP
    {
        //  pre-process the pattern string, compute an auxiliary array lps[] which has identical size with the pattern.
        //  for each i in [0...m-1], lps[i] = the longest size of prefix which is also a suffix of substring p[0...i].
        void computeFailureFunction(string& p, vector<int>& lps)
        {
            // the first element is always 0.
            lps[0] = 0;

            // use this len to track the longest prefix which is also a suffix
            int len = 0;
            int j = 1;
            while(j < p.size())
            {
                if (p[j] == p[len])
                {
                    lps[j] = ++len;
                    j++;
                }
                else
                {
                    if (len == 0)
                    {
                        lps[j] = 0;
                        j++;
                    }
                    else
                        len = lps[len - 1];   // This is tricky. Consider the example "aaacaaaa" and i = 7.
                }
            }
        }

        // for each i in [0...n-1], j in [0...m-1], if s[i] != p[j], set j = lps[j-1].
        int kmp(string s, string p)
        {
            vector<int> lps(p.size());
            computeFailureFunction(p, lps);

            int i = 0;
            int j = 0;

            while (i < s.size())
            {
                if (s[i] == p[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if (j == 0)
                        i++;
                    else
                        j = lps[j - 1];
                }

                if (j == p.size())
                    return i - j;   // i has moved to the end of the mached string.
            }

            return -1;
        }
    }
}
