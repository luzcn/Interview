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
        vector<vector<int>> sol;
        if (!root)
            return sol;

        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        vector<int> level;
        que1.push(root);

        while (!que1.empty())
        {
            auto current = que1.front();
            que1.pop();
            level.push_back(current->val);

            if (current->left)
            {
                que2.push(current->left);
            }
            if (current->right)
            {
                que2.push(current->right);
            }

            if (que1.empty())
            {
                sol.push_back(level);
                level.clear();
                que1 = que2;
                que2 = queue<TreeNode*>();
            }
        }

        return sol;
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