#pragma once
#include "stdafx.h"
#include <unordered_set>
#include <unordered_map>

/**
 *	 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

 Your algorithm should run in O(n) complexity.


 */
namespace LongestConsecutiveSequence
{

    /**
     *
     - We cannot sort, since it requires O(n) complexity.
     - A traditional space trade time solution, use a hashmap/hashset
     1. for each number "n" in the given vector:
     - check if the num -1 is in the hashmap, continue as loop if it is in the hashmap
     - check if the num + 1 is in the hashmap, continue as loop if yes.
     2. Trace the longest sequence.
     */
    int longestConsecutive(vector<int> &num)
    {
        unordered_set<int> set(num.begin(), num.end());

        int longest = 0;

        for (int n : num)
        {
            int count = 0;
            int temp = n;   // copy the current number

            while (set.find(temp) != set.end())
            {
                set.erase(temp);
                temp = temp - 1;
                count++;
            }
            temp = n + 1;
            while (set.find(temp) != set.end())
            {
                set.erase(temp);
                temp = temp + 1;
                count++;
            }
            longest = max(longest, count);
        }

        return longest;
    }

}