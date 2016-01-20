#pragma once
#include "stdafx.h"

//  Given n nodes labeled from 0 to n - 1 and a list of undirected edges(each edge is a pair of nodes), 
//  write a function to find the number of connected components in an undirected graph.
//
//  Example 1:
//
//  0          3
//  |          |
//  1 -- - 2   4
//
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//
//  Example 2:
//
//  0             4
//  |             |
//  1 -- - 2 -- - 3
//
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

namespace leetcode
{
    void dfs(vector<pair<int, int>>& edges, vector<bool>& visited, int u)
    {
        if (visited[u])
        {
            return;
        }

        visited[u] = true;

        for (auto p : edges)
        {
            int v = 0;
            if (p.first == u)
            {
                v = p.second;
            }
            else if (p.second == u)
            {
                v = p.first;
            }

            dfs(edges, visited, v);
        }
    }

    int countComponents(int n, vector<pair<int, int>>& edges) 
    {
        vector<bool> visited(n + 1, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(edges, visited, i);
            }
        }
        return count;
    }
}