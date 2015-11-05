#pragma once

#include "stdafx.h"
#include <unordered_map>
#include <queue>
#include <limits>

namespace Graph
{
    void BFS(GraphNode* node, std::queue<GraphNode*>& que, std::unordered_map<GraphNode*, int>& visited)
    {
        if (!node)
        {
            return;
        }

        if (visited.find(node) == visited.end())
        {
            que.push(node);
            visited.emplace(node, 1);

            while (!que.empty())
            {
                auto current = que.front();
                que.pop();
                cout << current->val << endl;

                for (auto& adj : current->adj_list)
                {
                    if (visited.find(adj) == visited.end())
                    {
                        que.push(adj);
                        visited.emplace(adj, 1);
                    }
                }
            }
        }
    }

    void DFS(GraphNode* node, unordered_map<GraphNode*, int>& map)
    {
        if (!node)
            return;

        cout << node->val << endl;
        map.emplace(node, 1);

        for (auto adj : node->adj_list)
        {
            if (map.find(adj) == map.end())
            {
                DFS(adj, map);
            }
        }
    }

    //  Detect Cycle In Directed Graph
    bool isCycleDFS(GraphNode* node, unordered_map<GraphNode*, int>& visited,
        unordered_map<GraphNode*, int>& ancestor)
    {
        if (!node)
        {
            return false;
        }

        //// Detect cycle
        //if (ancestor.find(node) != ancestor.end())
        //{
        //    return true;
        //}

        visited.emplace(node, 1);
        ancestor.emplace(node, 1);

        for (auto adj : node->adj_list)
        {
            if (visited.find(adj) == visited.end())
            {
                return isCycleDFS(adj, visited, ancestor);
            }
            else if (ancestor.find(adj) != ancestor.end())
            {
                return true;
            }
        }
        ancestor.erase(node);
        return false;
    }

    bool isCycle(GraphNode* node, unordered_map<GraphNode*, int>& visited)
    {
        if (visited.find(node) != visited.end())
            return false;

        unordered_map<GraphNode*, int> ancestor;
        return isCycleDFS(node, visited, ancestor);
    }

    void TopologicalSortRec(GraphNode* node, std::unordered_set<GraphNode*>& visited, std::stack<GraphNode*>& stack)
    {
        if (!node)
            return;

        if (visited.find(node) == visited.end())
        {
            visited.insert(node);
            for (auto n : node->adj_list)
            {
                TopologicalSortRec(n, visited, stack);
            }
            stack.push(node);
        }
    }
    void TopologicalSort(vector<GraphNode*> graph)
    {
        std::unordered_set<GraphNode*> visited;
        std::stack<GraphNode*> stack;

        for (auto node : graph)
        {
            if (visited.find(node) == visited.end())
            {
                TopologicalSortRec(node, visited, stack);
            }
        }
        while (!stack.empty())
        {
            cout << stack.top()->val << endl;
            stack.pop();
        }

        return;
    }
}

namespace WeightedGraph
{
    // some helper function
    int find_min(vector<bool>& visited, vector<int>& dist, int n)
    {
        int min_index = 0;
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }

    //  Dijkstra algorithm to compute the shortest distance from source to each vertex.
    //  Dijkstra’s algorithm doesn’t work for graphs with negative weight edges. 
    //  For graphs with negative weight edges, Bellman–Ford algorithm can be used.
    // 
    //  O(n^2)
    //  http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
    vector<int> shortest_path(vector<vector<int>>& graph, int src)
    {
        const int n = graph.size();

        vector<bool> visited(n, false);
        vector<int> dist(n, INT_MAX);

        // used to record the previous vertex,
        // so we can used to print out the vertex path.
        vector<int> prev(n, -1);

        // initialize
        dist[src] = 0;

        for (int count = 0; count < n; count++)
        {
            auto u = find_min(visited, dist, n);
            visited[u] = true;

            // Update dist value of the adjacent vertices of the picked vertex.
            for (int v = 0; v < n; v++)
            {
                // Update dist[v] only if is not visited, there is an edge from 
                // u to v, and total weight of path from src to  v through u is 
                // smaller than current value of dist[v]
                if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                    && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
        return prev;
    }
}
#if 0

#include "stdafx.h"
#include "DataStructure/Graph.h"
using namespace std;
using namespace Graph;

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

    n2.add_edge(&n0); // 2 -> 0
    n2.add_edge(&n3); // 2 -> 4

    n5.add_edge(&n6); // 5 -> 6

    vector<GraphNode*> graph = { &n0, &n1, &n2, &n3, &n4, &n5, &n6, &n10 };
    std::queue<GraphNode*> que;
    std::unordered_map<GraphNode*, int> visited;

    /* for (auto v : graph)
    {
    BFS(v, que, visited);
    }*/

    /*DFS(&n0, visited);*/

    cout << isCycle(&n0, visited);
    return 0;
    }
#endif

#if 0
vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
};
#endif