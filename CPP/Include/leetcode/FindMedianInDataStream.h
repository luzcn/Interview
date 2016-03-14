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

        // Adds a number into the data structure.
        void addNum(int num)
        {
            if (right.empty() || num >= right.top())
            {
                right.push(num);
            }
            else
            {
                left.push(num);
            }

            // make left and right balance
            makeBalance();
        }

        // Returns the median of current data stream
        double findMedian()
        {
            if (left.empty() && right.empty())
                return 0;


            if (left.size() == right.size())
            {
                return (left.top() + right.top()) / 2.0;
            }
            else
            {
                return (double)left.size() > right.size() ? left.top() : right.top();
            }
        }

    private:
        void makeBalance()
        {
            // size() returns "unsigned int", 
            // using "left.size() - right.size()" may cause underflow.
            if (left.size() > right.size() + 1)
            {
                int value = left.top();
                left.pop();

                right.push(value);
            }
            else if (right.size() > left.size() + 1)
            {
                int value = right.top();
                right.pop();

                left.push(value);
            }
        }

        struct ComparatorMinHeap
        {
            bool operator()(int lhs, int rhs)
            {
                return lhs > rhs;
            }
        };

        struct ComparatorMaxHeap
        {
            bool operator()(int lhs, int rhs)
            {
                return lhs < rhs;
            }
        };

        priority_queue<int, vector<int>, ComparatorMaxHeap> left;   // max heap, left sub tree
        priority_queue<int, vector<int>, ComparatorMinHeap> right;  // min heap, right sub tree
    };
    // Your MedianFinder object will be instantiated and called as such:
    // MedianFinder mf;
    // mf.addNum(1);
    // mf.findMedian();
}