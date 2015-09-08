#pragma once
#include "stdafx.h"

//The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.
//
//start and end are both integers, they should be assigned in following rules :
//
//The root's start and end is given by build method.
//The left child of node A has start = A.left, end = (A.left + A.right) / 2.
//The right child of node A has start = (A.left + A.right) / 2 + 1, end = A.right.
//if start equals to end, there will be no children for this node.
//
//Implement a build method with two parameters start and end, 
// so that we can create a corresponding segment tree with every node has the correct start and end value, return the root of this segment tree.
//
//Given start = 0, end = 3. The segment tree will be :
//
//        [0, 3]
//        /     \
//   [0, 1]      [2, 3]
//  /     \       /   \
// [0, 0][1, 1] [2, 2][3, 3]
//
//Given start = 1, end = 6. The segment tree will be :
//
//[1, 6]
/// \
//[1, 3][4, 6]
/// \ / \
//[1, 2][3, 3][4, 5][6, 6]
/// \ / \
//[1, 1][2, 2][4, 4][5, 5]
//
//Clarification
//
//Segment Tree(a.k.a Interval Tree) is an advanced data structure which can support queries like :
//
//which of these intervals contain a given point
//which of these points are in a given interval

namespace lintcode
{
    class SegmentTreeNode
    {
    public:
        int start, end;
        int max;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int s, int e, int max)
            :start(s), end(e), left(nullptr), right(nullptr), max(max)
        {}
    };


    SegmentTreeNode * buildRec(vector<int>& arr, int l, int r)
    {
        if (l > r)
            return nullptr;
        if (l == r)
            return new SegmentTreeNode(l, r, arr[l]);

        int m = l + (r - l) / 2;
        auto leftSub = buildRec(arr, l, m);
        auto rightSub = buildRec(arr, m + 1, r);

        SegmentTreeNode* root = new SegmentTreeNode(l, r, std::max(leftSub->max, rightSub->max));
        root->left = leftSub;
        root->right = rightSub;

        return root;
    }

    // build the segment tree.
    SegmentTreeNode * build(vector<int>& arr)
    {
        if (arr.empty())
            return nullptr;

        return buildRec(arr, 0, arr.size() - 1);
    }

    // query on a segment tree
    // the idea is if the the current node range is in the query range, return this node value
    // if current range is totally out the query range, return with no values.
    int query(SegmentTreeNode *root, int start, int end)
    {
        if (!root || start > root->end || end < root->start)
            return INT_MIN;

        if (start <= root->start && root->end <= end)
            return root->max;

        return std::max(query(root->left, start, end), query(root->right, start, end));
    }
}

/**
* Definition of SegmentTreeNode:
* class SegmentTreeNode {
* public:
*     int start, end;
*     SegmentTreeNode *left, *right;
*     SegmentTreeNode(int start, int end) {
*         this->start = start, this->end = end;
*         this->left = this->right = NULL;
*     }
* }
*/