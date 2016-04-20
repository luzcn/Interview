#pragma once
#include "stdafx.h"

//You are given an integer array nums and you have to return a new counts array.
//The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
//Example:
//
//Given nums = [5, 2, 6, 1]
//
//To the right of 5 there are 2 smaller elements(2 and 1).
//To the right of 2 there is only 1 smaller element(1).
//To the right of 6 there is 1 smaller element(1).
//To the right of 1 there is 0 smaller element.
//
//Return the array[2, 1, 1, 0].
namespace leetcode
{
    // insertation sort + binary search
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> result(nums.size(), 0);
        vector<int> t;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int l = 0;
            int r = t.size();

            while (l < r)
            {
                int m = l + (r - l) / 2;

                if (t[m] >= nums[i])
                {
                    r = m;
                }
                else
                {
                    l = m + 1;
                }
            }

            result[i] = r;
            t.insert(t.begin() + r, nums[i]);
        }

        return result;
    }

    // we can improve to use the c++ stl lower_bound and distance
    vector<int> countSmaller2(vector<int>& nums)
    {
        vector<int> result(nums.size(), 0);
        vector<int> t;

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));

            result[i] = d;
            t.insert(t.begin() + d, nums[i]);
        }

        return result;
    }


    // we can construct a binary search tree
    // 
    class Solution
    {
    public:
        struct Node 
        {
            Node(int v, int s) 
                : val(v), smaller(s), left(nullptr), right(nullptr) 
            {}

            int val;
            int smaller;
            Node *left, *right;
        };

        vector<int> countSmaller(vector<int>& nums)
        {
            vector<int> result(nums.size());

            Node* root = nullptr;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                result[i] = insert(root, nums[i]);
            }

            return result;
        }
    private:
        int insert(Node* root, int value)
        {
            if (!root)
            {
                root = new Node(value, 0);
                return 0;
            }

            if (value < root->val)
            {
                root->smaller++;
                return insert(root->left, value);
            }
            else
            {
                // consider the example 6,4,5
                // after insert 4, the node 5, will have smaller increased by 1
                // if we do not add the "root->smaller", we will miss the number "4", which is also smaller than "6".
                return root->smaller + insert(root->right, value) + (root->val < value);
            }
        }
    };
}