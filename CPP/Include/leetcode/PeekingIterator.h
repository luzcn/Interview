#pragma once
#include "stdafx.h"

// Given an Iterator class interface with methods : next() and hasNext(), 
// design and implement a PeekingIterator that support the peek() operation
// it essentially peek() at the element that will be returned by the next call to next().
//
// Here is an example.Assume that the iterator is initialized to the beginning of the list : [1, 2, 3].
//
// Call next() gets you 1, the first element in the list.
//
// Now you call peek() and it returns 2, the next element.Calling next() after that still return 2.
//
// You call next() the final time and it returns 3, the last element.Calling hasNext() after that should return false.
//
// Follow up : How would you extend your design to be generic and work with all types, not just integer ?
namespace leetcode
{
    class Iterator
    {
        struct Data;
        Data* data;
    public:
        Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);
        virtual ~Iterator();
        // Returns the next element in the iteration.
        int next();
        // Returns true if the iteration has more elements.
        bool hasNext() const;
    };


    class PeekingIterator : public Iterator
    {
    public:
        PeekingIterator(const vector<int>& nums)
            : Iterator(nums)
        {
            // Initialize any member here.
            // **DO NOT** save a copy of nums and manipulate it directly.
            // You should only use the Iterator interface methods.
            m_iter = nums.begin();
            end = nums.end();
        }

        // Returns the next element in the iteration without advancing the iterator.
        int peek()
        {
            return *m_iter;
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next()
        {
            int result = *m_iter;
            m_iter++;

            return result;
        }

        bool hasNext() const
        {
            return m_iter != end;
        }
    private:
        vector<int>::const_iterator m_iter;
        vector<int>::const_iterator end;
    };
}