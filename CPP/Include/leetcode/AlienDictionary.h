#pragma once
#include "stdafx.h"

//here is a new alien language which uses the latin alphabet.
//However, the order among letters are unknown to you.
//
//You receive a list of words from the dictionary, where words are sorted lexicographically 
//by the rules of this new language.Derive the order of letters in this language.
//
//For example,
//Given the following words in dictionary,
//
//[
//    "wrt",
//    "wrf",
//    "er",
//    "ett",
//    "rftt"
//]
//
//The correct order is : "wertf".
//
//Note :
//
//    You may assume all letters are in lowercase.
//    If the order is invalid, return an empty string.
//    There may be multiple valid order of letters, return any one of them is fine.

namespace leetcode
{
    void dfs()
    {

    }

    string alienOrder(vector<string>& words) 
    {
        string order = "";
        if (words.empty())
            return order;

        int length = max_element(words.begin(), words.end(), [&](string& s1, string& s2) {
            return s1.size() < s2.size();
        })->size();

        vector<bool> visited(26, false);

        return order;
    }
}