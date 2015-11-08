#pragma once
#include "stdafx.h"

namespace LowestCommonAncestor
{
    // Given a binary tree, find the lowest common ancestor of two given nodes in the tree.
    TreeNode* LCA(TreeNode* node, int n1, int n2)
    {
        if (!node)
            return nullptr;
        if (node->val == n1 || node->val == n2)
        {
            return node;
        }

        auto left = LCA(node->left, n1, n2);
        auto right = LCA(node->right, n1, n2);

        if (left && right)
        {
            return node;
        }
        else if (left == nullptr)
        {
            return right;
        }
        else
            return left;
    }
}