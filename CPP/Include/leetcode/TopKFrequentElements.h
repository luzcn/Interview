#pragma once
#include "stdafx.h"
#include <functional>

//Given a non - empty array of integers, return the k most frequent elements.
//
//For example,
//Given[1, 1, 1, 2, 2, 3] and k = 2, return[1, 2].
//
//Note:
//
//You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
namespace leetcode
{
    struct Comparator
    {
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second > p2.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // hashmap + heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap; // min heap
        unordered_map<int, int> map;    // nums value, frequent

        for (int& n : nums)
        {
            map[n]++;
        }

        for (auto& p : map)
        {
            if (minHeap.size() < k)
            {
                minHeap.push(p);
            }
            else
            {
                if (p.second > minHeap.top().second)
                {
                    minHeap.pop();
                    minHeap.push(p);
                }
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
}