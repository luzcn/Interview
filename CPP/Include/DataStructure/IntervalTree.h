#pragma once
#include "stdafx.h"
// Consider a situation where we have a set of intervals and we need following operations to be implemented efficiently.
// 1) Add an interval
// 2) Remove an interval
// 3) Given an interval x, find if x overlaps with any of the existing intervals.

// Interval Tree : The idea is to augment a self - balancing Binary Search Tree(BST) to maintain set of intervals 
// so that all operations can be done in O(Logn) time.
namespace careercup
{
    struct Interval
    {
        int low;
        int higher;
        Interval() {}

        Interval(int x, int y)
            :low(x), higher(y)
        {}

        Interval operator=(const Interval& i)
        {
            if (this != &i)
            {
                low = i.low;
                higher = i.higher;
            }
        }
    };

    class IntervalTreeNode
    {
    public:
        Interval m_interval;
        int max;
        IntervalTreeNode* left;
        IntervalTreeNode* right;
        IntervalTreeNode(const Interval i)
        {
            m_interval = i;
            max = i.higher;
        }
    };

    // helper function to build a interval tree.
    IntervalTreeNode* insert(IntervalTreeNode* root, const Interval& i)
    {
        if (!root)
            return new IntervalTreeNode(i);

        if (i.low < root->m_interval.low)
            root->left = insert(root->left, i);
        else
            root->right = insert(root->right, i);

        // update the max
        if (root->max < i.higher)
            root->max = i.higher;

        return root;
    }

    // similar to construct a binary search tree.
    IntervalTreeNode* constructIntervalTree(vector<Interval>& v)
    {
        IntervalTreeNode* root = nullptr;
        for (auto i : v)
        {
            insert(root, i);
        }
        return root;
    }

    bool isOverlap(Interval l1, Interval l2)
    {
        if (l1.low <= l2.higher && l2.low <= l1.higher)
            return true;
        return false;
    }

    // the search takes O(lgn) for balanced interval tree.
    IntervalTreeNode* searchOverlap(IntervalTreeNode* root, Interval i)
    {
        if (!root)
            return nullptr;

        if (isOverlap(root->m_interval, i))
            return root;
        else if (root->left && root->left->max >= i.low)
            searchOverlap(root->left, i);
        else
            searchOverlap(root->right, i);

        return nullptr;
    }

    void searchAllOverlap(IntervalTreeNode* root, vector<IntervalTreeNode*>& res, Interval i)
    {
        if (!root)
            return ;

        if (isOverlap(root->m_interval, i))
        {
            res.push_back(root);
        }

        if (root->left && root->left->max >= i.low)
            searchOverlap(root->left, i);
        
        if (root->right)
            searchOverlap(root->right, i);

    }
}