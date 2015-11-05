#pragma once

#include "stdafx.h"

/***
 *	 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
    For example:
    Given the below binary tree and sum = 22,

                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1

    return

    [
       [5,4,11,2],
       [5,8,4,5]
    ]
 */
namespace PathSum2
{ 
    using namespace std;

    // The recursive helper function.
    void pathSumRec(TreeNode* node, vector<vector<int>>& sol, vector<int> current_path, int sum, int target)
    {
        if (!node)
            return;

        current_path.push_back(node->val);

        pathSumRec(node->left, sol, current_path, sum + node->val, target);
        pathSumRec(node->right, sol, current_path, sum + node->val, target);

        if (!node->left && !node->right)
        {
            if (sum + node->val == target)
            {
                sol.push_back(current_path);
            }
        }

        current_path.pop_back();
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> sol;

        if (!root)
        {
            return sol;
        }

        vector<int> current_path;
        pathSumRec(root, sol, current_path, 0, sum);

        return sol;
    }
}