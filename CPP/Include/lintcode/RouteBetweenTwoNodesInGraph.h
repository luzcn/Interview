#pragma once
#include "stdafx.h"
#include <queue>

namespace lintcode
{
    //  Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
    //    Given graph :
    //  A----->B----->C
    //    \ |
    //    \ |
    //    \ |
    //    \  v
    //    ->D----->E
    //
    //    for s = B and t = E, return true
    //    for s = D and t = C, return false

    struct DirectedGraphNode
    {
        int label;
        vector<DirectedGraphNode *> neighbors;
        DirectedGraphNode(int x) : label(x) {};
    };


    class Solution {
    public:
        /**
        * @param graph: A list of Directed graph node
        * @param s: the starting Directed graph node
        * @param t: the terminal Directed graph node
        * @return: a boolean value
        */
        bool hasRoute(vector<DirectedGraphNode*> graph,
            DirectedGraphNode* s, DirectedGraphNode* t)
        {
            // write your code here
            if (s == t)
                return true;
            // BFS
            std::queue<DirectedGraphNode*> que;
            unordered_set<DirectedGraphNode*> visited;
            que.push(s);

            while (!que.empty())
            {
                auto cur = que.front();
                que.pop();

                if (visited.find(cur) == visited.end())
                {
                    if (cur == t)
                        return true;

                    visited.emplace(cur);
                    for (auto n : cur->neighbors)
                    {
                        que.push(n);
                    }
                }
            }
            return false;
        }
    private:
        bool DFS(unordered_set<DirectedGraphNode*>& visited,
            DirectedGraphNode* node, DirectedGraphNode* t)
        {
            if (node == t)
                return true;
            visited.emplace(node);

            for (auto n : node->neighbors)
            {
                if (visited.find(n) == visited.end())
                {
                    if (DFS(visited, n, t))
                        return true;
                }
            }

            return false;
        }
    };
}