#pragma once
#include "stdafx.h"

// Given two strings S and T, determine if they are both one edit distance apart.
// The edit includes: delete, insert and replace
// all these operations can only happ once

// Thought:
// the brute force solution is using "EditDistance" dp solution to get all the edit distance 
// and comparing with 1, this takes O(n^2) both time and space.
// However; there are more constraints if only allows 1 edit distance.
// 1. |s.size() - t.size()| <= 1
// 2. if s.size() == t.size(), once we find a mismatch character s[i], t[j]; we can only replace.
// 3. if s.size() < t.size(), for mismatch, only insert. and only delete if s.size() > t.size().
namespace leetcode
{
    bool isOneEditDistance(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        int length = min(m, n);
        for (int i = 0; i < length; i++)
        {
            if (s[i] == t[i])
                continue;

            if (m == n)
                return s.substr(i + 1) == t.substr(i + 1);
            else if (m > n)
                return s.substr(i + 1) == t.substr(i);
            else
                return s.substr(i) == t.substr(i + 1);
        }

        return abs(m - n) == 1;
    }
}