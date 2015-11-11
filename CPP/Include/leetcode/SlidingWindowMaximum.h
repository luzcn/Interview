#pragma once
#include "stdafx.h"
#include <queue>

//  Given an array nums, there is a sliding window of size k which is moving 
//  from the very left of the array to the very right.
//  You can only see the k numbers in the window.Each time the sliding window moves right by one position.
//
//  For example,
//  Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.

//  Window position                Max
//  -------------- - ---- -
//  [1  3 - 1] - 3  5  3  6  7       3
//  1[3 - 1 - 3] 5  3  6  7       3
//  1  3[-1 - 3  5] 3  6  7       5
//  1  3 - 1[-3  5  3] 6  7       5
//  1  3 - 1 - 3[5  3  6] 7       6
//  1  3 - 1 - 3  5[3  6  7]      7
//
//  Therefore, return the max sliding window as[3, 3, 5, 5, 6, 7].
// http://articles.leetcode.com/2011/01/sliding-window-maximum.html
namespace leetcode
{
    struct Data
    {
        int value;
        int index;

        Data(int v, int i)
            :value(v), index(i)
        {}
    };
    struct comparator
    {
        bool operator() (Data a, Data b)
        {
            return a.value < b.value;
        }
    };
    
    vector<int> maxSlidingWindowHeap(vector<int>& nums, int k)
    {
        if (k == 1)
            return nums;

        int n = nums.size();
        vector<int> res;
        std::priority_queue<Data, vector<Data>, comparator> heap;   // max heap

        for (int i = 0; i < k; i++)
        {
            heap.push(Data(nums[i], i));
        }

        res.push_back(heap.top().value);

        for (int i = k; i < n; i++)
        {
            while (heap.top().index <= i - k)
            {
                heap.pop();
            }

            heap.push(Data(nums[i], i));

            res.push_back(heap.top().value);
        }

        return res;
    }

    // using deque to store the index.
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (k <= 1)
        {
            return nums;
        }

        vector<int> result;
        std::deque<int> que;    // double ended queue to store the index

        for (int i = 0; i < k; i++)
        {
            while (!que.empty() && nums[i] >= nums[que.back()])
            {
                que.pop_back();
            }

            que.push_back(i);
        }
        result.push_back(nums[que.front()]);

        for (int i = k; i < nums.size(); i++)
        {
            // a new data is added to the window now, 
            // need remove all data that are less or equal to this data
            while (!que.empty() && nums[i] >= nums[que.back()])
            {
                que.pop_back();
            }

            // the largest element may be out the sliding window size.
            while (!que.empty() && que.front() <= i - k)
            {
                que.pop_front();
            }

            que.push_back(i);

            result.push_back(nums[que.front()]);
        }

        return result;
    }
}