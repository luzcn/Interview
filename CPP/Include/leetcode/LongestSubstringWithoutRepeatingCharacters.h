#pragma once

#include "stdafx.h"
#include <unordered_map>

namespace LongestSubstringWithoutRepeatingCharacters
{
    typedef std::unordered_map<char, int> hash_map;

    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        hash_map map;
        int last_index = 0;
        int max_len = 0;

        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (map.count(c) > 0 && last_index <= map[c])
            {
                last_index = map[c] + 1;
            }

            map[c] = i;
            max_len = max(max_len, i - last_index + 1);

        }

        return max_len;

    }

}