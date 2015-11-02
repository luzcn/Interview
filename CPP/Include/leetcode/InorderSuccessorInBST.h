#pragma once
#include "stdafx.h"

namespace leetcode
{
    TreeNode* getParent(TreeNode* root, TreeNode* p, TreeNode* parent)
    {
        if (!root)
            return nullptr;

        if (root == p)
            return parent;

        auto L = getParent(root->left, p, root);
        auto R = getParent(root->right, p, root);

        if (L)
        {
            return L;
        }
        else
        {
            return R;
        }
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if (!p || !root)
            return nullptr;


        TreeNode* successor = nullptr;
        if (p->right)
        {
            // if p has right child, find the left-most node in the right sub tree
            successor = p->right;
            while (successor->left)
            {
                successor = successor->left;
            }
            return successor;
        }
        else
        {
            // the successor is the partent of p, if p is the left child of its parent.
            TreeNode* parent = getParent(root, p, nullptr);

            // if p is the right child of its parent, need to keep finding its parent, 
            // util the parent is nullptr or it is left child.
            auto x = p;
            auto y = parent;
            while (y && y->right == x)
            {
                x = y;
                y = getParent(root, x, nullptr);
            }

            return y;
        }

    }
}