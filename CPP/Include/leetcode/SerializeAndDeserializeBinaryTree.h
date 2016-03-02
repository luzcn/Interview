#pragma once
#include "stdafx.h"
#include <sstream>

namespace leetcode
{
    class Codec
    {
    public:
        Codec()
            :index(0)
        {}

        // Encodes a tree to a single string.
        string serialize(TreeNode* root)
        {
            string data = "";
            preorder(root);

            for (auto& str : dataList)
            {
                data.append(str);
            }

            return data;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(vector<string>& data) 
        {
            if (index >= data.size())
                return nullptr;

            if (data[index] == "#")
            {
                index++;
                return nullptr;
            }

            TreeNode* node = new TreeNode(stoi(data[index]));
            index++;

            node->left = deserialize(data);
            node->right = deserialize(data);

            return node;
        }
    private:
        void preorder(TreeNode* node)
        {
            if (!node)
            {
                dataList.push_back("#");
                return;
            }

            dataList.push_back(to_string(node->val));

            preorder(node->left);
            preorder(node->right);
        }

      
        int index;
        vector<string> dataList;
    };
}