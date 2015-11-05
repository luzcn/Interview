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

    // insert a new node, returns the BST root node
    TreeNode* insert(TreeNode* root, int v)
    {
        if (!root)
            return new TreeNode(v);

        if (root->val > v)
            root->left = insert(root->left, v);
        else
            root->right = insert(root->right, v);

        return root;
    }


    void transplant(TreeNode* parent, TreeNode* node, TreeNode* newNode)
    {
        if (parent->left == node)
            parent->left = newNode;
        else
            parent->right =newNode;

        node->left = nullptr;
        node->right = nullptr;
    }

    TreeNode* deleteNodeRec(TreeNode* parent, TreeNode* node, int v)
    {
        if (!node)
            return nullptr;

        if (node->val == v)
        {
            if (!node->left)
            {
                if (!parent)
                    return node->right;

                transplant(parent, node, node->right);
            }
            else if (!node->right)
            {
                if (!parent)
                    return node->left;

                transplant(parent, node, node->left);
            }
            else
            {
                // find the successor of node
                auto successor = node->right;
                TreeNode* prev = nullptr;
                while (successor->left)
                {
                    prev = successor;
                    successor = successor->left;
                }

                // if the successor is the right child of target node
                // 1. set the left child of target node as the left of successor
                // 2. transplant the parent and 
                if (node->right == successor)
                {
                    successor->left = node->left;
                    if (!parent)
                        return successor;

                    transplant(parent, node, successor);
                }
                else
                {
                    prev->left = successor->right;
                    successor->left = node->left;
                    successor->right = node->right;

                    if (!parent)
                        return successor;

                    transplant(parent, node, successor);
                }
            }
        }
        deleteNodeRec(node, node->left, v);
        deleteNodeRec(node, node->right, v);

        return node;
    }

    // delete a tree node which has value v, return the tree root node.
    // 1. if the target node v has no children, simply delete this node.
    // 2. if v has only one child y, replace the v node with y by v's parent to point y as child
    // 3. if v has two children, find the successor y (which must be in the righ subtree of v)
    //   - if y is v's right child, 
    TreeNode* deleteNode(TreeNode* root, int target)
    {
        // inorder traverse
        if (!root)
            return root;

        //if (root->val == target)
        //{
        //    if (!root->left)
        //    {
        //        return root->right;
        //    }
        //    else if (!root->right)
        //    {
        //        return root->right;
        //    }
        //    else
        //    {
        //        // find the successor of node
        //        auto successor = root->right;
        //        TreeNode* prev = nullptr;
        //        while (successor->left)
        //        {
        //            prev = successor;
        //            successor = successor->left;
        //        }
        //        // if the successor is the right child of target node
        //        // 1. set the left child of target node as the left of successor
        //        if (root->right == successor)
        //        {
        //            successor->left = root->left;
        //        }
        //        else
        //        {
        //            prev->left = successor->right;
        //            successor->left = root->left;
        //            successor->right = root->right;
        //        }
        //        return successor;
        //    }
        //}

        return deleteNodeRec(nullptr, root, target);
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
                while (n->left)
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