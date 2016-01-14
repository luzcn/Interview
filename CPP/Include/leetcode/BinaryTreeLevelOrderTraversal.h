#pragma once
#include "stdafx.h"
#include <queue>

namespace leetcode
{
    // Use queue to simulate the level.
    vector<vector<int>> TreeLevelOrderTraversal(TreeNode* root)
    {
        if (!root)
            return{};

        vector<vector<int>> result;
        vector<int> levelList;

        std::queue<TreeNode*> que_nodes;
        std::queue<TreeNode*> que_temp;

        que_nodes.push(root);

        while (!que_nodes.empty())
        {
            TreeNode* current = que_nodes.front();
            que_nodes.pop();

            levelList.push_back(current->val);
            if (current->left)
            {
                que_temp.push(current->left);
            }

            if (current->right)
            {
                que_temp.push(current->right);
            }

            if (que_nodes.empty())
            {
                que_nodes.swap(que_temp);

                result.push_back(levelList);
                levelList.clear();
            }
        }

        return result;
    }

    // recursive solution        
    void TreeLevelOrderDFS(TreeNode* node, vector<vector<int>>& result, int level)
    {
        if (!node)
            return;

        if (level == result.size())
        {
            result.push_back(vector<int>());
        }

        result[level].push_back(node->val);

        // For zigzag order
        //if (level % 2 == 0)
        //{
        //    result[level].push_back(node->val);
        //}
        //else
        //{
        //    result[level].insert(result[level].begin(), node->val);
        //}

        TreeLevelOrderDFS(node->left, result, level + 1);
        TreeLevelOrderDFS(node->right, result, level + 1);
    }

    vector<vector<int>> TreeLevelOrderTraversalDFS(TreeNode* root)
    {
        vector<vector<int>> solution;
        if (!root)
            return solution;

        TreeLevelOrderDFS(root, solution, 0);

        return solution;
    }
}