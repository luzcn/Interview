#pragma once
#include "stdafx.h"

namespace leetcode
{
    struct TrieNode
    {
        int words;
        TrieNode* children[26];

        TrieNode()
            :words(0)
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    class WordDictionary
    {
    public:
        WordDictionary()
        {
            root = new TrieNode();
        }

        // Adds a word into the data structure.
        void addWord(string word)
        {
            if (word.empty())
                return;

            auto current = root;
            for (int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                int index = c - 'a';
                if (!current->children[index])
                {
                    TrieNode* temp = new TrieNode();
                    current->children[index] = temp;
                }
                current = current->children[index];
            }
            current->words++;
        }

        // Returns if the word is in the data structure. A word could
        // contain the dot character '.' to represent any one letter.
        bool search(string word)
        {
            return dfs(word, 0, root);
        }

    private:
        // helper function to search the word
        bool dfs(string& s, int pos, TrieNode* node)
        {
            if (pos >= s.size())
                return node->words > 0;

            for (int i = 0; i < 26; i++)
            {
                if (node->children[i])
                {
                    if (s[pos] == '.' || i == s[pos] - 'a')
                    {
                        if (dfs(s, pos + 1, node->children[i]))
                            return true;
                    }
                }
            }
            
            return false;
        }


        // the Trie prefix tree root node.
        TrieNode *root;

    };

}