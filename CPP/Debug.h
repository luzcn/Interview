#pragma once
#include "stdafx.h"
#include <sstream>

namespace debug
{
    namespace helper
    {
        vector<string> split(string& str, char delim)
        {
            std::stringstream ss(str);
            vector<string> result;
            string element;

            while (std::getline(ss, element, delim))
            {
                result.push_back(element);
            }

            return result;
        }

        // 
        TreeNode* deserializeRec(const vector<string>& data, int& i)
        {
            if (i >= data.size())
            {
                return nullptr;
            }

            if (data[i] == "#")
            {
                i++;
                return nullptr;
            }

            TreeNode* node = new TreeNode(stoi(data[i]));

            i++;
            node->left = deserializeRec(data, i);
            node->right = deserializeRec(data, i);

            return node;
        }
    }

    // Construct Binary tree from pre-order string
    TreeNode* deserialize(string preorder)
    {
        vector<string> data = std::move(helper::split(preorder, ','));

        int i = 0;
        return helper::deserializeRec(data, i);
    }

    // pre-order print a binary tree
    void preorder(TreeNode* root)
    {
        if (!root)
            return;

        cout << root->val << endl;
        debug::preorder(root->left);
        debug::preorder(root->right);
    }
}