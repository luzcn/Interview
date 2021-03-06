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

    // using the super template
    // two pointers + hash map
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;
        int start = 0, end = 0;
        int count = 0;  // counter of the duplicate char
        int maxLength = 0;

        while (end < s.size())
        {
            if (map[s[end++]]++ > 0)
            {
                count++;
            }

            while (count > 0)
            {
                if (map[s[start++]]-- > 1)
                {
                    count--;
                }
            }

            maxLength = max(maxLength, end - start);
        }

        return maxLength;
    }

}