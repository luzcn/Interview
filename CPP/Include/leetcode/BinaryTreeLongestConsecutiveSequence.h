#pragma once
#include "stdafx.h"

//Given a binary tree, find the length of the longest consecutive sequence path.
//
//The path refers to any sequence of nodes from some starting node to any node in the tree along the parent - child connections.
// The longest consecutive path need to be from parent to child(cannot be the reverse).
namespace leetcode
{
    int dfs(TreeNode* node, int& maxLen)
    {
        if (!node)
            return 0;

        int leftLen = dfs(node->left, maxLen) + 1;
        int rightLen = dfs(node->right, maxLen) + 1;

        if (node->left && node->val + 1 != node->left->val)
        {
            leftLen = 1;
        }
        if (node->right && node->val + 1 != node->right->val)
        {
            rightLen = 1;
        }

        maxLen = max(maxLen, max(leftLen, rightLen));

        return max(leftLen, rightLen);
    }

    int longest(TreeNode* root)
    {
        if (!root)
            return 0;

        int maxLen = 0;
        return dfs(root, maxLen);
    }
}