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
    string encode(string& s)
    {
        int diff = 0;
        string encodeStr;
        for (int i = 1; i < s.size(); i++)
        {
            diff = s[i] - s[i - 1];
            if (diff < 0)
                diff += 26;

            encodeStr += 'a' + diff + ',';
        }

        return encodeStr;
    }

    vector<vector<string>> groupStrings(vector<string>& strings)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;

        if (strings.empty())
            return result;

        for (string& str : strings)
        {
            string encodeStr = std::move(encode(str));
            map[encodeStr].push_back(str);
        }

        for (auto& p : map)
        {
            sort(p.second.begin(), p.second.end());

            result.push_back(p.second);
        }

        return result;
    }

    // follow up:
    // if each time shit 2 successive character: abc => cde => efg => ... => yza; bcd => def => ... zab
    // the solution is similiar, but when compute the diff, we divide by 2,
    // and compute the final character, we set t[i] = t[i]-diff*2;
}
