#pragma once
#include "stdafx.h"

//Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd".
//We can keep "shifting" which forms the sequence :
//
//"abc" -> "bcd" -> ... -> "xyz"
//
//Given a list of strings which contains only lowercase alphabets, 
// group all strings that belong to the same shifting sequence.
//
//For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
//Return :
//
//    [
//          ["abc", "bcd", "xyz"],
//          ["az", "ba"],
//          ["acef"],
//          ["a", "z"]
//    ]

// ["ab","ba"] returns [["ab"], ["ba"]]
namespace leetcode
{
    vector<vector<string>> groupStrings(vector<string>& strings)
    {
        std::unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for (auto& str : strings)
        {
            string t = str;
            int diff = t[0] - 'a';

            for (int i = 0; i < t.size(); i++)
            {
                if (t[i] - diff - 'a'>= 0)
                {
                    t[i] = t[i] - diff;
                }
                else
                {
                    t[i] = t[i] - diff  + 1 + 26;
                }
            }

            map[t].push_back(str);
        }

        for (auto it = map.begin(); it != map.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
            res.push_back(it->second);
        }
        return res;
    }

    // follow up:
    // if each time shit 2 successive character: abc => cde => efg => ... => yza; bcd => def => ... zab
    // the solution is similiar, but when compute the diff, we divide by 2,
    // and compute the final character, we set t[i] = t[i]-diff*2;
}
