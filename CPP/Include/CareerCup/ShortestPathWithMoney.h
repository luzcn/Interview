#pragma once
#include "stdafx.h"

//Given an undirected graph G having positive weights and N vertices.
//
//You start with having a sum of M money.
//For passing through a vertex i, you must pay S[i]  money.
//If you don’t have enough money – you can’t pass through that vertex.
//
//Find the shortest path from vertex 1 to vertex N.
// Thoughts:
// In shortest path problem, we use a single array dist[i] to indicate the shortest path from vertix i to the source vertix
//
// in this problem, we need to store one more condition "the Money", 
// so we need to use 2d array min[i][j] to store the shortest path to vertix i and the money left.
namespace careercup
{
    int findMin(vector<vector<int>>& min, vector<bool>& visited)
    {
        int n = min.size();
        int min_index = 0;
        int minValue = INT_MAX;
        for (int i = 0; i < min.size(); i++)
        {
            for (int j = 0; j <= min[0].size(); j++)
            {
                if (!visited[i] && min[i][j] < minValue)
                {
                    minValue = min[i][j];
                    min_index = i;
                }
            }
        }
        return min_index;
    }

    // graph: the adjacent matrix represented graph
    // M : the money
    int shortestPathWithMoney(vector<vector<int>>& graph, int M, vector<int>& S)
    {
        int vertexNum = graph.size();
        vector<vector<int>> min(vertexNum, vector<int>(M + 1, 100));
        vector<bool> visited(vertexNum, false);

        min[0][M] = 0;

        for (int count = 0; count < vertexNum; count++)
        {

            // find min
            int u = -1;
            int j = M;  // The money
            int minCost = 100;
            for (int i = 0; i < min.size(); i++)
            {
                for (int l = 0; l <= M; l++)
                {
                    if (!visited[i] && min[i][l] < minCost)
                    {
                        minCost = min[i][l];
                        u = i;
                        j = l;
                    }
                }
            }
            if (u == -1)
                return -1;

            visited[u] = true;
            int cost = S[u];
            if (j < cost)
                continue;

            for (int v = 0; v < vertexNum; v++)
            {
                if (!visited[v] && graph[u][v] && min[u][j] + graph[u][v] < min[v][j - cost])
                {
                    min[v][j - cost] = min[u][j] + graph[u][v];
                }
            }
        }

        // print out min
        for (auto l : min)
        {
            for (auto i : l)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return *std::min_element(min[vertexNum - 1].begin(), min[vertexNum - 1].end());
    }
}