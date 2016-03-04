#pragma once
#include "stdafx.h"

// Write a function to generate the generalized abbreviations of a word.
//
// Example:
//
// Given word = "word", return the following list(order does not matter) :
//
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

namespace leetcode
{
    void dfs(const string& word, vector<string>& result, string& current, int start)
    {
        if (start >= word.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= word.size(); i++)
        {
            int dist = i - start;
            if (dist > 0)
                current.append(to_string(dist));

            if (i < word.size())
                current.push_back(word[i]);

            dfs(word, result, current, i + 1);

            if (i < word.size())
                current.pop_back();
            if (dist > 0)
                current.resize(current.size() - to_string(dist).size());
        }
    }

    vector<string> generateAbbreviations(string word)
    {
        vector<string> result;
        string current;

        dfs(word, result, current, 0);

        return result;
    }
}