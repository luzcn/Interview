#pragma  once
#include "stdafx.h"
#include <map>
#include <algorithm>

namespace Anagram
{
    void print(const std::map<std::string, std::string>& map)
    {
        if (map.empty())
            return;

        for (auto& pair : map)
        {
            std::cout << pair.first << "\t" << pair.second << std::endl;
        }
    }

    /// <summary>
    ///  Given a list of words, find all the anagram
    ///  For example, "stop" and "tops" are anagram.
    ///  
    ///  The simple solution is sorting each single word, save as the signature, "stop => opst"
    ///  All the works have the same signature are considered as anagram.
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    void find_anagram(std::vector<std::string> words)
    {
        if (words.empty())
            return;

        std::map<std::string, std::string> m_map;

        for (std::string& word : words)
        {
            std::string signature = word;
            std::sort(signature.begin(), signature.end());

            if (m_map.count(signature) > 0)
            {
                // append words, if they have same signature.
                m_map[signature].append("," + word);
            }
            else
            {
                m_map.emplace(signature, word);
            }
        }

        print(m_map);
    }
}

/*
int _tmain(int argc, _TCHAR* argv [])
{
std::vector<std::string> wordlist{ "pans", "pots", "opt", "snap", "stop", "tops" };

Anagram an;
an.find_anagram(wordlist);
return 0;
}*/