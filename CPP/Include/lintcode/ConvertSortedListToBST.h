#pragma once
#include "stdafx.h"

//Convert Sorted List to Binary Search Tree
//
//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//Example
//
//             2
//1->2->3 = > / \
//           1   3
namespace lintcode
{
    TreeNode* buildRec(ListNode* head, int size)
    {
        if (!head || size <= 0)
            return nullptr;

        int i = 0;
        auto p = head;
        while (p && i < size / 2)
        {
            p = p->next;
            i++;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = buildRec(head, size / 2);
        root->right = buildRec(p->next, size - 1 - size / 2);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        if (!head)
            return nullptr;

        auto p = head;
        int size = 0;
        while (p)
        {
            size++;
            p = p->next;
        }

        return buildRec(head, size);
    }
}