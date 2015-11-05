#pragma once
#include "stdafx.h"

//Print Common Nodes in Two Binary Search Trees
//Given two Binary Search Trees, find common nodes in them.
//In other words, find intersection of two BSTs.
// 
// Thought:
// If the inputs are tow arrays, then we can do in O(m+n) time and O(n) space by using hashmap.
// But for BST, we have more useful information.
// we use inorder iterative traverse for both two BST trees.
// - if root1->val == root2->val, find one common node, save and both move the left node.
// - if root1->val < root2->val, move root1 to root1->right, 
//   since it is BST, we cannot find any common nodes in root1 left subtrees
// - otherwise move to left subtree.

// The best solution:
//1.) Convert BSTs tosorted DLLs.
//
//2.) Apply the algorithm to get intersection of two sorted arrays 
//      on these two sorted DLLs to get common of these two DLLs.
//
//3.) Convert DLLs to balanced BST.
//
//This method does not need any extra space(If we do not consider implicit recursion stack space).

