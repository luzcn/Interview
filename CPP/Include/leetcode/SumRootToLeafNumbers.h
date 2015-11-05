#pragma once

#include "stdafx.h"

/***
 *	Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

    An example is the root-to-leaf path 1->2->3 which represents the number 123.

    Find the total sum of all root-to-leaf numbers.

    For example,

        1
       / \
      2   3

    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.

    Return the sum = 12 + 13 = 25. 
 */
namespace SumRoofToLeafNumbers
{
    using namespace std;

    void findAllPathNumber(TreeNode* node, vector<int>& allNumbers, int currentNum)
    {
        if (!node)
            return;

        currentNum = currentNum * 10 + node->val;
        findAllPathNumber(node->left, allNumbers, currentNum);
        if (!node->left && !node->right)
        {
            allNumbers.push_back(currentNum);
        }
        findAllPathNumber(node->right, allNumbers, currentNum);
    }

    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return root->val;

        vector<int> numbers;
        findAllPathNumber(root, numbers, 0);

        int sum = 0;
        for (auto num : numbers)
        { 
            sum += num;
        }

        return sum;
    }
}