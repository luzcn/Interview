#pragma once
#include "stdafx.h"
#include <set>

//Given a list of airline tickets represented by pairs of departure and arrival airports[from, to], reconstruct the itinerary in order.
// All of the tickets belong to a man who departs from JFK.Thus, the itinerary must begin with JFK.
//
// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order 
// when read as a single string.For example, the itinerary["JFK", "LGA"] has a smaller lexical order than["JFK", "LGB"].
//
// All airports are represented by three capital letters(IATA code).
// You may assume all tickets form at least one valid itinerary.
//
// Example 1:
//  tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//  Return["JFK", "MUC", "LHR", "SFO", "SJC"].
//
// Example 2 :
//    tickets = [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
//    Return["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"].
//    Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"].But it is larger in lexical order.

namespace leetcode
{
    /*bool dfs(unordered_map<string, multiset<string>>& graph, vector<string>& result, string start, int n)
    {
        if (graph[start].empty())
        {
            
            if (n <= 0)
            {
                result.push_back(start);
                return true;
            }
            else
                return false;
        }

        for (int i = 0; i < graph[start].size(); i++)
        {
            result.push_back(start);
            string next = *std::next(graph[start].begin(), i);
            graph[start].erase(next);

            if (dfs(graph, result, next, n - 1))
            {
                return true;
            }

            graph[start].insert(next);
            result.pop_back();
        }
        return false;
    }*/

    // use multiset because there maybe duplicate itinerary between two cities.
    void dfs(unordered_map<string, multiset<string>>& graph, vector<string>& result, string start)
    {
        while (!graph[start].empty())
        {
            string next = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(graph, result, next);
        }
        result.push_back(start);
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        vector<string> result;
        unordered_map<string, multiset<string>> graph;

        for (auto& p : tickets)
        {
            graph[p.first].insert(p.second);
        }

        dfs(graph, result, "JFK");
        std::reverse(result.begin(), result.end());

        return result;
    }
}