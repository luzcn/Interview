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
            preorder(root, data);

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
        void preorder(TreeNode* node, string& data)
        {
            if (!node)
            {
                data.append("#");
                dataList.push_back("#");
                return;
            }

            data.append(to_string(node->val));
            dataList.push_back(to_string(node->val));

            preorder(node->left, data);
            preorder(node->right, data);
        }

      
        /*vector<string> split(string& s, char delim)
        {
            stringstream ss(s);
            vector<string> element;
            string item;

            while (getline(ss, item, delim))
            {
                element.push_back(item);
            }
        }*/

        int index;
        vector<string> dataList;
    };
}