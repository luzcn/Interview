// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\KthSmallestElementInBST.h"

using namespace std;

void inorder(TreeNode* node)
{
    if (!node)
        return;

    inorder(node->left);
    cout << node->val << endl;
    inorder(node->right);

}

int _tmain(int argc, _TCHAR* argv[])
{
    vector<TreeNode> n{
        TreeNode(20),
        TreeNode(8),
        TreeNode(4),
        TreeNode(12),
        TreeNode(10),
        TreeNode(14),
        TreeNode(22)
    };

    n[0].left = &n[1];
    n[0].right = &n[6];

    n[1].left = &n[2];
    n[1].right = &n[3];

    n[3].left = &n[4];
    n[3].left = &n[5];


    cout << leetcode::kthSmallest2(&n[0], 3);
    return 0;
}