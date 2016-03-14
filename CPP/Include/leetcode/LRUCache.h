///   Design and implement a data structure for Least Recently Used (LRU) cache. 
// It should support the following operations: get and set.
///   
///   1. get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
///   
///   2. set(key, value) - Set or insert the value if the key is not already present.
//  When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
/// 

#pragma once

#include "stdafx.h"
#include <unordered_map>
#include <list>

namespace leetcode
{
    // the key-value pair of LRU cached data
    struct Data
    {
        Data(int k, int v)
            :key(k), value(v)
        {}

        int key;
        int value;
    };

    class LRUCache
    {
    public:
        LRUCache(int capacity)
        {
            m_cap = capacity;
        }

        int get(int key)
        {
            if (m_map.find(key) == m_map.end())
                return -1;

            int value = m_map[key]->value;
            moveToHead(key, value);

            return value;
        }

        void set(int key, int value)
        {
            if (m_map.find(key) == m_map.end())   // not in the map
            {
                if (m_list.size() == m_cap)
                {
                    // reach the size limitation
                    // delete the last list element
                    m_map.erase(m_list.back().key);
                    m_list.pop_back();
                }

                // directly add the new data at the list front
                m_list.push_front({ key, value });
                m_map[key] = m_list.begin();
            }
            else
            {
                moveToHead(key, value);
            }

        }
    private:
        int m_cap;
        list<Data> m_list;
        unordered_map<int, list<Data>::iterator> m_map;

        void moveToHead(int key, int value)
        {
            auto it = m_map[key];

            // delete it
            m_list.erase(it);

            // put the data at the front
            m_list.push_front({ key, value });

            // update the hash map pointing to the list front.
            m_map[key] = m_list.begin();
        }
    };
}
