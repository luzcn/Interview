#pragma once
#include "stdafx.h"

//Given a binary tree, count the number of uni - value subtrees.
//
//A Uni - value subtree means all nodes of the subtree have the same value.
//
//For example :
//Given binary tree,
//
//       5
//      / \
//     1   5
//    / \   \
//   5   5   5
//
//return 4.

namespace leetcode
{
    // 1. every leaf node is a univalue subtree, 
    // 2. if any subtree is univalue, return true;
    // 3. if the leftsub tree and right subtree both return true, check if the subtree with current node is univalue
    bool dfs(TreeNode* node, int& count)
    {
        if (!node)
            return true;

        if (!node->left && !node->right)
        {
            count++;
            return true;
        }

        bool L = dfs(node->left, count);
        bool R = dfs(node->right, count);

        if (L && R)
        {
            if (node->left && node->right && node->val == node->left->val && node->val == node->right->val
                || !node->left && node->val == node->right->val
                || !node->right && node->val == node->left->val)
            {
                count++;
                return true;
            }
            else
                return false;
        }

        return false;
    }

    int countUnivalSubtrees(TreeNode* root)
    {
        if (!root)
            return 0;

        int count = 0;

        dfs(root, count);

        return count;
    }
}