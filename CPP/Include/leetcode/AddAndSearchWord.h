#pragma once
#include "stdafx.h"

// Add and Search Word - Data structure design
//Design a data structure that supports the following two operations :
//
//  void addWord(word)
//  bool search(word)
//
//  search(word) can search a literal word or a regular expression string containing only letters a - z or ..
//
//  A "." means it can represent any one letter.
//
//  For example :
//
//  addWord("bad")
//  addWord("dad")
//  addWord("mad")
//  search("pad") -> false
//  search("bad") -> true
//  search(".ad") -> true
//  search("b..") -> true
//
//  Note:
//  You may assume that all words are consist of lowercase letters a - z.

// Thought: build trie.
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
            return dfs(root, word, 0);
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

            return false;
        }

        // the Trie prefix tree root node.
        TrieNode *root;

    };

}