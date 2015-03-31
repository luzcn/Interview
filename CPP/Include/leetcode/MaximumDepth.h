/************************************************************************/
/* Given a binary tree, find its maximum height.
 *
 * The maximum height of a binary tree is defined as the number of nodes along the path from the root node to the deepest leaf node.
 * Note that the maximum height of an empty tree is 0.
 /************************************************************************/
#pragma once
#include "DataStructure/BinaryTree.h"
#include <math.h>

namespace leetcode
{
    class Solution
    {
    public:
        int max_height(TreeNode* root)
        {
            if (!root)
                return 0;

            return std::max(max_height(root->left), max_height(root->right)) + 1;
        }
    };
}