#include "stdafx.h"

/**
 * Construct binary tree from the inorder array and postorder array.
 **/
namespace ConstructTreeFromInorderAndPostorder
{
    TreeNode* constructRec(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        // The last element in the postorder is the root of the tree(subtree)
        int val = postorder[postEnd];
        TreeNode* root = new TreeNode(val);
        int index = std::find(inorder.begin(), inorder.end(), val) - inorder.begin();

        // elements ahead of the root position in the inorder are all left subtrees and after this position are right subtrees.
        // so we can construct recursively.
        root->left = constructRec(inorder, postorder, inStart, index - 1, postStart, postStart + (index - 1 - inStart));
        root->right = constructRec(inorder, postorder, index + 1, inEnd, postEnd - (inEnd - index), postEnd - 1);
        return root;
    }

    TreeNode* construct(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.empty())
            return nullptr;

        int n = postorder.size();
        TreeNode* root = constructRec(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

        return root;
    }
}
