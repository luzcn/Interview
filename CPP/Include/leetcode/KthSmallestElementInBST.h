#pragma once
#include "stdafx.h"
#include <stack>


//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 <= k <= BST's total elements.
//
//Follow up:
//What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
//How would you optimize the kthSmallest routine?
namespace leetcode
{
    // in order traverse solution, O(n) time, O(n) space
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root)
        {
            return 0;
        }

        std::stack<TreeNode*> stack;
        auto current = root;
        bool done = false;
        int count = 0;
        int res = 0;

        while (!done && count < k)
        {
            if (current)
            {
                stack.push(current);
                current = current->left;
            }
            else if (!stack.empty())
            {
                current = stack.top();
                stack.pop();
                count++;
                res = current->val;
                current = current->right;
            }
            else
                done = true;
        }
        return res;
    }

    // O(1) space solution, morris traversal
    int kthSmallest2(TreeNode* root, int k)
    {
        if (!root)
            return 0;

        int count = 0;
        auto current = root;
        TreeNode* pre = nullptr;

        while (current != nullptr)
        {
            if (current->left != nullptr)
            {
                //cout << current->val << endl;
                count++;
                if (count == k)
                    return current->val;
                current = current->right;
            }
            else
            {
                pre = current->left;
                while (pre->right && pre->right != current)
                    pre = pre->right;

                // set the left subtree right most node point the right point to the current root node.
                if (pre->right == nullptr)
                {
                    pre->right = current;
                    current = current->left;
                }

                // recover the right most node right pointer.
                else
                {
                    pre->right = nullptr;
                    //cout << current->val << endl;
                    count++;
                    if (count == k)
                        return current->val;
                    current = current->right;
                }
            }
        }

        return 0;
    }

}