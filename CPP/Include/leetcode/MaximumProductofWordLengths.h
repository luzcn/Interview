#pragma once
#include "stdafx.h"

// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
// You may assume that each word will contain only lower case letters.If no such two words exist, return 0.
//
//Example 1:
//
//    Given["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//        Return 16
//        The two words can be "abcw", "xtfn".
//
//        Example 2:
//
//    Given["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//        Return 4
//        The two words can be "ab", "cd".
//
//        Example 3:
//
//    Given["a", "aa", "aaa", "aaaa"]
//        Return 0
//        No such pair of words.
//
namespace leetcode
{
    // brute force


    // bit manipulate
    int maxProduct(vector<string>& words)
    {
        size_t max_product = 0;
        vector<int> element(words.size(), 0);

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                element[i] |= 1 << (words[i][j] - 'a');
            }
        }

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (!(element[i] & element[j]))
                {
                    max_product = max(max_product, words[i].size() * words[j].size());
                }
            }
        }

        return max_product;
    }
}

namespace test
{
    bool has_duplicate(string s1, string s2)
    {
        bool visited[26]{ false };

        for (char c : s1)
        {
            visited[c - 'a'] = true;
        }

        for (char c : s2)
        {
            if (visited[c - 'a'])
                return false;
        }

        return true;
    }

    int maxProduct(vector<string>& words)
    {
        size_t max_product = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (!has_duplicate(words[i], words[j]))
                {
                    max_product = max(max_product, words[i].size() * words[j].size());
                }
            }
        }

        return max_product;
    }
}