#pragma once
#include "stdafx.h"

//Given n nodes labeled from 0 to n - 1 and a list of undirected edges(each edge is a pair of nodes), 
//write a function to check whether these edges make up a valid tree.
//
//For example :
//
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

namespace leetcode
{
    bool dfs(vector<pair<int, int>>& edges, vector<bool>& visited, int u, int parent)
    {
        visited[u] = true;

        for (auto& p : edges)
        {
            int v = -1;
            if (p.first == u)
                v = p.second;
            else if (p.second == u)
                v = p.first;

            // no need to repeat the [0,1] and [1,0], these two should not be considered as loop.
            if (v != -1 && v != parent)
            {
                if (!visited[v])
                {
                    if (dfs(edges, visited, v, u))
                    {
                        return true;
                    }
                }
                else
                    return true;
            }
        }

        return false;
    }


    bool validTree(int n, vector<pair<int, int>>& edges)
    {
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                if (dfs(edges, visited, i, -1)) // the edge list has loop.
                    return false;
            }
        }

        // the vertex are not all connected
        if (count > 1)
            return false;

        return true;
    }
}