#pragma once
#include "stdafx.h"
#include <queue>

namespace leetcode
{
    //  Given a binary tree, find its maximum height.
    // 
    //  The maximum height of a binary tree is defined as the number of nodes along the path from the root node to the deepest leaf node.
    //  Note that the maximum height of an empty tree is 0.
    int max_height(TreeNode* root)
    {
        if (!root)
            return 0;

        return std::max(max_height(root->left), max_height(root->right)) + 1;
    }

    //  Given a binary tree, find its minimum depth.
    //  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
    int min_depth(TreeNode* node)
    {
        // BFS solution
        if (!node)
            return 0;

        std::queue<TreeNode*> que;
        std::queue<TreeNode*> que2;
        que.push(node);

        int count = 0;
        while (!que.empty())
        {
            auto current = que.front();
            que.pop();

            if (!current->left && !current->right)
                return count;

            if (current->left)
                que2.push(current->left);
            if (current->right)
                que2.push(current->right);

            if (que.empty())
            {
                count++;
                que = que2;
                que2 = std::queue<TreeNode*>();
            }
        }
    }

    int min_depthRec(TreeNode* node)
    {
        if (!node)
            return 0;

        if (node->left && !node->right)
            return min_depthRec(node->left) + 1;

        if (node->right && !node->left)
            return min_depthRec(node->right) + 1;

        return std::min(min_depthRec(node->left), min_depthRec(node->right)) + 1;
    }
}