// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int lengthOfLongestSubstring(string str)
{
    if (str.empty())
        return 0;

    int len = 1;
    unordered_map<char, int> map;

    int start = 0;
    int end = start;
    int current_len = 0;

    while (end < str.size())
    {
        char c = str[end];
        if (map.find(c) == map.end()) // not duplicate
        {
            map.emplace(c, end);
            current_len++;
            end++;
        }
        else
        {
            if (map[c] >= start)
            {
                start = map[c] + 1;
            }
            map[c] = end;
            current_len = end - start + 1;
            end++;
        }

        if (current_len > len)
            len = current_len;
    }

    return len;
}

#if 0
int lengthOfLongestSubstring(string s)
{
    if (s.empty())
        return 0;

    unordered_map<char, int> map; 
    int maxLen = 1;
    int currentLen = 0;
    int i = 0;

    while (i < s.size())
    {
        char c = s[i];
        if (map.find(c) == map.end()) // no dup
        {
            map.emplace(c, i);
            currentLen++;
            i++;
        }
        else
        {
            if (i - map[c] + 1 > maxLen)
            {
                int temp = map[c];
                map[c] = i;
                i = temp + 1;
            }
            else
            {
                i++;
            }
            currentLen = 1;
        }

        if (currentLen > maxLen)
            maxLen = currentLen;
    }

    return maxLen;
}
#endif
int _tmain(int argc, _TCHAR* argv [])
{
    cout << lengthOfLongestSubstring("qwnfenpglqdq") << endl;
    return 0;
}