#pragma once
#include "stdafx.h"
#include <queue>
namespace careercup
{
    // find kth smallest divide-conquer solution, similar to quick sort.
    int kthSmallestDivideConquer(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];

        int m = l - 1;
        int pivot = nums[r];
        for (int i = l; i < r; i++)
        {
            if (nums[i] < pivot)  // use (nums[i] > pivot) to find kth largest
            {
                m++;
                if (m != i)
                {
                    int temp = nums[i];
                    nums[i] = nums[m];
                    nums[m] = temp;
                }
            }
        }
        m++;
        int temp = nums[r];
        nums[r] = nums[m];
        nums[m] = temp;

        if (m + 1 == k)
            return nums[m];
        else if (m + 1 > k)
            return kthSmallestDivideConquer(nums, l, m - 1, k);
        else
            return kthSmallestDivideConquer(nums, m + 1, r, k);
    }

    // Find kth smallest/largest in BST
    int findKthSmallestBST(TreeNode* root, int k)
    {
        // inorder iterative
        if (!root)
            return 0;

        stack<TreeNode*> m_stack;
        auto current = root;
        int count = 0;
        while (true)
        {
            if (current)
            {
                m_stack.push(current);
                current = current->left;
            }
            else if (!m_stack.empty())
            {
                current = m_stack.top();
                m_stack.pop();

                count++;
                if (count == k)
                {
                    return current->val;
                }
                current = current->right;
            }
            else
                break;
        }

        return 0;
    }
}