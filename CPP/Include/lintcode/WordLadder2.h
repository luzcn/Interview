#pragma once
#include "stdafx.h"

//Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//
//Example
//
//Given :
//start = "hit"
//end = "cog"
//dict = ["hot", "dot", "dog", "lot", "log"]
//
//Return
//
//[
//    ["hit", "hot", "dot", "dog", "cog"],
//    ["hit", "hot", "lot", "log", "cog"]
//]



namespace lintcode
{
    // DFS solution
    void dfs(string start, const string& end, unordered_set<string> &dict, vector<string>& current,
        vector<vector<string>>& res, unordered_map<string, int>& distance, size_t& min_distance)
    {
        for (int i = 0; i < start.size(); i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                auto temp = start;
                temp[i] = c;
                if (temp == end)
                {
                    if (current.size() < min_distance)
                    {
                        res.clear();
                        min_distance = current.size();
                        res.push_back(current);
                    }
                    else if (current.size() == min_distance)
                    {
                        res.push_back(current);
                    }
                    return;
                }

                if (dict.find(temp) != dict.end() && distance[temp] == 0)
                {
                    distance[temp] = distance[start] + 1;
                    current.push_back(temp);

                    dfs(temp, end, dict, current, res, distance, min_distance);
                    current.pop_back();
                    distance[temp] = 0; // mark this word as unvisited.
                }
            }
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        if (dict.empty())
            return{};

        unordered_map<string, int> distance;    // bfs visited
        vector<string> list;    // bfs queue
        vector<string> current;
        vector<vector<string>> res;
        distance[start] = 1;
        size_t min_distance = INT_MAX;

        dfs(start, end, dict, current, res, distance, min_distance);
        return res;
    }
}
