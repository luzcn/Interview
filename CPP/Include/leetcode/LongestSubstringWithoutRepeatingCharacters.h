#pragma once

#include "stdafx.h"
#include <unordered_map>

namespace LongestSubstringWithoutRepeatingCharacters
{
    typedef std::unordered_map<char, int> hash_map;

    /***
     *	The burte force solution
     *	O(n^2) solution.
     */
    int lengthOfLongestSubstring_bruteforce(string s)
    {
        if (s.empty())
            return 0;

        hash_map map;
        int max_len = 1;
        int start = 0;
        int index = start + 1;
        map.emplace(s[start], 1);

        while (index < s.size())
        {
            char c = s[index];

            if (map.count(c) > 0)
            {
                map.clear();
                start++;
                index = start + 1;
                map.emplace(s[start], 1);
            }
            else
            {
                max_len = max(max_len, index - start + 1);
                index++;
                map.emplace(c, 1);
            }
        }

        return max_len;
    }

    /***
     *	The O(n) solution
     *	use the hash_map second value to store the index.
     */
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        hash_map map;
        int last_index = -1;
        int max_len = 0;

        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (map.count(c) > 0 && last_index < map[c])
            { 
                last_index = map[c];
            }

            map[c] = i;
            max_len = max(max_len, i - last_index);

        }

        return max_len;

    }

}