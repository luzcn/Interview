#pragma  once

#include "stdafx.h"
#include <unordered_set>


//In directed graph, there are 3 types edge:
//  1. forward edge (from ancestor to descendant),
//  2. back edge (from descendant to ancestor),
//  3. cross edge(between branches of a tree, or between trees)
// 
//If there is cycle in the tree, there must exist one back edge.
//  - Use a hashmap to store all the visited nodes.
//  - If current node has edge to a visited node, there is cycle in undirected graph.
//  However, in directed graph, we need to check if the visisted node is the ancestor of current node.


// representation the graph with N vertex
// - each vertex is represented as 0,1..N-1.
// - edges are represented as edge list
//  for example [0,1] meadn there is an edge from vertex 0 to vertex 1.
namespace careercup
{
    bool dfs(vector<pair<int, int>>& edgeList, int u, 
        vector<bool>& visited, unordered_set<int>& ancestor)
    {
        if (!visited[u])
        {
            visited[u] = true;
            ancestor.insert(u);

            for (auto& edge : edgeList)
            {
                if (edge.first == u)
                {
                    int v = edge.second;

                    if (!visited[v])
                    {
                        if (dfs(edgeList, v, visited, ancestor))
                        {
                            return true;
                        }
                    }
                    else if (ancestor.find(v) != ancestor.end())
                    {
                        return true;
                    }
                }
            }
            ancestor.erase(u);
        }

        return false;
    }

    bool isCycle(vector<pair<int, int>>& edgeList, int vertexNumber)
    {
        vector<bool> visited(vertexNumber, false);
        unordered_set<int> ancestor;

        for (auto& p : edgeList)
        {
            if (dfs(edgeList, p.first, visited, ancestor))
                return true;
        }

        return false;
    }
}