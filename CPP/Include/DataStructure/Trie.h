#pragma once
#include "stdafx.h"

namespace datastructur
{
    class TrieNode
    {
    public:
        int words;  // used to indicate the leaf node
        int prefixes;   // used to count how may words has this common prefix
        vector<TrieNode*> children;

        TrieNode()
            :words(0), prefixes(0)
        {
            children.resize(26);
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    class Trie
    {
    public:
        Trie()
        {
            root = new TrieNode();
        }

        void addWord(const string& word)
        {
            auto current = root;

            for (int i = 0; i < word.size(); i++)
            {
                current->prefixes++;
                char c = word[i];
                int index = c - 'a';    // only consider lower case 26 alphabet
                if (!current->children[index])
                {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->words++;   // the dictionary may contain duplicate words
        }

        int countWords(const string& word)
        {
            if (word.empty())
                return true;

            auto current = root;
            for (int i = 0; i < word.size(); i++)
            {
                char c = word[i];
                int index = c - 'a';

                if (!current->children[index])
                {
                    return 0;
                }

                current = current->children[index];
            }

            if (!current)
                return 0;

            return current->words;
        }

        int countPrefix(const string& prefix)
        {
            if (prefix.empty())
                return root->prefixes;

            auto current = root;
            for (int i = 0; i < prefix.size(); i++)
            {
                char c = prefix[i];
                int index = c - 'a';

                if (!current->children[index])
                {
                    return 0;
                }

                current = current->children[index];
            }
            return current->prefixes;
        }
    private:
        TrieNode* root;
    };
}

#if 0
int main()
{
    Trie t;

    vector<string> v{ "the", "their", "there",  "there" ,"list", "good" };

    for (string& s : v)
    {
        t.addWord(s);
    }

    cout << t.countWords(v[2]);
    cout << t.countPrefix("the");
    return 0;
}
#endif