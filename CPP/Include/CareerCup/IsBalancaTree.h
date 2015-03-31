#pragma once

#include "stdafx.h"
#include "../DataStructure/BinarySearch.h"

int depth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return std::max(depth(root->left), depth(root->right)) + 1;
}

/// <summary>
///  For each node in a balanced binary tree,  
///  the distance of the depth of left subtree and the depth of righ subtree is no more than 1.
/// </summary>
/// <param name=""> </param>
/// <return> </return>
bool is_balanceTree(TreeNode* root)
{
    if (root == nullptr)
        return true;

    return (std::abs(depth(root->left) - depth(root->right)) <= 1) 
        && is_balanceTree(root->left) && is_balanceTree(root->right);
}

#if 0
int _tmain(int argc, _TCHAR* argv [])
{
    TreeNode* nodes[5] = { new TreeNode(1), new TreeNode(2), new TreeNode(3), new TreeNode(7), new TreeNode(12) };

    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[2]->left = nodes[3];
    //nodes[3]->left = nodes[4];

    std::cout << depth(nodes[0]) << std::endl;

    std::cout << is_balanceTree(nodes[0]) << std::endl;

    for (auto t : nodes)
    {
        delete t;
    }

    return 0;
}
#endif // 0
