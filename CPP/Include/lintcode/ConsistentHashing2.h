#pragma once
#include "stdafx.h"
#include <map>

namespace lintcode
{
    class Solution
    {
    public:
        static Solution create(int n, int k)
        {
            Solution s;
            s.n = n;
            s.k = k;

            for (int i = 0; i < n; i++)
            {
                s.availablePositions.push_back(i);
            }

            return s;
        }

        vector<int> addMachine(int machine_id)
        {
            // Write your code here
            vector<int> random_nums;
            for (int i = 0; i < k; ++i) 
            {
                int index = rand() % availablePositions.size();

                // idList has n elements
                random_nums.push_back(availablePositions[index]);

                // add to map
                shards[availablePositions[index]] = machine_id;

                // this id (data allocation) belongs to current machine_id now
                // remove this from the available
                availablePositions.erase(availablePositions.begin() + index);
            }

            sort(random_nums.begin(), random_nums.end());

            return random_nums;
        }

        int getMachineIdByHashCode(int hashcode)
        {
            // Write your code here
            map<int, int>::iterator it = shards.lower_bound(hashcode);

            if (it == shards.end())
            {
                return shards.begin()->second;
            }
            else
            {
                return it->second;
            }
        }

        int n;
        int k;
        vector<int> availablePositions;
        map<int, int> shards;
    };

}