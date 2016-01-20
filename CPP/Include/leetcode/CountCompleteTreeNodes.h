#pragma once
#include "stdafx.h"

// Given a complete binary tree, count the number of nodes.
//
// Definition of a complete binary tree from Wikipedia :
// In a complete binary tree every level, except possibly the last, is completely filled, 
// and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.

namespace leetcode
{
    int countNodes(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }

        int depth = 0;
        auto l = root;
        auto r = root;

        while (l && r)
        {
            depth++;
            l = l->left;
            r = r->right;
        }

        if (!l && !r)
        {
            return (1 << depth) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }


    // Binary search solution
    TreeNode* getNode(TreeNode* root, int path, int depth)
    {
        while (depth-- && root)
        {
            if (path & (1 << depth))
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return root;
    }

    int countNodesBS(TreeNode* root)
    {
        int depth = 0;
        TreeNode* node = root;

        while (node)
        {
            depth++;
            node = node->left;
        }

        if (depth == 0)
        {
            return 0;
        }

        int left = 0, right = (1 << (depth - 1)) - 1;

        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return (1 << (depth - 1)) + right;
    }
}