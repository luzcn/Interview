#pragma once

#include "stdafx.h"

#include <unordered_set>
#include <limits>
#include <unordered_map>
/**
*  Given two words (start and end), and a dictionary,
find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/
namespace WordLadder
{
    int ladderLength(string start, string end, unordered_set<string>& dict)
    {
        // BFS
        vector<string> list;
        unordered_map<string, int> distance;

        list.push_back(start);
        distance.emplace(start, 1);

        while (!list.empty())
        {
            auto word = list.front();
            list.erase(list.begin());

            // compare all the transformation
            for (int i = 0; i < word.size(); i++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                {
                    auto t = word;
                    t[i] = c;
                    if (t == end)
                    {
                        return distance[word] + 1;
                    }
                    if (dict.count(t) > 0 && distance.count(t) == 0)
                    {
                        distance[t] = distance[word] + 1;
                        list.push_back(t);
                    }
                }
            }
        }

        return 0;
    }



}

namespace WordLadder2
{
    // construct a graph and find the shorted path.
    struct Node
    {
        string val;
        vector<Node*> adj;
        int distance;

        Node(string str)
            :val(std::move(str))
        {
        }

        void add_adj(Node* s)
        {

            adj.push_back(s);
        }
    };

    void BFS(Node* head)
    {
        std::unordered_map<Node*, int> visited;
        vector<Node*> list;
        list.push_back(head);

        while (!list.empty())
        {
            auto t = list.front();
            list.erase(list.begin());

            if (visited.count(t) == 0)
            {
                cout << t->val << endl;
                visited[t] = 1;
                for (auto item : t->adj)
                {
                    list.push_back(item);
                }
            }
        }
    }

    void shortest_path(Node* head)
    {

    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<vector<string>> result;

        // construct a graph first.
        vector<Node*> list;        // used as a queue for BFS
        std::unordered_map<string, int> distance; // used to check if the string has been visited

        distance.emplace(start, 1);

        Node * head = new Node(start);
        list.push_back(head);

        while (!list.empty())
        {
            auto p_word = list.front();
            list.erase(list.begin());

            for (int i = 0; i < p_word->val.size(); i++)
            {
                auto t = p_word->val;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    t[i] = c;

                    if (t == end)
                    {
                        break;
                    }

                    if (dict.count(t) > 0 && distance.count(t) == 0)
                    {
                        auto newNode = new Node(t);
                        p_word->add_adj(newNode);
                        list.push_back(newNode);
                        distance[t] = distance[p_word->val] + 1;
                    }
                }
            }
        }

        BFS(head);

        return result;
    }
}