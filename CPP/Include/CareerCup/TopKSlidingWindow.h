#pragma once
#include "stdafx.h"
#include <set>
#include <functional>

//  Find k - largest elements in a sliding window
//
//  A long array A[] with size n is given to you.
//
// There is a sliding window of size w which is moving from the very left of the array to the very right.
// You can only see the w numbers in the window.
//
// Each time the sliding window moves rightwards by one position.
// Find top k elements in the sliding window when it moves to each n positions.
namespace careercup
{
    vector<int> getK(std::multiset<int, greater<int>>& bst, int k)
    {
        vector<int> result;
        std::multiset<int, greater<int>>::iterator it = bst.begin();

        for (int i = 0; i < k; i++)
        {
            result.push_back(*it);
            it++;
        }

        return result;
    }

    vector<vector<int>> topKSliding(vector<int>& nums, int w, int k)
    {
        std::multiset<int, greater<int>> bst;
        vector<vector<int>> result;

        for (int i = 0; i < w; i++)
        {
            bst.insert(nums[i]);  // O(logw)
        }
        auto topk = getK(bst, k);   // O(k)
        result.push_back(topk);

        for (int i = w; i < nums.size(); i++)
        {
            int data_remove = nums[i - w];
            bst.erase(bst.find(data_remove));   // O(logw)

            bst.insert(nums[i]);

            topk = getK(bst, k);
            result.push_back(topk);
        }

        return result;
    }
}