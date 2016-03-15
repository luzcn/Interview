#pragma once
#include "stdafx.h"

namespace leetcode
{
    struct TrieNode
    {
        // Initialize your data structure here.
        TrieNode()
            :words(0)
        {
        }

        int words;
        TrieNode* children[26]{ nullptr };
    };

    class Trie
    {
    public:
        Trie()
        {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word)
        {
            if (word.empty())
                return;

            TrieNode* current = root;

            for (char c : word)
            {
                int index = c - 'a';
                if (!current->children[index])
                {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->words++;
        }

        // Returns if the word is in the trie.
        bool search(string word)
        {
            if (word.empty())
                return true;

            auto current = root;

            for (char c : word)
            {
                int index = c - 'a';
                if (!current->children[index])
                {
                    return false;
                }
                current = current->children[index];
            }

            return current->words > 0;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix)
        {
            if (prefix.empty())
                return true;

            TrieNode* current = root;
            for (char c : prefix)
            {
                int index = c - 'a';
                if (!current->children[index])
                {
                    return false;
                }
                current = current->children[index];
            }

            return true;
        }

    private:
        TrieNode* root;
    };

    // Your Trie object will be instantiated and called as such:
    // Trie trie;
    // trie.insert("somestring");
    // trie.search("key");
}