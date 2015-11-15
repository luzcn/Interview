#pragma once
#include "stdafx.h"

//  There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//  Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
//  which is expressed as a pair : [0, 1]
//
//  Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//For example :
//  2, [[1, 0]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
// 
//  2, [[1, 0], [0, 1]]
// There are a total of 2 courses to take.To take course 1 you should have finished course 0, 
// and to take course 0 you should also have finished course 1. So it is impossible.
namespace leetcode
{
#pragma region Course Schedule 1
    // detect is cycle in DAG solution
    bool isCycle(vector<pair<int, int>>& prerequisites, vector<bool>& visited,
        unordered_set<int>& ancestor, int u)
    {
        if (!visited[u])
        {
            visited[u] = true;
            ancestor.insert(u);

            for (pair<int, int> p : prerequisites)
            {
                if (u == p.first)
                {
                    int v = p.second;

                    if (!visited[v])
                    {
                        if (isCycle(prerequisites, visited, ancestor, v))
                            return true;
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

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        if (prerequisites.empty())
            return true;

        vector<bool> visited(numCourses + 1, false);
        unordered_set<int> ancestor;

        for (auto& p : prerequisites)
        {
            if (isCycle(prerequisites, visited, ancestor, p.first))
                return false;
        }

        return true;
    }
#pragma endregion

#pragma region Course Schedule2
    bool dfs(vector<pair<int, int>>& edgeList, int u,
        vector<bool>& visited, unordered_set<int>& ancestor, vector<int>& order)
    {
        if (!visited[u])
        {
            visited[u] = true;
            ancestor.insert(u);
            int v = -1;

            for (pair<int, int>& edge : edgeList)
            {
                if (edge.first == u)
                {
                    v = edge.second;

                    if (!visited[v])
                    {
                        if (dfs(edgeList, v, visited, ancestor, order))
                            return true;
                    }
                    else if (ancestor.find(v) != ancestor.end())
                    {
                        return true;
                    }
                }
            }

            ancestor.erase(u);
            order.push_back(u);
        }

        return false;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<bool> visited(numCourses, false);
        unordered_set<int> ancestor;
        vector<int> order;

        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(prerequisites, i, visited, ancestor, order))
                return{};
        }

        return order;
    }

#pragma endregion


}