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
    int bfs(string start, string end, unordered_set<string>& dict)
    {
        vector<string> list;
        list.push_back(start);

        unordered_map<string, int> distance;
        distance[start] = 1;

        while (!list.empty())
        {
            string word = list.front();
            list.erase(list.begin());

            for (int i = 0; i < word.size(); i++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    string temp = word;
                    temp[i] = c;

                    if (temp == end)
                        return distance[word] + 1;

                    if (dict.find(temp) != dict.end() && distance[temp] == 0) // not visited
                    {
                        distance[temp] = distance[word] + 1;
                        list.push_back(temp);
                    }
                }
            }
        }

    }


    void dfs(string start, string end, unordered_set<string> &dict, vector<string>& current,
        vector<vector<string>>& res, unordered_map<string, bool>& visited, int step, size_t& min_distance)
    {
        if (step >= min_distance)   // "step" not include the end word yet.
            return;

        for (int i = 0; i < start.size(); i++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                string temp = start;
                temp[i] = c;

                if (temp == end)
                {
                    current.push_back(end);
                    res.push_back(current);
                    current.pop_back();
                    return;
                }

                if (dict.find(temp) != dict.end() && !visited[temp])
                {
                    current.push_back(temp);
                    visited[temp] = true;
                    dfs(temp, end, dict, current, res, visited, step + 1, min_distance);
                    current.pop_back();
                    visited[temp] = false;
                }
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        if (dict.empty())
            return{};

        unordered_map<string, bool> visited;    // dfs visited
        vector<string> current;
        vector<vector<string>> res;
        size_t min_distance = bfs(start, end, dict);
        current.push_back(start);

        dfs(start, end, dict, current, res, visited, 1, min_distance);
        return res;
    }
}

#if 0
// Construct a graph first.
namespace lintcode2
{
    // DFS solution
    void dfs(string start, string end, const vector<string>& words, const vector<vector<int>>& diffMatrix,
        int index, vector<string>& current, vector<vector<string>>& res,
        unordered_map<int, bool>& visited, size_t& min_distance)
    {
        if (start == end)
        {
            //current.push_back(end);
            if (current.size() < min_distance)
            {
                min_distance = current.size();
                res.clear();
                res.push_back(current);
            }
            else if (current.size() == min_distance)
            {
                res.push_back(current);
            }
            return;
        }

        for (int i = 1; i < words.size(); i++)
        {
            if (visited[i] || diffMatrix[index][i] != 1)
                continue;

            visited[i] = true;
            current.push_back(words[i]);
            dfs(words[i], end, words, diffMatrix, i, current, res, visited, min_distance);
            current.pop_back();
            visited[i] = false;
        }
    }

    // preprocessing steps
    // find the characters transition function, build the graph adj-matrix
    //       hit hot dot dog 
    //  hit   0   1   2   3
    //  hot   1   0   1   2
    //  dot   2   1   0   1
    //  dog   3   2   1   0
    // 
    //  only the edge with "1" in this graph can be traversed.
    void preprocess(string& start, string& end, vector<string>& words, vector<vector<int>>& diffMatrix)
    {
        auto it = std::find(words.begin(), words.end(), start);
        if (it != words.end())
        {
            words.erase(it);
        }
        // add start as the first element in array
        words.insert(words.begin(), start);

        it = std::find(words.begin(), words.end(), end);
        if (it != words.end())
        {
            words.erase(it);
        }
        // add end as the last element
        words.insert(words.end(), end);

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i; j < words.size(); j++)
            {
                int diff = 0;
                for (int k = 0; k < words[i].size(); k++)
                {
                    if (words[i][k] != words[j][k])
                        diff++;
                }
                diffMatrix[i][j] = diff;
                diffMatrix[j][i] = diff;
            }
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        if (dict.empty())
            return{};

        unordered_map<int, bool> visited;    // dfs visited
        vector<string> current;
        vector<vector<string>> res;
        size_t min_distance = INT_MAX;


        vector<string> words{ dict.begin(), dict.end() };
        vector<vector<int>> diffMatrix(words.size(), vector<int>(words.size(), 0));
        current.push_back(start);
        preprocess(start, end, words, diffMatrix);
        dfs(start, end, words, diffMatrix, 0, current, res, visited, min_distance);
        return res;
    }
}
#endif
