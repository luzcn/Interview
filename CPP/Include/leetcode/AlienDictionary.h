#pragma once
#include "stdafx.h"

//  here is a new alien language which uses the latin alphabet.
//  However, the order among letters are unknown to you.
//
//  You receive a list of words from the dictionary, where words are sorted lexicographically 
//  by the rules of this new language.Derive the order of letters in this language.
//
//  For example,
//  Given the following words in dictionary,
//
//  [
//    "wrt",
//    "wrf",
//    "er",
//    "ett",
//    "rftt"
//  ]
//
//  The correct order is : "wertf".
//
//  Note :
//
//    You may assume all letters are in lowercase.
//    If the order is invalid, return an empty string.
//    There may be multiple valid order of letters, return any one of them is fine.
namespace leetcode
{
    void topoSort(unordered_map<char, unordered_set<char>>& graph, char node,
        unordered_map<char, bool>& visited, stack<char>& order)
    {
        if (visited[node])
            return;

        visited[node] = true;

        for (char c : graph[node])
        {
            topoSort(graph, c, visited, order);
        }

        order.push(node);
    }

    bool isCycle(unordered_map<char, unordered_set<char>>& graph, char node,
        unordered_map<char, bool>& visited, unordered_set<char>& ancestor)
    {
        if (ancestor.find(node) != ancestor.end())
            return true;

        if (!visited[node])
        {
            visited[node] = true;
            ancestor.insert(node);

            for (char n : graph[node])
            {
                if (isCycle(graph, n, visited, ancestor))
                {
                    return true;
                }
            }
            ancestor.erase(node);
        }
        return false;
    }

    void buildGraph(vector<string>& words, unordered_map<char, unordered_set<char>>& graph)
    {
        for (int i = 1; i < words.size(); i++)
        {
            bool found = false;
            int m = words[i - 1].size();
            int n = words[i].size();

            for (int j = 0; j < max(m, n); j++)
            {
                // need to implicitly add this node into graph
                // otherwise, the topo sort will miss this character.
                if (j < m && graph.find(words[i - 1][j]) == graph.end())
                {
                    graph.emplace(words[i - 1][j], unordered_set<char>());
                }

                if (j < n && graph.find(words[i][j]) == graph.end())
                {
                    graph.emplace(words[i][j], unordered_set<char>());
                }

                // found one edge,
                // no need to continue add edges, otherwise, it could make the graph cycle.
                if (j < m && j < n && words[i][j] != words[i - 1][j] && !found)
                {
                    graph[words[i - 1][j]].insert(words[i][j]);
                    found = true;
                }
            }
        }
    }

    string alienOrder(vector<string>& words)
    {
        if (words.empty())
            return "";

        if (words.size() == 1) 
            return words[0];

        // build the adjacent-list graph
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, bool> visited;  // topo sort(dfs) used to check visited.
        stack<char> order;                  // stack for topo sort
        string result;

        // build the graph
        buildGraph(words, graph);

        // check if the graph has cycle
        unordered_set<char> ancestor;
        for (auto p : graph)
        {
            if (isCycle(graph, p.first, visited, ancestor))
                return "";
        }

        // topo sort
        visited.clear();
        for (auto p : graph)
        {
            if (!visited[p.first])
            {
                topoSort(graph, p.first, visited, order);
            }
        }

        while (!order.empty())
        {
            result.push_back(order.top());
            order.pop();
        }

        return result;
    }
}