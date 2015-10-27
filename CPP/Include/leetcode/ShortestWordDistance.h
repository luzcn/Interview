#pragma once
#include "stdafx.h"
//#include <map>
//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
//For example,
//Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
//Given word1 = “coding”, word2 = “practice”, return 3.
//Given word1 = "makes", word2 = "coding", return 1.
//
//Note:
//You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
namespace leetcode
{
    int shortestDistance(vector<string>& words, string word1, string word2)
    {
        int p = -1, q = -1;
        int distance = INT_MAX;

        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
            {
                p = i;
                if (q != -1)
                {
                    distance = min(distance, abs(p - q));
                }
            }
            else if (words[i] == word2)
            {
                q = i;
                if (p != -1)
                {
                    distance = min(distance, abs(p - q));
                }
            }
        }

        return distance;
    }


    // shortest word distance 2
    class WordDistance
    {
    public:
        WordDistance(vector<string>& words)
        {
            for (int i = 0; i < words.size(); i++)
            {
                map.emplace(words[i], i);
            }
        }

        int shortest(string word1, string word2)
        {
            // pair<unordered_multimap<string, int>::iterator, unordered_multimap<string, int>::iterator>
            auto it1 = map.equal_range(word1);
            auto it2 = map.equal_range(word2);

            int distance = INT_MAX;
            for (auto p = it1.first; p != it1.second; p++)
            {
                for (auto q = it2.first; q != it2.second; q++)
                {
                    distance = min(distance, abs(p->second - q->second));
                }
            }

            return distance;
        }
    private:
        std::unordered_multimap<string, int> map;
    };


    //This is a follow up of Shortest Word Distance.The only difference is now word1 could be the same as word2.

    //    Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

    //    word1 and word2 may be the same and they represent two individual words in the list.

    //    For example,
    //    Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

    //    Given word1 = “makes”, word2 = “coding”, return 1.
    //    Given word1 = "makes", word2 = "makes", return 3.
    int shortestWordDistance(vector<string>& words, string word1, string word2) 
    {
        std::unordered_multimap<string, int> map;
        for (int i = 0; i < words.size(); i++)
        {
            map.emplace(words[i], i);
        }

        auto it1 = map.equal_range(word1);
        auto it2 = map.equal_range(word2);

        int shortest = INT_MAX;
        for (auto p = it1.first; p != it1.second; p++)
        {
            for (auto q = it2.first; q != it2.second; q++)
            {
                auto distance = abs(p->second - q->second);
                if (distance != 0 && distance < shortest)
                {
                    shortest = distance;
                }
            }
        }

        return shortest;
    }
}