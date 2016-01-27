#pragma once

#include "stdafx.h"
#include <unordered_map>

// Given two words (start and end), and a dictionary,
// find the length of shortest transformation sequence from start to end, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
//
// For example,
//
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
//
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Note:
//
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

namespace leetcode
{
    // BFS
    int ladderLength(string start, string end, unordered_set<string>& dict)
    {
        if (dict.empty())
            return 0;

        // hash map used to store the distance of candidate word 
        // and indicate if this word has been visited.
        unordered_map<string, int> map_distance;

        // BFS needs a queue to save the candidate data
        queue<string> que;

        que.push(start);
        map_distance[start] = 1;

        while (!que.empty())
        {
            string word = que.front();
            que.pop();

            for (int i = 0; i < word.size(); i++)
            {
                // need to make a copy
                string s = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    s[i] = c;

                    if (s == end)
                    {
                        return map_distance[word] + 1;
                    }

                    if (dict.find(s) != dict.end() && map_distance[s] == 0)
                    {
                        que.push(s);
                        map_distance[s] = map_distance[word] + 1;
                    }
                }
            }
        }

        return 0;
    }
}

namespace WordLadder2
{
    void dfs(string word, const string& end, unordered_set<string>& dict,
        vector<vector<string>>& result,
        vector<string>& current,
        unordered_map<string, bool>& visited,
        int distance, const int& max_length)
    {
        if (distance >= max_length)
            return;

        for (int i = 0; i < word.size(); i++)
        {
            string s = word;
            for (char c = 'a'; c <= 'z'; c++)
            {
                s[i] = c;

                if (s == end)
                {
                    current.push_back(end);
                    result.push_back(current);
                    current.pop_back();

                    return;
                }
                if (dict.find(s) != dict.end() && !visited[s])
                {
                    visited[s] = true;
                    current.push_back(s);

                    dfs(s, end, dict, result, current, visited, distance + 1, max_length);

                    current.pop_back();
                    visited[s] = false;
                }
            }
        }
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
    {
        vector<vector<string>> result;
        if (wordList.empty())
            return result;

        int max_length = leetcode::ladderLength(beginWord, endWord, wordList);
        unordered_map<string, bool> visited;
        vector<string> current{ beginWord };

        dfs(beginWord, endWord, wordList, result, current, visited, 1, max_length);

        return result;
    }
}