#pragma once
#include "stdafx.h"
#include <stack>

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

*/
namespace leetcode
{
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
}