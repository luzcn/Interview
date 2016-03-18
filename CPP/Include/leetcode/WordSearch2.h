#pragma once
#include "stdafx.h"

// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.
//
// For example,
// Given words = ["oath", "pea", "eat", "rain"] and board =
//
// [
//    ['o', 'a', 'a', 'n'],
//    ['e', 't', 'a', 'e'],
//    ['i', 'h', 'k', 'r'],
//    ['i', 'f', 'l', 'v']
// ]
//
// Return["eat", "oath"].
// from the hint, we should use Trie
namespace leetcode
{
    struct TrieNode
    {
        TrieNode()
            :wordCounts(0)
        {}

        int wordCounts;
        TrieNode* children[26]{ nullptr };
    };

    class Solution
    {
    public:
        Solution()
        {
            root = new TrieNode();
        }

        // words may have duplicates, each word can use only once
        vector<string> findWords(vector<string>& board, vector<string>& words)
        {
            if (board.empty() || words.empty())
                return{};

            constructTrie(words);

            int m = board.size();
            int n = board[0].size();

            vector<string> result;
            string current;

            // dfs search
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));

                    if (root->children[board[i][j] - 'a'])
                    {
                        dfs(board, result, current, i, j, visited, root);
                    }
                }
            }

            sort(result.begin(), result.end());
            return result;
        }
    private:
        TrieNode* root;
        TrieNode* test;

        void constructTrie(vector<string>& words)
        {
            TrieNode* current = nullptr;
            for (string& word : words)
            {
                // for each word, construct from root.
                current = root;

                for (const char& c : word)
                {
                    int index = c - 'a';
                    if (!current->children[index])
                    {
                        current->children[index] = new TrieNode();
                    }
                    current = current->children[index];
                }

                // The problem does not want duplicate
                // so set the word count to "1"
                current->wordCounts = 1;
                //current->wordCounts++;
            }
        }

        void dfs(vector<string>& board, vector<string>& result,
            string& current, int i, int j, vector<vector<bool>>& visited, TrieNode* node)
        {
            if (!node)
                return;

            if (node->wordCounts > 0)
            {
                result.push_back(current);
                node->wordCounts--;
            }

            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
                return;

            if (!visited[i][j] && node->children[board[i][j] - 'a'])
            {
                visited[i][j] = true;
                current.push_back(board[i][j]);

                dfs(board, result, current, i - 1, j, visited, node->children[board[i][j] - 'a']);
                dfs(board, result, current, i + 1, j, visited, node->children[board[i][j] - 'a']);
                dfs(board, result, current, i, j + 1, visited, node->children[board[i][j] - 'a']);
                dfs(board, result, current, i, j - 1, visited, node->children[board[i][j] - 'a']);

                current.pop_back();
                visited[i][j] = false;
            }
        }
    };
}