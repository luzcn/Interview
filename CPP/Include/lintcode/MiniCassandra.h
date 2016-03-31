#pragma once
#include "stdafx.h"
#include <map>

// Cassandra is a NoSQL storage.The structure has two - level keys.
//
// Level 1: raw_key.The same as hash_key or shard_key.
// Level 2 : column_key.
// Level 3 : column_value
//
// - raw_key is used to hash and can not support range query. let's simplify this to a string.
// - column_key is sorted and support range query. let's simplify this to integer.
// - column_value is a string. you can serialize any data into a string and store it in column value.
//
// implement the following methods :
//
// - insert(raw_key, column_key, column_value)
// - query(raw_key, column_start, column_end) // return a list of entries

namespace lintcode
{
    
    class Column 
    {
    public:
        int key;
        string value;

        Column(int key, string value) 
        {
            this->key = key;
            this->value = value;
        }
    };
    
    class MiniCassandra 
    {
    public:
        MiniCassandra() 
        {
            // initialize your data structure here.
        }

        /**
        * @param raw_key a string
        * @param column_start an integer
        * @param column_end an integer
        * @return void
        */
        void insert(string raw_key, int column_key, string column_value)
        {
            // Write your code here
            mapData[raw_key][column_key] = column_value;
        }

        /**
        * @param raw_key a string
        * @param column_start an integer
        * @param column_end an integer
        * @return a list of Columns
        */
        vector<Column> query(string raw_key, int column_start, int column_end)
        {
            // Write your code here
            vector<Column> result;

            for (const auto& p : mapData[raw_key])
            {
                if (p.first >= column_start && p.first <= column_end)
                {
                    result.push_back({ p.first, p.second });
                }
            }

            return result;
        }
    private:
        unordered_map<string, map<int, string>> mapData;
    };
}
