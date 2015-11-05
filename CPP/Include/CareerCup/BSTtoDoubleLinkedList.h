#pragma once
#include "stdafx.h"

// Convert a binary search tree to a sorted double-linked list. 
// We can only change the target of pointers, but cannot create any new nodes
// Thought: In-order traverse bst will give sorted result
// 1. if current node has left subtree, process the left subtree
//    a. Resursively convert the left subtree to double linked list.
//    b. Then find the right most node in this left subtree, which will be the predecessor of the root node.
//    c. make this inorder predecessor node as previous of root and root as the next of this inorder predecessor.
// 2. if right subtree exists, process the right subtree.
namespace careercup
{
    TreeNode* convert(TreeNode* node)
    {
        if (!node)
            return nullptr;

        if (node->left)
        {
            // process the left subtree
            auto left = convert(node->left);

            // find the right most node in the left subtree
            while (left->right)
            {
                left = left->right;
            }

            left->right = node;
            node->left = left;
        }

        if (node->right)
        {
            // process the right subtree
            auto right = convert(node->right);

            // find the left most node in the right subtree
            while (right->left)
            {
                right = right->left;
            }

            right->left = node;
            node->right = right;
        }

        return node;
    }

    TreeNode* convertBSTtoList(TreeNode* root)
    {
        auto head = convert(root);

        while (head && head->left)
        {
            head = head->left;
        }

        return head;
    }
}