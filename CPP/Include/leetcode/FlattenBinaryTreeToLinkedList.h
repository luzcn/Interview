#pragma  once

#include "stdafx.h"
#include <stack>

/***
 *	 Given a binary tree, flatten it to a linked list in-place.

    For example,
    Given

             1
            / \
           2   5
          / \   \
         3   4   6

    The flattened tree should look like:

       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6

 */
namespace FlatternBinaryTreeToLinkedList
{
    using namespace  std;

    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        // preorder non recursive
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* current = nullptr;
        TreeNode* pre = nullptr;

        while (!s.empty())
        {
            current = s.top();
            s.pop();

            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);

            if (pre)
            {
                pre->right = current;
                pre->left = nullptr;
            }

            pre = current;
            current = current->left;
        }
    }

}