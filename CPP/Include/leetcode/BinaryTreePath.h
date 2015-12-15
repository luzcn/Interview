#pragma once
#include "stdafx.h"

//Given a binary tree, return all root - to - leaf paths.
//
//For example, given the following binary tree :
//
//  1
// / \
//2     3
// \
//  5
//
//All root - to - leaf paths are :
//
//["1->2->5", "1->3"]
namespace leetcode
{
    void dfs(TreeNode* node, vector<string>& result, string& current)
    {
        if (!node)
        {
            return;
        }

        if (!node->left && !node->right)
        {
            current.append(to_string(node->val));
            result.push_back(current);
            current.resize(current.size() - to_string(node->val).size());
        }

        current.append(to_string(node->val)).append("->");
        dfs(node->left, result, current);
        dfs(node->right, result, current);
        current.resize(current.size() - to_string(node->val).size() - 2);

    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        string current = "";

        dfs(root, result, current);

        return result;
    }
}