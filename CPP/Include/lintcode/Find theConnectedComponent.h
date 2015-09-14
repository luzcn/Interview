#pragma once
#include "stdafx.h"

//Find the Connected Component in the Undirected Graph

// Find the number connected component in the undirected graph.
// Each node in the graph contains a label and a list of its neighbors.
//
// (a connected component(or just component) of an undirected graph is 
// a subgraph in which any two vertices are connected to each other by paths, 
// and which is connected to no additional vertices in the supergraph.)
//
// Given graph :
//
//  A-----B  C
//  \     |  |
//   \    |  |
//    \   |  |
//     \  |  |
//       D   E
//
//Return{ A,B,D }, { C,E }.Since there are two connected component which is{ A,B,D }, { C,E }

namespace lintcode
{
    void dfs(UndirectedGraphNode* node, unordered_set<UndirectedGraphNode*>& visited, 
        vector<int>& current)
    {
        if (visited.find(node) != visited.end())
            return;

        visited.insert(node);
        current.push_back(node->label);
        for (auto n : node->neighbors)
        {
            dfs(n, visited, current);
        }
    }

    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes)
    {
        vector<vector<int>> res;
        if (nodes.empty())
            return res;

        unordered_set<UndirectedGraphNode*> visited;
        vector<int> current;

        for (auto n : nodes)
        {
            dfs(n, visited, current);
            if (!current.empty())
            {
                res.push_back(current);
                current.clear();
            }
        }

        return res;
    }
}