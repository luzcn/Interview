#pragma  once
#include "stdafx.h"

/***
 *	Given a binary tree and a sum, determine if the tree has a root-to-leaf path
    such that adding up all the values along the path equals the given sum.
           
    For example :
    Given the below binary tree and sum = 22,
          5
         /  \
        4    8
        /    / \
        11  13  4
        / \      \
        7  2      1
    return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.
         
    Solution:
    Sum up all the node value in each path and compare with the target at leaf nodes.
 */
namespace PathSum
{
    namespace details
    {
        // Be careful, here cannot use "int& sum"
        bool hasPathSumRootToLeafRec(TreeNode* node, int sum, int target)
        {
            if (!node)
                return false;

            if (!node->left && !node->right)
            {
                if (sum + node->val == target)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }


            sum += node->val;
            return hasPathSumRootToLeafRec(node->left, sum, target) || hasPathSumRootToLeafRec(node->right, sum, target);
        }

        /***
        * Given a binary tree and a sum, determine if the tree has a root-to-anynode
        * path such that adding up all the values along the path equals the given
        * sum.
        *
        */
        bool hasPathSumRootToAny(TreeNode* node, int sum, int target)
        {
            if (!node)
                return false;

            sum += node->val;
            if (sum == target)
                return true;

            return hasPathSumRootToAny(node->left, sum, target) || hasPathSumRootToAny(node->right, sum, target);
        }
    }

    bool hasPathSum(TreeNode *root, int target)
    {
        return details::hasPathSumRootToLeafRec(root, 0, target);
    }
}