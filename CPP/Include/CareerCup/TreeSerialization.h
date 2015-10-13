#pragma once
#include "stdafx.h"

// binary tree serialization and deserialization
namespace careercup
{
    void preorder(vector<string>& res, TreeNode* node)
    {
        if (!node)
        {
            res.push_back("#");
            return;
        }

        res.push_back(to_string(node->val));
        preorder(res, node->left);
        preorder(res, node->right);
    }

    vector<string> serialize(TreeNode *root)
    {
        vector<string> res;
        preorder(res, root);

        return res;
    }

    TreeNode* deserialize(vector<string>& arr, int& index)
    {
        if (index >= arr.size())
            return nullptr;

        if (arr[index] == "#")
        {
            index++;
            return nullptr;
        }

        auto node = new TreeNode(std::stoi(arr[index]));
        index++;
        node->left = deserialize(arr, index);
        node->right = deserialize(arr, index);
        return node;
    }
}