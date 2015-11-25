#pragma once
#include "stdafx.h"
#include <sstream>

//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non - empty word in str.
//
//Examples:
//
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//
//Notes :
//    You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
namespace leetcode
{
    vector<string> split(const string& str, char delim)
    {
        std::stringstream ss(str);
        string item;
        vector<string> elements;
        while (std::getline(ss, item, delim))
        {
            elements.push_back(item);
        }

        return elements;
    }


    bool wordPattern(string pattern, string str)
    {
        if (pattern.empty())
        {
            return str.empty();
        }

        std::unordered_map<char, string> map;
        std::unordered_map<string, char> map2;
        vector<string> strList = split(str, ' ');
        if (strList.size() != pattern.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string s = strList[i];

            if (map.find(c) == map.end())
            {
                map.emplace(c, s);
            }
            else if (map[c] != s)
            {
                return false;
            }

            if (map2.find(s) == map2.end())
            {
                map2.emplace(s, c);
            }
            else if (map2[s] != c)
            {
                return false;
            }
        }

        return true;
    }

    // Word Pattern II
    // Given a pattern and a string str, find if str follows the same pattern.
    //
    // Here follow means a full match, such that there is a bijection between a 
    // letter in pattern and a non-empty substring in str.
    //
    // Examples:
    //
    //    pattern = "abab", str = "redblueredblue" should return true.
    //    pattern = "aaaa", str = "asdasdasdasd" should return true.
    //    pattern = "aabb", str = "xyzabcxzyabc" should return false.
    //
    //Notes:
    //You may assume both pattern and str contains only lowercase letters.
#if 0
    bool dfs(const string& pattern, string& str, int start, vector<string>& words, int count)
    {
        if (count == 0 && start == str.size())
        {
            std::unordered_map<char, string> map;
            std::unordered_map<string, char> map2;

            // check correctness
            for (int i = 0; i < pattern.size(); i++)
            {
                char c = pattern[i];
                string s = words[i];

                if (map.find(c) == map.end())
                {
                    map.emplace(c, s);
                }
                else if (map[c] != s)
                {
                    return false;
                }

                if (map2.find(s) == map2.end())
                {
                    map2.emplace(s, c);
                }
                else if (map2[s] != c)
                {
                    return false;
                }
            }

            return true;
        }

        for (int i = start; i < str.size(); i++)
        {
            string s = str.substr(start, i - start + 1);
            words.push_back(s);
            if (dfs(pattern, str, i + 1, words, count - 1))
            {
                return true;
            }
            words.pop_back();
        }

        return false;
    }
#endif

    bool match(const string& pattern, string str,
        unordered_map<char, string>& map, unordered_set<string>& set, int start, int count)
    {
        if (count == pattern.size() && start == str.size())
            return true;

        if (count >= pattern.size())
            return false;

        char c = pattern[count];

        // if we already have set the pattern with some string s
        // check if we can find any substring which can match this s
        if (map.find(c) != map.end())
        {
            string s = map[c];
            if (s != str.substr(start, s.size()))
                return false;

            return match(pattern, str, map, set, start + s.size() + 1, count + 1);
        }

        for (int i = start; i < str.size(); i++)
        {
            string s = str.substr(start, i - start + 1);

            // here, the pattern "c" must have no string assigned yet,
            // but string s has been assigned to some pattern, 
            // so this s is not a valid candicate, keep searching.
            if (set.find(s) != set.end())
            {
                continue;
            }

            set.insert(s);
            map.emplace(c, s);

            if (match(pattern, str, map, set, i + 1, count + 1))
            {
                return true;
            }
            set.erase(s);
            map.erase(c);
        }
        return false;
    }

    bool wordPatternMatch(string pattern, string str)
    {
        if (pattern.empty())
        {
            return str.empty();
        }

        vector<string> words;
        unordered_map<char, string> map1;
        unordered_set<string> st;

        return match(pattern, str, map1, st, 0, 0);
    }
}