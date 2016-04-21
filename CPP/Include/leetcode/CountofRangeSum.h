#pragma once
#include "stdafx.h"

//Given an integer array nums, return the number of range sums that lie in[lower, upper] inclusive.
//Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j(i ≤ j), inclusive.
//
//Note:
//A naive algorithm of O(n2) is trivial.You MUST do better than that.
//
//Example :
//    Given nums = [-2, 5, -1], lower = -2, upper = 2,
//    Return 3.
//    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are : -2, -1, 2.

namespace leetcode
{
    struct SegmentNode
    {
        SegmentNode(int s, int e, int value)
            :start(s), end(e), sum(value), left(nullptr), right(nullptr)
        {}

        int sum;

        // segment tree node range
        int start;
        int end;

        SegmentNode* left;
        SegmentNode* right;
    };

    class Solution
    {
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper)
        {
            if (nums.empty() || upper < lower)
                return 0;

            SegmentNode* root = construct(nums, 0, nums.size() - 1);

            int count = 0;

            dfs(root, count, lower, upper);

            return count;
        }
    private:
        // preorder search the segment tree
        void dfs(SegmentNode* node, int& count, int lower, int upper)
        {
            if (!node)
                return;

            if (node->sum <= upper && node->sum >= lower)
            {
                count++;
            }

            dfs(node->left, count, lower, upper);
            dfs(node->right, count, lower, upper);
        }

        // construct the segment tree
        SegmentNode* construct(vector<int>& nums, int l, int r)
        {
            if (l > r)
                return nullptr;

            if (l == r)
                return new SegmentNode(l, r, nums[l]);

            int m = l + (r - l) / 2;
            auto leftSub = construct(nums, l, m);
            auto rightSub = construct(nums, m + 1, r);

            SegmentNode* node = new SegmentNode(l, r, leftSub->sum + rightSub->sum);
            node->left = leftSub;
            node->right = rightSub;

            return node;
        }


    };
}