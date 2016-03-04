#pragma once
#include "stdafx.h"

// Given a binary tree, find the largest subtree which is a Binary Search Tree(BST), 
// where largest means subtree with largest number of nodes in it.
// A subtree must include all of its descendants.
// Here's an example:
//
//      10
//      / \
//     5  15
//    / \   \
//   1   8   7
//
//The Largest BST Subtree in this case is the highlighted one.
//The return value is the subtree's size, which is 3. 

namespace leetcode
{
    struct Data
    {
        Data(int maxvalue, int minvalue, int sum, bool valid)
            :maxValue(maxvalue), minValue(minvalue), nodeSum(sum), isValid(valid)
        {}

        int maxValue;
        int minValue;
        int nodeSum;
        bool isValid;
    };

    Data* dfs(TreeNode* node)
    {
        if (!node)
            return nullptr;

        // a leaf node is a valid bst
        if (!node->left && !node->right)
            return new Data(node->val, node->val, 1, true);

        Data* leftSub = dfs(node->left);
        Data* rightSub = dfs(node->right);

        if (leftSub && rightSub)
        {
            if (leftSub->isValid
                && rightSub->isValid
                && node->val > leftSub->maxValue
                && node->val < rightSub->minValue)
            {
                return new Data(rightSub->maxValue, leftSub->minValue, leftSub->nodeSum + rightSub->nodeSum + 1, true);
            }

            return new Data(0, 0, max(leftSub->nodeSum, rightSub->nodeSum), false);
        }
        else if (leftSub)
        {
            if (leftSub->isValid && node->val > leftSub->maxValue)
            {
                return new Data(node->val, leftSub->minValue, leftSub->nodeSum + 1, true);
            }
            return new Data(0, 0, leftSub->nodeSum, false);
        }
        else
        {
            if (rightSub->isValid && node->val < rightSub->minValue)
            {
                return new Data(rightSub->maxValue, node->val, rightSub->nodeSum + 1, true);
            }
            return new Data(0, 0, rightSub->nodeSum, false);
        }

        return nullptr;
    }

    int largestBSTSubtree(TreeNode* root)
    {
        if (!root)
            return 0;

        auto t = dfs(root);

        return t->nodeSum;
    }
}