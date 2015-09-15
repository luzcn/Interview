#pragma once
#include "stdafx.h"

// Binary Search Tree related functions:
// 1. construct a balanced binary search tree from sorted array
// 2. construct a balanced binary search tree from sorted linked list
// 3. some foundmental binary search tree operations.
namespace datastructure
{
    // construct a balanced binary search tree from sorted array
    TreeNode* buildBST(vector<int>& v, int l, int r)
    {
        if (l > r)
            return nullptr;

        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(v[m]);
        root->left = buildBST(v, l, m - 1);
        root->right = buildBST(v, m + 1, r);

        return root;
    }

    // construct a balanced binary search tree from sorted linked list
    TreeNode* buildBST(ListNode* head, int size)
    {
        if (!head || size <= 0)
            return nullptr;

        int i = 0;
        ListNode* p = head;
        while (p && i < size / 2)
        {
            p = p->next;
            i++;
        }
        TreeNode* root = new TreeNode(p->val);
        root->left = buildBST(head, size / 2);
        root->right = buildBST(p->next, size - size / 2 - 1);

        return root;
    }

    // insert a new node
    TreeNode* insert(TreeNode* root, int v)
    {
        if (!root)
            return new TreeNode(v);

        if (root->val > v)
            root->left = insert(root->left, v);
        else
            root->right = insert(root->right, v);
    }

    // The Delete, Successor and predecessor operations may need "parent" pointer
    namespace details
    {
        // A binary tree node with parent pointer
        struct TNode
        {
            int val;
            TNode* left;
            TNode* right;
            TNode* parent;

            TNode(int v)
                :val(v)
            {}
        };

        // find the tree node which is the successor of the input node in output sorted list
        TNode* successor(TNode* node)
        {
            if (!node)
                return node;

            // if the node has right children, 
            // find the minmum in the right subtree
            if (node->right)
            {
                auto n = node->right;
                while(n->left)
                {
                    n = n->left;
                }
                return n;
            }
            else
            {
                // the successor is the parent node if the input node is the left child of its parent
                auto n = node;
                auto p = node->parent;
                while (p && p->right == n)
                {
                    n = p;
                    p = n->parent;
                }
                return p;
            }
        }
    }
}