#pragma once
#include "stdafx.h"

// Binary Tree Upside Down
//Given a binary tree where all the right nodes are either leaf nodes with a sibling
// (a left node that shares the same parent node) or empty, 
// flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes.Return the new root.
//For example :
//Given a binary tree{ 1,2,3,4,5 },
//
//1
/// \
//2   3
/// \
//4   5
//
//return the root of the binary tree[4, 5, 2, #, #, 3, 1].
//
//4
/// \
//5   2
/// \
//3   1
namespace leetcode
{
    void dfs(TreeNode* node)
    {
        if (!node)
            return;

        TreeNode* t = node->left;

        dfs(node->left);
        if (t)
        {
            t->left = node->right;
            t->right = node;
        }
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root)
    {
        // find the leftmost node, which will be the return root node
        if (!root)
            return nullptr;

        TreeNode* result = root;
        while (result->left)
        {
            result = result->left;
        }

        dfs(root);
        root->left = nullptr;
        root->right = nullptr;

        return result;
    }
}