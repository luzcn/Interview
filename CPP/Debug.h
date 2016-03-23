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
    }

    TreeNode* buildTree(string s)
    {
        vector<string> nodeList = helper::split(s, ',');

        if (nodeList.empty())
            return nullptr;

        std::queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoi(nodeList[0]));

        que.push(root);
        int i = 1;
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();

            if (i < nodeList.size())
            {
                if (nodeList[i] != "#")
                {
                    TreeNode* leftNode = new TreeNode(stoi(nodeList[i]));
                    node->left = leftNode;
                    que.push(leftNode);
                }
                
                i++;
            }

            if (i < nodeList.size())
            {
                if (nodeList[i] != "#")
                {
                    TreeNode* rightNode = new TreeNode(stoi(nodeList[i]));
                    node->right = rightNode;
                    que.push(rightNode);
                }
                i++;
            }
        }

        return root;
    }
}