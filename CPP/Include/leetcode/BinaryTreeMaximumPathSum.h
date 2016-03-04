#pragma  once

#include "stdafx.h"

namespace BinaryTreeMaximumPathSum
{
    struct Data
    {
        Data(int maxvalue, int sum, bool valid)
            :maxValue(maxvalue),nodeSum(sum), isValid(valid)
         {}

        int maxValue;
        int nodeSum;
        bool isValid;
    };

    Data* dfs(TreeNode* node)
    {
        if (!node)
            return nullptr;

        if (!node->left && !node->right)
        {
            return new Data(node->val, 1, true);
        }

        Data* leftSub = dfs(node->left);
        Data* rightSub = dfs(node->right);

        if (leftSub && rightSub)
        {
            if (leftSub->isValid && rightSub->isValid)
            {
                if (node->val > leftSub->maxValue && node->val < rightSub->maxValue)
                {
                    return new Data(rightSub->maxValue, leftSub->nodeSum + rightSub->nodeSum + 1, true);
                }
                else
                {
                    return new Data(INT_MAX, max(leftSub->nodeSum, rightSub->nodeSum), false);
                }
            }
        }
        else if (leftSub)
        {
            if (leftSub->isValid && node->val > leftSub->maxValue)
            {
                return new Data(node->val, leftSub->nodeSum + 1, true);
            }
            else
            {
                return new Data(INT_MAX, leftSub->nodeSum, false);
            }
        }
        else
        {
            if (rightSub->isValid && node->val > rightSub->maxValue)
            {
                return new Data(node->val, rightSub->nodeSum + 1, true);
            }
            else
            {
                return new Data(INT_MAX, rightSub->nodeSum, false);
            }
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