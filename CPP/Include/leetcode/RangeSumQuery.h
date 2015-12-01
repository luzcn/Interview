#pragma once
#include "stdafx.h"

namespace leetcode
{
    // Your NumArray object will be instantiated and called as such:
    // NumArray numArray(nums);
    // numArray.sumRange(0, 1);
    // numArray.sumRange(1, 2);
    class NumArray
    {
    public:
        NumArray(vector<int> &nums)
        {
            totalSums.resize(nums.size() + 1);
            totalSums[0] = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                totalSums[i + 1] = totalSums[i] + nums[i];
            }
        }

        int sumRange(int i, int j)
        {
            return totalSums[j + 1] - totalSums[i];
        }
    private:
        vector<int> totalSums;
    };


    // using segment tree

    // the array value may update multiple times
    class NumArrayMutable
    {
    public:
        NumArrayMutable(vector<int>& nums)
        {
            // construct the segment tree
            this->root = constructSegmentTree(nums, 0, nums.size() - 1);
        }

        void update(int i, int val)
        {
            updateRec(root, i, val);
        }

        int sumRange(int i, int j)
        {
            return queryRec(root, i, j);
        }
    private:
        class SegmentTreeNode
        {
        public:
            int start;
            int end;
            int value;
            SegmentTreeNode *left, *right;

            SegmentTreeNode(int s, int e, int val)
                :start(s), end(e), value(val), left(nullptr), right(nullptr)
            {}
        };

        SegmentTreeNode* root;

        SegmentTreeNode* constructSegmentTree(vector<int> &nums, int l, int r)
        {
            if (l > r)
                return nullptr;

            if (l == r)
                return new SegmentTreeNode(l, r, nums[l]);

            int m = l + (r - l) / 2;
            auto leftSub = constructSegmentTree(nums, l, m);
            auto rightSub = constructSegmentTree(nums, m + 1, r);

            SegmentTreeNode* node = new SegmentTreeNode(l, r, leftSub->value + rightSub->value);
            node->left = leftSub;
            node->right = rightSub;

            return node;
        }

        int queryRec(SegmentTreeNode* node, int i, int j)
        {
            if (!node || i > node->end || j < node->start)
                return 0;

            if (node->start >= i && node->end <= j)
                return node->value;

            return queryRec(node->left, i, j) + queryRec(node->right, i, j);
        }

        void updateRec(SegmentTreeNode* node, int i, int val)
        {
            if (!node || i < node->start || i > node->end)
                return;

            if (i == node->start && i == node->end)
            {
                node->value = val;
                return;
            }

            updateRec(node->left, i, val);
            updateRec(node->right, i, val);

            node->value = node->left->value + node->right->value;
        }
    };

    // Range Sum Query 2D - Immutable
    // Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined 
    // by its upper left corner(row1, col1) and lower right corner(row2, col2).
    //
    //Given matrix = [
    //        [3, 0, 1, 4, 2],
    //        [5, 6, 3, 2, 1],
    //        [1, 2, 0, 1, 5],
    //        [4, 1, 0, 1, 7],
    //        [1, 0, 3, 0, 5]
    //]
    //    sumRegion(2, 1, 4, 3) -> 8
    //    sumRegion(1, 1, 2, 2) -> 11
    //    sumRegion(1, 2, 2, 4) -> 12
    class NumMatrix
    {
    public:
        NumMatrix(vector<vector<int>> &matrix)
        {
            if (!matrix.empty())
            {
                int m = matrix.size();
                int n = matrix[0].size();

                totalSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));


                // compute the total sum of each row
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        totalSum[i][j] = matrix[i - 1][j - 1] + totalSum[i][j - 1];
                    }
                }

                // add up all the row sum for each column, 
                // the result is the range sum of each rectangle
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        totalSum[i][j] += totalSum[i - 1][j];
                    }
                }
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            if (totalSum.empty())
                return 0;

            return totalSum[row2 + 1][col2 + 1]
                - totalSum[row1][col2 + 1] // the up rectangle range sum
                - totalSum[row2 + 1][col1] // the left rectangle range sum
                + totalSum[row1][col1];    // the up left conner range sum, it removed twice
        }
    private:
        vector<vector<int>> totalSum;
    };


    // need to update multiple times
    class NumMatrixMutable
    {
    public:
        NumMatrixMutable(vector<vector<int>> &matrix)
        {
            if (!matrix.empty())
            {
                root = constructSegementTree(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
            }
        }

        void update(int row, int col, int val)
        {
            modify(root, row, col, val);
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            return query(root, row1, col1, row2, col2);
        }
    private:
        // 2D segment tree (quad
        class SegmentTreeNode
        {
        public:
            int start_row;
            int start_col;

            int end_row;
            int end_col;

            int value;

            vector<SegmentTreeNode*> children{ nullptr, nullptr, nullptr, nullptr };

            SegmentTreeNode(int r1, int c1, int r2, int c2, int val)
                :start_row(r1), start_col(c1), end_row(r2), end_col(c2), value(val)
            {
            }
        };

        SegmentTreeNode* constructSegementTree(vector<vector<int>>& M, int a1, int b1, int a2, int b2)
        {
            if (a2 < a1 || b2 < b1)
                return nullptr;

            if (a1 == a2 && b1 == b2)
            {
                return new SegmentTreeNode(a1, b1, a2, b2, M[a1][b1]);
            }

            int mid_row = (a1 + a2) / 2;
            int mid_col = (b1 + b2) / 2;

            auto t1 = constructSegementTree(M, a1, b1, mid_row, mid_col);
            auto t2 = constructSegementTree(M, a1, mid_col + 1, mid_row, b2);
            auto t3 = constructSegementTree(M, mid_row + 1, b1, a2, mid_col);
            auto t4 = constructSegementTree(M, mid_row + 1, mid_col + 1, a2, b2);

            int v1 = t1 ? t1->value : 0;
            int v2 = t2 ? t2->value : 0;
            int v3 = t3 ? t3->value : 0;
            int v4 = t4 ? t4->value : 0;

            SegmentTreeNode* node = new SegmentTreeNode(a1, b1, a2, b2, v1 + v2 + v3 + v4);
            node->children[0] = t1;
            node->children[1] = t2;
            node->children[2] = t3;
            node->children[3] = t4;

            return node;
        }

        int query(SegmentTreeNode* node, int row1, int col1, int row2, int col2)
        {
            if (!node)
                return 0;

            // one rectangel is on top side of another
            if (node->end_row < row1 || node->start_row > row2)
                return 0;

            //  one rectangel is on left side of another
            if (node->end_col < col1 || node->start_col > col2)
                return 0;

            if (node->start_row >= row1
                && node->start_col >= col1
                && node->end_row <= row2
                && node->end_col <= col2)
            {
                return node->value;
            }

            return query(node->children[0], row1, col1, row2, col2)
                + query(node->children[1], row1, col1, row2, col2)
                + query(node->children[2], row1, col1, row2, col2)
                + query(node->children[3], row1, col1, row2, col2);
        }

        void modify(SegmentTreeNode* node, int row, int col, int val)
        {
            if (!node)
                return;

            // one rectangel is on top side of another
            if (node->end_row < row || node->start_row > row)
                return;

            //  one rectangel is on left side of another
            if (node->end_col < col || node->start_col > col)
                return;

            if (node->start_row == row && node->end_row == row && node->start_col == col && node->end_col == col)
            {
                node->value = val;
                return;
            }

            modify(node->children[0], row, col, val);
            modify(node->children[1], row, col, val);
            modify(node->children[2], row, col, val);
            modify(node->children[3], row, col, val);

            int v1 = node->children[0] ? node->children[0]->value : 0;
            int v2 = node->children[1] ? node->children[1]->value : 0;
            int v3 = node->children[2] ? node->children[2]->value : 0;
            int v4 = node->children[3] ? node->children[3]->value : 0;

            node->value = v1 + v2 + v3 + v4;
        }

        SegmentTreeNode* root;
    };
}