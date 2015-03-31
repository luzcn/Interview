///   Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
///   
///   1. get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
///   
///   2. set(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, 
///   it should invalidate the least recently used item before inserting a new item.
/// 

#pragma once

#include "stdafx.h"
#include <unordered_map>
#include <list>

namespace LRUCache
{
    /// <summary>
    ///  The Cache data item structure.
    /// </summary>
    struct CacheData 
    {
        int key;
        int value;
        CacheData(int k, int v)
            :key(k), value(v)
        {}
    };

    /// <summary>
    ///  
    /// </summary>
    class LRUCache
    {
    public:
        LRUCache(int capacity)
            :m_capacity(capacity)
        {
        }

        int get(int key)
        {
            if (m_map.find(key) == m_map.end())
                return -1;

            // Move to Head
            move_to_head(key);

            return m_map[key]->value;
        }

        void set(int key, int value)
        {
            if (m_map.find(key) == m_map.end())  // new data
            {
                CacheData new_data(key, value);

                if (m_map.size() >= m_capacity)
                {
                    // Remove the end (least used element) from m_LRUCache list.
                    m_map.erase(m_LRUCache.back().key);
                    m_LRUCache.pop_back();
                }

                // Insert to the front of m_LRUCache list.
                m_LRUCache.push_front(new_data);
                m_map[key] = m_LRUCache.begin();
            }
            else
            {
                m_map[key]->value = value;  // update the value, which already in the LRUCache list.

                // Move to head
                move_to_head(key);
            }

        }

    private:
        std::unordered_map<int, std::list<CacheData>::iterator> m_map;
        int m_capacity;
        std::list<CacheData> m_LRUCache;
        //std::list < std::pair<int, int> > 
        

        /// <summary>
        ///  
        /// </summary>
        /// <param name=""> </param>
        void move_to_head(int key)
        {
            auto copy_dataentry = *m_map[key];
            m_LRUCache.erase(m_map[key]);
            m_LRUCache.push_front(copy_dataentry);

            // Update the hash map value, since it is a reference to the element in LRUCache list.
            m_map[key] = m_LRUCache.begin();
        }
    };
}
