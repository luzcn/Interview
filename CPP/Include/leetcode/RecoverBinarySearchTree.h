#pragma once
#include "stdafx.h"

// Two elements of a binary search tree(BST) are swapped by mistake.
// Recover the tree without changing its structure.
// 
// Note:
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution ?

namespace leetcode
{
    /*
    void inorder(TreeNode* node, vector<TreeNode*>& list)
    {
        if (!node)
            return;

        inorder(node->left, list);
        list.push_back(node);
        inorder(node->right, list);
    }
    void recoverTree(TreeNode* root)
    {
        if (!root)
            return;

        vector<TreeNode*> list;
        inorder(root, list);

        TreeNode* n1 = nullptr;
        TreeNode* n2 = nullptr;

        // list[0,1,2...n-1] should be in increasing order
        for (int i = 0; i < list.size() - 1; i++)
        {
            if (list[i]->val > list[i + 1]->val)
            {
                n1 = list[i];
                break;
            }
        }

        // scan from the last element, should in decreasing order.
        for (int i = list.size() - 1; i > 0; i--)
        {
            if (list[i]->val < list[i - 1]->val)
            {
                n2 = list[i];
                break;
            }
        }

        // swap
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
    }
    */

    TreeNode* prev = nullptr;

    void in_order(TreeNode* node, TreeNode*& mis_node)
    {
        if (!node)
        {
            return;
        }

        in_order(node->left, mis_node);
        if (prev && prev->val > node->val)
        {
            mis_node = prev;
            return;
        }
        prev = node;
        in_order(node->right, mis_node);
    }


    void recoverTree(TreeNode* root)
    {
        if (!root)
            return;

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Recursive needs O(n) space of call stacks
        //in_order(root, nullptr, first, false);
        //in_order(root, nullptr, second, true);

        in_order(root, first);

        if (first && second)
        {
            int t = first->val;
            first->val = second->val;
            second->val = t;
        }
    }
}