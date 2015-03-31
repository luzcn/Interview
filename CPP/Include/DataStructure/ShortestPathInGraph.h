#pragma once
#include "stdafx.h"

// Dijkstra’s algorithm to compute the shortest distance from source to each vertex.
namespace ShortestPath
{
    struct GraphNode
    {
        int val;
        unordered_map<GraphNode*, int> adj_list;

        GraphNode(int v)
            :val(v)
        {
        }

        void add_edge(GraphNode* node, int dist)
        {
            adj_list.emplace(node, dist);
        }
    };

    GraphNode* find_min(vector<GraphNode*>& graph, unordered_map<GraphNode*, int>& dist, 
        unordered_map<GraphNode*, bool>& visited)
    {
        int n = graph.size();
        int min_dist = INT_MAX;
        GraphNode* result = nullptr;

        for (GraphNode* v : graph)
        {
            if (visited[v] && dist[v] < min_dist)
            {
                result = v;
                min_dist = dist[v];
            }
        }

        return result;
    }

    unordered_map<GraphNode*, int> shortest_path(vector<GraphNode*>& graph, GraphNode* src)
    {
        int n = graph.size();
        unordered_map<GraphNode*, int> dist;
        unordered_map<GraphNode*, bool> visited;

        // init the distance to infinity except start vertex as 0. 
        for (auto v : graph)
        {
            dist[v] = INT_MAX;
        }
        dist[src] = 0;

        for (int i = 0; i < n; i++)
        {
            auto u = find_min(graph, dist, visited);
            if (u)
            {
                visited[u] = true;

                for (auto v : u->adj_list)
                {
                    auto node = v.first;
                    auto distance = v.second;

                    if (!visited[node] && dist[u] + distance < dist[node])
                    {
                        dist[node] = dist[u] + distance;
                    }
                }
            }
        }

        return dist;
    }
}