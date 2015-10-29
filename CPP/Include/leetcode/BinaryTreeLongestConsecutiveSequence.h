#pragma once
#include "stdafx.h"

//Given a binary tree, find the length of the longest consecutive sequence path.
//
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent - child connections.
// The longest consecutive path need to be from parent to child(cannot be the reverse).
namespace leetcode
{
    int dfs(TreeNode* root, TreeNode* parent, int& maxLen)
    {
        if (!root)
            return 0;

        auto L = dfs(root->left, root, maxLen) + 1;
        if (parent && parent->val + 1 != root->val)
            L = 1;

        auto R = dfs(root->right, root, maxLen) + 1;
        if (parent && parent->val + 1 != root->val)
            R = 1;

        maxLen = max(maxLen, max(L, R));
        return max(L, R);
    }

    int longest(TreeNode* root)
    {
        if (!root)
            return 0;

        int maxLen = 0;
        return dfs(root, nullptr, maxLen);
    }
}