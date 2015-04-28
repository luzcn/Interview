// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CareerCup\ConstructTreefromInorderandPreorder.h"


using namespace std;


void inorderT(TreeNode* root)
{
    if (!root)
        return;

    inorderT(root->left);
    cout << root->val;
    inorderT(root->right);
}
int _tmain(int argc, _TCHAR* argv [])
{
    // inorder: 4,2,5,1,6,3,9,7  preorder: 1,2,4,5,3,6,7,9

    vector<int> inorder = { 4, 2, 5, 1, 6, 3, 9, 7 };
    vector<int> preorder = { 1, 2, 4, 5, 3, 6, 7, 9 };

    auto t = ConstructTreeFromInorderAndPostorder::constructTree(inorder, preorder);

    inorderT(t);
    return 0;
}

