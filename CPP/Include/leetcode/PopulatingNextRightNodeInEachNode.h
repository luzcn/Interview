#pragma once
#include "stdafx.h"

//Given a binary tree
//
//struct TreeLinkNode {
//    TreeLinkNode *left;
//    TreeLinkNode *right;
//    TreeLinkNode *next;
//}
//
//Populate each next pointer to point to its next right node.If there is no next right node, 
//the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//You may assume that it is a perfect binary tree(ie, all leaves are at the same level, and every parent has two children).
//
//For example,
//Given the following perfect binary tree,
//
//     1
//   /   \
//  2     3
// / \   / \
//4  5   6  7
//
//After calling your function, the tree should look like :
//
//1->NULL
/// \
//2 -> 3->NULL
/// \ / \
//4->5->6->7->NULL


namespace leetcode
{
    class TreeLinkNode
    {
    public:
        TreeLinkNode *left;
        TreeLinkNode *right;
        TreeLinkNode *next;
        int val;

        TreeLinkNode(int v)
            :val(v)
        {}
    };
    // Since the tree is perfect binary tree, we can recurisvely solve the problem.
    // For each node:
    // 1. node->left->next = node->right
    // 2. if node->next. next->right->next = node->next->left
    void connect(TreeLinkNode* node)
    {
        if (!node)
            return;

        if (node->left)
            node->left->next = node->right;

        if (node->right && node->next)
            node->right->next = node->next->left;

        connect(node->left);
        connect(node->right);
    }

    // If the given binary tree is any binary tree.
    void connect2(TreeLinkNode* node)
    {
        if (!node)
            return;

        if (node->left)
        {
            if (node->right)
                node->left->next = node->right;
            else
            {
                auto p = node->next;
                while (p)
                {
                    if (p->left || p->right)
                    {
                        node->left->next = p->left ? p->left : p->right;
                        break;
                    }
                    p = p->next;
                }
            }
        }

        if (node->right)
        {
            auto p = node->next;
            while (p)
            {
                if (p->left || p->right)
                {
                    node->right->next = p->left ? p->left : p->right;
                    break;
                }
                p = p->next;
            }
        }

        // It must be right subtree first.
        connect2(node->right);
        connect2(node->left);
    }
}