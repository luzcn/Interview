#pragma once
#include "stdafx.h"
#include <queue>

namespace leetcode
{
    using namespace std;
    /***
     *	Use queue to simulate the level.
     */
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

    /***
     *	inorder DFS solution.
     */
    void TreeLevelOrderDFS(TreeNode* node, vector<vector<int>>& solution, int level)
    {
        if (!node)
            return;

        if (level == solution.size())
        {
            solution.push_back(vector<int>());
        }

        solution[level].push_back(node->val);

        TreeLevelOrderDFS(node->left, solution, level + 1);
        TreeLevelOrderDFS(node->right, solution, level + 1);
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