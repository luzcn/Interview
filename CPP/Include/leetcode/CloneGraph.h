#pragma once

#include "stdafx.h"
#include <queue>
#include <unordered_map>
#include <algorithm>

/***
 *	  Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *	  OJ's undirected graph serialization:
 *
 *	  Nodes are labeled uniquely.
 *	  We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 *
 *	  As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *	  The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 *	  First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 *	  Second node is labeled as 1. Connect node 1 to node 2.
 *	  Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 *
 *	  Visually, the graph looks like the following:
 1
 / \
 /   \
 0 --- 2
 / \
 \_/
 */

namespace leetcode
{
    using namespace std;
    class UndirectedGraphNode
    {
    public:
        int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) 
            : label(x) 
        {}
    };

    using HashMap = std::unordered_map < UndirectedGraphNode*, UndirectedGraphNode* > ;

#pragma region BFS Solution
    // The breadth first search of an undirected graph.
    void UndirectedGraphBFS(UndirectedGraphNode* node)
    {
        if (!node)
            return;

        // using a queue to store the adjacent nodes.
        // using a hash table to indicate if the the nodes have been visited.
        std::queue<UndirectedGraphNode*> queue;
        std::unordered_map<UndirectedGraphNode*, int> map;

        auto current_node = node;
        queue.push(node);

        while (!queue.empty())
        {
            current_node = queue.front();
            if (map.find(current_node) != map.end())
                return;

            map.emplace(current_node, 1);
            queue.pop();

            std::cout << current_node->label << std::endl;

            for (auto neighbor : current_node->neighbors)
            {
                queue.push(neighbor);
            }
        }

    }
#pragma endregion

#pragma region DFS Solution
    void UndirectedGraphDFS(UndirectedGraphNode* node)
    {

    }

#pragma endregion DFS Solution

    // Clone graph
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node)
        {
            return node;
        }

        // using queue to store the neighbors and using hashmap to inidicate if the node has been visited.
        std::queue<UndirectedGraphNode*> que;
        HashMap map;

        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        map.emplace(node, newNode);
        que.push(node);

        while (!que.empty())
        {
            auto current = que.front();
            que.pop();

            for (auto neighbor : current->neighbors)
            {
                if (map.find(neighbor) == map.end())     // No copy node exists.
                {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    map.emplace(neighbor, newNode);
                    map[current]->neighbors.push_back(newNode);
                    que.push(neighbor);
                }
                else
                {
                    map[current]->neighbors.push_back(map[neighbor]);
                }
            }
        }

        return newNode;
    }
}

#if 0
int _tmain(int argc, _TCHAR* argv[])
{
    CloneGraph::UndirectedGraphNode n0(0);
    CloneGraph::UndirectedGraphNode n1(1);
    CloneGraph::UndirectedGraphNode n2(2);

    n0.neighbors.push_back(&n1);
    n0.neighbors.push_back(&n2);

    n1.neighbors.push_back(&n2);

    n2.neighbors.push_back(&n2);

    auto n = CloneGraph::cloneGraph(&n0);

    CloneGraph::UndirectedGraphBFS(n);
    return 0;
}
#endif