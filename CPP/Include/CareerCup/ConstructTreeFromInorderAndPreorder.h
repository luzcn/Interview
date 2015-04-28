#include "stdafx.h"

namespace ConstructTreeFromInorderAndPostorder
{
    TreeNode* constructRec(vector<int>& inorder, vector<int>& preorder, int index, int l, int r)
    {
        if (index >= preorder.size())
            return nullptr;
        if (l > r)
            return nullptr;

        auto t = preorder[index];
        TreeNode* node = new TreeNode(preorder[index]);
        auto inindex = std::find(inorder.begin(), inorder.end(), t) - inorder.begin();
        index++;

        node->left = constructRec(inorder, preorder, index, l, inindex - 1);
        node->right = constructRec(inorder, preorder, index, inindex + 1, r);

        return node;

    }
    TreeNode* constructTree(vector<int>& inorder, vector<int>& preorder)
    {
        TreeNode* root;
        if (preorder.empty())
            return nullptr;

        root = constructRec(inorder, preorder, 0, 0, inorder.size() - 1);

        return root;
    }
}