#pragma once

#include "stdafx.h"
#include <unordered_map>

/**
*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

http://leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html
*/
namespace leetcode
{

#pragma region  Inorder and Postorder 
	int post_index;
	TreeNode *buildTree_POST(vector<int> &inorder, vector<int> &postorder)
	{
		std::unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++)
		{
			map.emplace(inorder[i], i);
		}

		post_index = postorder.size() - 1;

		return buildTreePOSTRec(map, inorder, postorder, 0, postorder.size() - 1);
	}

	TreeNode* buildTreePOSTRec(std::unordered_map<int, int>& map, vector<int> &inorder, vector<int> &postorder, int in_start, int in_end)
	{
		if (in_start > in_end)
			return NULL;

		int val = postorder[post_index--];
		int pos = map[val];

		TreeNode* node = new TreeNode(val);

		node->right = buildTreePOSTRec(map, inorder, postorder, pos + 1, in_end);
		node->left = buildTreePOSTRec(map, inorder, postorder, in_start, pos - 1);

		return node;
	}
#pragma endregion

#pragma region Inorder and Preorder
	int pre_index = 0;

	TreeNode* buildTreeRec(std::unordered_map<int, int>& map, vector<int> &preorder, vector<int> &inorder,
		int in_start, int int_end)
	{
		if (in_start > int_end)
			return nullptr;

		int val = preorder[pre_index++];
		int pos = map[val];

		TreeNode* node = new TreeNode(val);

		node->left = buildTreeRec(map, preorder, inorder, in_start, pos - 1);
		node->right = buildTreeRec(map, preorder, inorder, pos + 1, int_end);

		return node;
	}

	// The first element of the pre-order array is the root of the tree.
	// Find the inorder index position of this root, 
	// all the elements on the left side of this index are the left child of this root element.
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		std::unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++)
		{
			map.emplace(inorder[i], i);
		}

		return buildTreeRec(map, preorder, inorder, 0, inorder.size() - 1);
	}
#pragma endregion

}
