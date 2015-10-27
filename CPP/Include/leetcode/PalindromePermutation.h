#pragma once
#include "stdafx.h"

//Given a string, determine if a permutation of the string could form a palindrome.
//
//For example,
//"code"->False, "aab"->True, "carerac"->True.
namespace leetcode
{
    bool canPermutePalindrome(string s)
    {
        if (s.size() <= 1)
            return true;

        std::unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (map.find(c) == map.end())
            {
                map.emplace(c, 1);
            }
            else
            {
                map[c]++;
            }
        }

        int count = 0;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second % 2 > 0)
                count++;

            if (count > 1)
                return false;
        }

        return true;
    }


    //  Given a string s, return all the palindromic permutations(without duplicates) of it.
    //  Return an empty list if no palindromic permutation could be form.
    //    For example :
    //  Given s = "aabb", return["abba", "baab"].
    //    Given s = "abc", return[].
    void getPermutation(vector<char>& s, vector<string>& result, string& current, vector<bool>& isUsing)
    {
        if (s.empty())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0 && s[i] == s[i - 1] && !isUsing[i - 1])
                continue;

            isUsing[i] = true;
            current.push_back(s[i]);
            s.erase(s.begin() + i);
            getPermutation(s, result, current, isUsing);
            s.insert(s.begin() + i, current.back());
            current.pop_back();
            isUsing[i] = false;
        }
    }

    vector<string> generatePalindromes(string s)
    {
        vector<string> result;

        if (s.empty())
            return result;

        std::unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (map.find(c) == map.end())
            {
                map.emplace(c, 1);
            }
            else
            {
                map[c]++;
            }
        }

        int count = 0;
        string singleStr = "";
        vector<char> charList;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            int num = it->second;
            if (num % 2 > 0)
            {
                count++;
                if (count > 1)
                    return{};

                singleStr = it->first;
            }

            num /= 2;
            while (num > 0)
            {
                charList.push_back(it->first);
                num--;
            }
        }

        // get all permutation
        string current;
        vector<bool> isUsing(charList.size(), false);
        getPermutation(charList, result, current, isUsing);

        for (string& str : result)
        {
            string temp = str;
            reverse(temp.begin(), temp.end());
            str += singleStr + temp;
        }

        return result;
    }
}