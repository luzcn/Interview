#pragma once
#include "stdafx.h"

// For a undirected graph with tree characteristics, we can choose any node as the root.
// The result graph is then a rooted tree.
// Among all possible rooted trees, those with minimum height are called minimum height trees(MHTs).
//
// Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. 
// You will be given the number n and a list of undirected edges(each edge is a pair of labels).
//
// You can assume that no duplicate edges will appear in edges.
// Since all edges are undirected, [0, 1] is the same as[1, 0] and thus will not appear together in edges.
namespace leetcode
{
    int bfs(int n, vector<pair<int, int>>& edges, int root, int minLength)
    {
        vector<bool> visited(n, false);
        queue<int> candidates;
        queue<int> candidatesTemp;

        int level = 0;

        candidates.push(root);
        while (!candidates.empty())
        {
            int u = candidates.front();
            candidates.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            for (auto& edge : edges)
            {
                if (edge.first == u && !visited[edge.second])
                {
                    candidatesTemp.push(edge.second);
                }
                else if (edge.second == u && !visited[edge.first])
                {
                    candidatesTemp.push(edge.first);
                }
            }

            if (candidates.empty())
            {
                level++;
                swap(candidates, candidatesTemp);
            }

            if (level > minLength)
                return INT_MAX;
        }

        return level;

    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
    {
        if (n == 1)
            return vector<int>{0};

        unordered_map<int, vector<int>> graph;
        for (auto edge : edges)
        {
            // undirected graph
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        vector<int> leaves;
        vector<int> newLeaves;
        for (int i = 0; i < graph.size(); i++)
        {
            // node degree is 1
            if (graph[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }

        while (n > 2)
        {
            n -= leaves.size();

            for (int leaf : leaves)
            {
                // leaf node has only one connected node
                int connectedNode = graph[leaf][0]; 

                // remove the leaf nodes from the graph
                graph.erase(leaf);

                // remove this leaf node from the connected node
                vector<int>& edge = graph[connectedNode];
                edge.erase(remove(edge.begin(), edge.end(), leaf));
                if (edge.size() == 1)
                {
                    newLeaves.push_back(connectedNode);
                }
            }

            // remove the visited leaves, replaced with new leaf nodes.
            leaves.clear();
            swap(leaves, newLeaves);
        }

        return leaves;
    }
}