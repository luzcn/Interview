#pragma once
#include "stdafx.h"
#include <time.h>
#include <random>
// Design a data structure that support get(key), set(key, value), remove(key), getRandom() in O(1) time

namespace careercup
{
    template <typename T, typename U>
    class DataStorage
    {
    public:
        DataStorage()
        {}

        U get(T key)
        {
            if (map_key_value.find(key) == map_key_value.end())
            {
                throw exception("the value does not exist");
            }

            return map_key_value[key];
        }

        void set(T key, U value)
        {
            if (map_key_value.find(key) == map_key_value.end())
            {
                dataList.push_back(key);
                map_key_index[key] = dataList.size() - 1;
            }

            map_key_value[key] = value;
        }

        void remove(T key)
        {
            if (map_key_value.find(key) == map_key_value.end())
            {
                return;
            }

            // the key index int the array, which needs to remove
            int index = map_key_index[key];

            // copy the last element of array to this 
            dataList[index] = dataList.back();
            dataList.pop_back();

            // erase the key
            map_key_index.erase(key);
            map_key_value.erase(key);

            // update the key to index hash map 
            // make the entry points to the previously end element to the correct index
            map_key_index[dataList[index]] = index;
        }

        U getRandom()
        {
            srand((unsigned)time(nullptr));

            int rand_index = rand() % dataList.size();

            return map_key_value[dataList[rand_index]];
        }
    private:
        vector<T> dataList;            // store the key
        unordered_map<T, int> map_key_index;  // key, index to the dataList vector
        unordered_map<T, U> map_key_value;
    };
}