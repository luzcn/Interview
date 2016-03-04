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

            TrieNode* current = root;

            // O(k), k is the word length
            for (int i = 0; i < word.size(); i++)
            {
                // for each characters in the word, 
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
        bool dfs(TrieNode* node, const string& word, int pos)
        {
            if (!node)
                return false;

            if (pos >= word.size())
                return node->words > 0;

            if (word[pos] != '.')
            {
                return dfs(node->children[word[pos] - 'a'], word, pos + 1);
            }
            else
            {
                for (TrieNode* child : node->children)
                {
                    if (child && dfs(child, word, pos + 1))
                    {
                        return true;
                    }
                }
            }
        }

        //bool dfs(string& s, int pos, TrieNode* node)
        //{
        //    if (pos >= s.size())
        //        return node->words > 0;

        //    for (int i = 0; i < 26; i++)
        //    {
        //        if (node->children[i])
        //        {
        //            if (s[pos] == '.' || i == s[pos] - 'a')
        //            {
        //                if (dfs(s, pos + 1, node->children[i]))
        //                    return true;
        //            }
        //        }
        //    }
        //    
        //    return false;
        //}


        // the Trie prefix tree root node.
        TrieNode *root;

    };

}