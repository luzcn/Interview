#pragma once
#include "stdafx.h"
#include <map>

//Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
//
//If two nodes are in the same row and column, the order should be from left to right.
//
//Examples:
//Given binary tree[3, 9, 20, null, null, 15, 7],
//
//     3
//    / \
//   9  20
//      / \
//     15  7
//
//return its vertical order traversal as :
//
//[
//    [9],
//    [3, 15],
//    [20],
//    [7]
//]

namespace leetcode
{
    void dfs(TreeNode* node, int key, std::map<int, vector<int>>& map)
    {
        if (!node)
        {
            return;
        }

        map[key].push_back(node->val);
        dfs(node->left, key - 1, map);
        dfs(node->right, key + 1, map);
    }

    vector<vector<int>> bfs(TreeNode* root)
    {
        if (!root)
            return{};

        std::map<int, vector<int>> map;    // the vertical value, list of tree node value
        std::queue<pair<TreeNode*, int>> que;

        que.emplace(root, 0);

        while (!que.empty())
        {
            TreeNode* current = que.front().first;
            int key = que.front().second;
            que.pop();

            map[key].push_back(current->val);

            if (current->left)
            {
                que.push(pair<TreeNode*, int>(current->left, key - 1));
            }
            if (current->right)
            {
                que.push(pair<TreeNode*, int>(current->right, key + 1));
            }
        }

        vector<vector<int>> result;
        for (auto p : map)
        {
            result.push_back(p.second);
        }

        return result;

    }

    vector<vector<int>> verticalOrder(TreeNode* root)
    {
        if (!root)
            return{};

        std::map<int, vector<int>> dict;    // the vertical value, list of tree node value

        dfs(root, 0, dict);

        vector<vector<int>> result;
        for (auto p : dict)
        {
            result.push_back(p.second);
        }

        return result;
    }
}