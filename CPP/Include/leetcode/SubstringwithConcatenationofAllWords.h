#pragma once

#include "stdafx.h"

/*
 *	 You are given a string, S, and a list of words, L, that are all of the same length.
 *	 Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once
 *	 and without any intervening characters.

 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]

 You should return the indices: [0,9].
 (order does not matter).

 The brute force solution:
 1. find all the string permutation constructing from L (e.g. L["foo","bar"] => (foobar, barfoo)).
 - this function is similar to the permutation sequence.
 2. for each string in the permutation, detect if it is a substring in the given string S.
 */
namespace SubstringwithConcatenationofAllWords
{
    // The function to get the permutation sequence.
    void getAllPermutation(vector<int>& list, vector<vector<int>>& sol, vector<int>& current, int index)
    {
        if (list.empty())
        {
            sol.push_back(current);
            return;
        }

        for (int i = index; i < list.size(); ++i)
        {
            current.push_back(list[i]);
            list.erase(list.begin() + i);
            getAllPermutation(list, sol, current, index);
            list.insert(list.begin() + i, current.back());
            current.pop_back();
        }
    }

    vector<int> findSubstring(string S, vector<string> &L)
    {
        int len = L.size();
        vector<int> num_list;
        for (int i = 1; i <= len; ++i)
        {
            num_list.push_back(i);
        }

        // Get all the permuation sequence of numbers from 1...n
        // the num_sequence is the index used to construct the string permutations.
        vector<vector<int>> num_sequence;
        vector<int> current;
        getAllPermutation(num_list, num_sequence, current, 0);

        // Construct all the string permutations.
        vector<string> str_permuations;
        for (auto nums : num_sequence)
        {
            string str("");
            for (auto i : nums)
            {
                str.append(L[i - 1]);
            }
            str_permuations.push_back(str);
        }

        // now, we need to test if all the string permutations are substring of the given string S.
        vector<int> result;
        for (auto& str : str_permuations)
        {
            int m = S.size();
            int n = str.size();
            bool issubstr = true;

            for (int i = 0; i <= m - n; ++i)
            {
                issubstr = true;
                for (int j = 0; j < n; ++j)
                {
                    if (S[i + j] != str[j])
                    {
                        issubstr = false;
                        break;
                    }
                }
                if (issubstr)
                {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
}