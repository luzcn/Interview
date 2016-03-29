#pragma once

#include "stdafx.h"
#include <stack>

namespace leetcode
{
    // Implement an iterator over a binary search tree (BST). 
    // Your iterator will be initialized with the root node of a BST.
    // Calling next() will return the next smallest number in the BST.
    //
    // Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
    class BSTIterator
    {
    public:
        BSTIterator(TreeNode *root)
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
        }

        /** @return whether we have a next smallest number */
        bool hasNext()
        {
            return !st.empty();
        }

        /** @return the next smallest number */
        int next()
        {
            TreeNode* current = st.top();
            int result = current->val;
            st.pop();
            
            current = current->right;
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            return result;

        }

    private:
        std::stack<TreeNode*> st;
    };
}