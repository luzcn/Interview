#pragma once
#include "stdafx.h"

//An abbreviation of a word follows the form <first letter><number><last letter>.Below are some examples of word abbreviations :
//
//a) it--> it(no abbreviation)
//
//1
//b) d | o | g--> d1g
//
//1    1  1
//1-- - 5----0----5--8
//c) i | nternationalizatio | n--> i18n
//
//1
//1-- - 5----0
//d) l | ocalizatio | n--> l10n
//
//Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
// A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
//Example:
//
//Given dictionary = ["deer", "door", "cake", "card"]
//
//isUnique("dear") -> false
//isUnique("cart") -> true
//isUnique("cane") -> false
//isUnique("make") -> true
namespace leetcode
{
    class ValidWordAbbr {
    public:
        ValidWordAbbr(vector<string> &dictionary)
        {
            for (string s : dictionary)
            {
                dict[s]++;
                map[process(s)]++;
            }
        }

        bool isUnique(string word)
        {
            // 2 conditions will return true
            // 1. abbreviate is not in the map
            // 2. word in dictionary and no other words have the same abbreviation.
            string abbreviate = process(word);
            if (dict.find(word) != dict.end() && dict[word] == map[abbreviate])
            {
                return true;
            }

            if (map.find(abbreviate) != map.end())
            {
                return false;
            }

            return true;
        }
    private:
        unordered_map<string, int> map;
        unordered_map<string, int> dict;


        string process(string& t)
        {
            if (t.size() <= 2)
                return t;

            string result = "";
            result.push_back(t[0]);
            result.append(to_string(t.size() - 2));
            result.push_back(t.back());

            return result;
        }
    };
}