#pragma once
#include "stdafx.h"

// Given a non-empty binary search tree and a target value, 
// find the value in the BST that is closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.
namespace leetcode
{
    void closestValueRec(TreeNode* node, double t, int& res)
    {
        if (!node)
            return;

        double value = (double) node->val;
        res = node->val;

        if (value == t)
        {
            return;
        }
        else if (t < value)
        {
            closestValueRec(node->left, t, res);
        }
        else
        {
            closestValueRec(node->right, t, res);
        }

        if (abs(res - t) > abs(node->val - t))
        {
            res = node->val;
        }
    }

    int closestValue(TreeNode* root, double target)
    {
        int res = INT_MAX;
        if (!root)
            return res;
        
        closestValueRec(root, target, res);

        return res;
    }


    //Given a non - empty binary search tree and a target value, find k values in the BST that are closest to the target.
    //    Note:
    //Given target value is a floating point.
    //    You may assume k is always valid, that is : k <= total nodes.
    //    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
    //    Follow up :
    //Assume that the BST is balanced, could you solve it in less than O(n) runtime(where n = total nodes)?

    void findKCloseseValueRec(TreeNode* node, double target, int k, int& closest, vector<int>& result)
    {
        
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) 
    {

    }
}