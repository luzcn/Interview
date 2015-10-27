#pragma once
#include "stdafx.h"
#include <algorithm>

//Median is the middle value in an ordered integer list.
//If the size of the list is even, there is no middle value.
//So the median is the mean of the two middle value.
//
//Examples:
//
//[2, 3, 4], the median is 3
//
//[2, 3], the median is(2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations :
//
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//
//For example :
//
//add(1)
//add(2)
//findMedian() -> 1.5
//add(3)
//findMedian() -> 2
namespace leetcode
{
    class MedianFinder
    {
    public:

        // TLE??
         //Adds a number into the data structure.
        void addNum(int num)
        {
            if (maxHeap.empty())
            {
                maxHeap.push(num);
                return;
            }
            else if (minHeap.empty())
            {
                minHeap.push(num);
                return;
            }

            if (num > minHeap.top())
            {
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }

            while (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top() 
                || maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            while (!maxHeap.empty() && !minHeap.empty() && minHeap.top() < maxHeap.top() 
                || minHeap.size() > maxHeap.size() + 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }


        // Returns the median of current data stream
        double findMedian()
        {
            if (minHeap.size() > maxHeap.size())
            {
                return (double)minHeap.top();
            }
            
            if (maxHeap.size() > minHeap.size())
            {
                return (double)maxHeap.top();
            }
            
            if (maxHeap.size() == minHeap.size())
            {
                return (double)((double)minHeap.top() + (double)maxHeap.top()) / 2;
            }
        }
    private:
        struct minHeapComparator
        {
            bool operator() (const int& a, const int& b)
            {
                return a > b;
            }
        };
        struct maxHeapComparator
        {
            bool operator() (const int& a, const int& b)
            {
                return a < b;
            }
        };

        std::priority_queue<int, vector<int>, minHeapComparator> minHeap;
        std::priority_queue<int, vector<int>, maxHeapComparator> maxHeap;
    };

    // Your MedianFinder object will be instantiated and called as such:
    // MedianFinder mf;
    // mf.addNum(1);
    // mf.findMedian();
}