﻿#pragma once

#include "stdafx.h"

/**
 *	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's.

 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3

 http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html

 */
namespace UniqueBinarySearchTrees
{
    //if n == 0, only one bst tree, empty tree
    //if n == 1, only one node tree.
    // 
    //if n == 2, number of trees with "1" as root + number of trees with "2" as root.
    //s => numTree(0)*numTree(1) + numTree(1)*numTree(0).
    // 
    //当数组为 1,2,3,4...n时，基于以下原则的BST建树具有唯一性:
    //以i为根节点的树: 1.其左子树由[0, i-1]构成 2.其右子树由[i+1, n]构成。

    //recursive solution.
    int numTrees(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        int num = 0;
        for (int i = 1; i <= n; ++i)
        {
            num += numTrees(i - 1)* numTrees(n - i);
        }
        return num;
    }

    /**
     *	The DP solution.
     *	count[0] = 1;
     *	count[1] = 1;
     *
     *	count[2] = count[0]*count[1] + count[1]*count[0];
     *
     *	count[3] = count[0]*count[2] + count[1]*count[1] + count[2]*count[0];
     *	...
     *
     *	count[i] = sum(count[0...k] * count[k+1...i]), 0 = k <= i-1
     */
    int numTrees_DP(int n)
    {
        vector<int> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                count[i] += count[j - 1] * count[i - j];
            }
        }
        return count[n];
    }

    vector<TreeNode*> generateRec(int min, int max)
    {
        vector<TreeNode*> res;
        if (min > max)
        {
            res.push_back(nullptr);
            return res;
        }

        vector<TreeNode*> leftSub;
        vector<TreeNode*> rightSub;
        for (int i = min; i <= max; i++)
        {
            leftSub = std::move(generateRec(min, i - 1));
            rightSub = std::move(generateRec(i + 1, max));

            for (auto leftNode : leftSub)
            {
                for (auto rightNode : rightSub)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // generate all the binary search tree
    vector<TreeNode*> generateTree(int n)
    {
        if (n == 0)
            return{};

        return generateRec(1, n);
    }
}
