#pragma once
#include "stdafx.h"

//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
namespace leetcode
{
    class UndirectedGraphNode
    {
    public:
        int label;
        vector<UndirectedGraphNode*> neighbors;
        UndirectedGraphNode(int x)
            : label(x)
        {}
    };


    // BFS Clone graph
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node)
            return nullptr;

        // key: the original graph node
        // value: the copied node
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapNodes;

        // make sure there is no infinit loop in graph.
        unordered_map<UndirectedGraphNode*, bool> visited;

        std::queue<UndirectedGraphNode*> que;
        que.push(node);

        while (!que.empty())
        {
            auto current = que.front();
            que.pop();

            if (visited[current])
                continue;

            visited[current] = true;

            if (mapNodes.find(current) == mapNodes.end())
            {
                UndirectedGraphNode* copiedNode = new UndirectedGraphNode(current->label);
                mapNodes[current] = copiedNode;
            }

            for (auto n : current->neighbors)
            {
                if (mapNodes.find(n) == mapNodes.end())
                {
                    mapNodes[n] = new UndirectedGraphNode(n->label);
                }
                mapNodes[current]->neighbors.push_back(mapNodes[n]);

                que.push(n);
            }
        }

        return mapNodes[node];
    }

    void dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mapNodes,
        unordered_map<UndirectedGraphNode*, bool>& visited)
    {
        if (!node || visited[node])
            return;

        visited[node] = true;

        if (mapNodes.find(node) == mapNodes.end())
        {
            UndirectedGraphNode* copiedNode = new UndirectedGraphNode(node->label);
            mapNodes[node] = copiedNode;
        }

        for (UndirectedGraphNode* n : node->neighbors)
        {
            if (mapNodes.find(n) == mapNodes.end())
            {
                mapNodes[n] = new UndirectedGraphNode(n->label);
            }

            mapNodes[node]->neighbors.push_back(mapNodes[n]);

            dfs(n, mapNodes, visited);
        }
    }
}
