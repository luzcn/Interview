#pragma once
#include "stdafx.h"

//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, 
//and all nodes in the last level are as far left as possible.
//It can have between 1 and 2h nodes inclusive at the last level h.

namespace leetcode
{
    namespace helper
    {
        void countRec(TreeNode* node, int& sum)
        {
            if (!node)
                return;

            sum++;
            countRec(node->left, sum);
            countRec(node->right, sum);
        }

        int getDepth(TreeNode* node)
        {
            if (!node)
                return 0;

            return std::max(getDepth(node->left), getDepth(node->right)) + 1;
        }
    }


    int countNodes(TreeNode* root)
    {
        int sum = 0;

        auto t = root;
        int height = 0;
        while (t)
        {
            height++;
            t = t->left;
        }

        sum = pow(2, height) - 1;
        return sum;
    }
}