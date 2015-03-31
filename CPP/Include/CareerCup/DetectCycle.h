#pragma  once

#include "stdafx.h"
#include <unordered_set>

/**
 *	In directed graph, there are 3 types edge:
 *	1. forward edge (from ancestor to descendant),
 *	2. back edge (from descendant to ancestor),
 *	3. cross edge(between branches of a tree, or between trees)
 *
 *	If there is cycle in the tree, there must exist one back edge.
 *	- Use a hashmap to store all the visited nodes.
 *	- If current node has edge to a visited node, there is cycle in undirected graph.
 *	But, in directed graph, we need to check if the visisted node is the ancestor of current node.
 *
 */
namespace DetectCycle
{
    struct GraphNode
    {
        int val;
        vector<GraphNode*> adj_list;

        GraphNode(int v)
            :val(v)
        {
        }

        void add_edge(GraphNode* node)
        {
            adj_list.push_back(node);
        }
    };

    bool isCycleDFS(GraphNode* node, unordered_set<GraphNode*>& visited,
        unordered_set<GraphNode*>& ancestor)
    {
        if (!node)
            return false;

        visited.emplace(node);
        ancestor.emplace(node);

        for (auto adj : node->adj_list)
        {
            if (visited.find(adj) == visited.end())  // not visited
            {
                return isCycleDFS(adj, visited, ancestor);
            }
            else if (ancestor.find(adj) != ancestor.end()) // visited, check if it is ancestor.
            {
                return true;
            }
        }

        ancestor.erase(node);
        return false;
    }

    /**
     *	A graph may not all connected.
     *	Use a vector to store all the graph nodes.
     */
    bool isCycle(vector<GraphNode*>& graph)
    {
        unordered_set<GraphNode*> visited;
        for (auto node : graph)
        {
            if (visited.find(node) == visited.end())
            {
                unordered_set<GraphNode*> ancestor;
                if (isCycleDFS(node, visited, ancestor))
                {
                    return true;
                }
            }
        }

        return false;
    }
}

#if 0
#include "stdafx.h"
#include "CareerCup/DetectCycle.h"

using namespace std;
using namespace DetectCycle;

int _tmain(int argc, _TCHAR* argv [])
{
    GraphNode n0(0);
    GraphNode n1(1);
    GraphNode n2(2);
    GraphNode n3(3);
    GraphNode n4(4);
    GraphNode n5(5);
    GraphNode n6(6);
    GraphNode n10(10);

    n0.add_edge(&n1); // 0 -> 1
    n0.add_edge(&n2); // 0 -> 2

    n1.add_edge(&n2); // 1 -> 2

    n2.add_edge(&n4); // 2 -> 4
    n2.add_edge(&n3); // 2 -> 3

    n5.add_edge(&n6); // 5 -> 6

    n10.add_edge(&n10);

    vector<GraphNode*> graph = { &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n10 };
    std::unordered_set<GraphNode*> visited;

    cout << isCycle(graph);
    return 0;
}
#endif