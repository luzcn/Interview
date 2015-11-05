#pragma once
#include "stdafx.h"

//Find a pair with given sum in a Balanced BST
//
//Given a Balanced Binary Search Tree and a target sum, 
//write a function that returns true if there is a pair with sum equals to target sum, otherwise return false.
//
//Expected time complexity is O(n) and only O(Logn) extra space can be used.
//Any modification to Binary Search Tree is not allowed.Note that height of a Balanced BST is always O(Logn).
// http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
namespace careercup
{
    bool towSumInBST(TreeNode* root, int target)
    {
        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        auto current1 = root;
        auto current2 = root;
        bool done1 = false;
        bool done2 = false;
        int value1 = 0;
        int value2 = 0;

        while (true)
        {
            // normal inorder traverse
            while (!done1)
            {
                if (current1)
                {
                    stack1.push(current1);
                    current1 = current1->left;
                }
                else if (!stack1.empty())
                {
                    current1 = stack1.top();
                    stack1.pop();
                    value1 = current1->val;

                    current1 = current1->right;
                    done1 = true;
                }
                else
                    done1 = true;
            }

            // reverse inorder traverse
            while (!done2)
            {
                if (current2)
                {
                    stack2.push(current2);
                    current2 = current2->right;
                }
                else if (!stack2.empty())
                {
                    current2 = stack2.top();
                    stack2.pop();

                    value2 = current2->val;
                    current2 = current2->left;

                    done2 = true;
                }
                else
                    done2 = true;
            }

            if (value1 != value2 && (value1 + value2) == target)
                return true;

            if (value1 != value2 && (value1 + value2) < target)
                done1 = false;

            if (value1 != value2 && (value1 + value2) < target)
                done2 = false;

            if (done1 && done2)
                break;
        }

        return false;
    }
}

#if 0
int main()
{
    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(12);
    root->right->left = new TreeNode(16);
    root->right->right = new TreeNode(25);

    cout << towSumInBST(root, 11);
    return 0;
}
#endif