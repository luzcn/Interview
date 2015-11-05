#pragma once

#include "stdafx.h"
#include <stack>

namespace leetcode
{
	/*
	Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

	Calling next() will return the next smallest number in the BST.

	Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
	*/
	class BSTIterator
	{
	public:
		BSTIterator(TreeNode *root)
		{
			auto current = root;
			while (current)
			{
				s.push(current);
				current = current->left;
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext()
		{
			return !s.empty();
		}

		/** @return the next smallest number */
		int next()
		{
			auto current = s.top();
			s.pop();
			int res = current->val;
			current = current->right;
			while (current)
			{
				s.push(current);
				current = current->left;
			}

			return res;

		}

	private:
		std::stack<TreeNode*> s;
	};
}