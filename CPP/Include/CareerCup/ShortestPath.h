#pragma once
#include "stdafx.h"

namespace careercup
{
#pragma region Shortest Path Adjacent-Matrix
    int findMinNode(vector<int> distance, vector<bool>& visited)
    {
        int minDistance = INT_MAX;
        int minNode = 0;
        for (int i = 0; i < distance.size(); i++)
        {
            if (!visited[i] && distance[i] < minDistance)
            {
                minDistance = distance[i];
                minNode = i;
            }
        }

        return minNode;
    }

    // adjacent matrix solution
    vector<int> shortestPath(vector<vector<int>>& graph, int source)
    {
        // total vertex number
        int n = graph.size();

        vector<int> distance(n, INT_MAX);
        vector<bool> visited(n, false);
        distance[source] = 0;

        for (int count = 0; count < n; count++)
        {
            auto u = findMinNode(distance, visited);
            visited[u] = true;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && graph[u][v] &&
                    distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        return distance;
    }
#pragma endregion

}