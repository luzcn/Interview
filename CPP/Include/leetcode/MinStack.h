#pragma once
#include "stdafx.h"
#include <stack>
//  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//  push(x) --Push element x onto stack.
//  pop() --Removes the element on top of the stack.
//  top() --Get the top element.
//  getMin() --Retrieve the minimum element in the stack.

namespace leetcode
{
    class MinStack
    {
    public:
        MinStack()
            :m_min(INT_MAX)
        {}
        void push(int x);
        void pop();
        int top();
        int getMin();
    private:
        std::stack<int> m_stack;
        std::stack<int> m_minStack;
        int m_min;
    };

    void MinStack::push(int x)
    {
        m_stack.push(x);
        // Here, it must use '<=';
        // consider the stack has "3,3,3", the min_stack must be "3,3,3"
        if (m_min <= x)
        {
            m_minStack.push(x);
        }
    }

    void MinStack::pop()
    {
        if (!m_stack.empty())
        {
            // The current min element could be poped
            if (m_stack.top() == m_min)
            {
                // Also need to remove(pop) the current min element
                m_minStack.pop();
                if (!m_minStack.empty())
                    m_min = m_minStack.top();
                else
                    m_min = INT_MAX;
            }
            m_stack.pop();
        }
    }

    int MinStack::top()
    {
        return m_stack.top();
    }

    int MinStack::getMin()
    {
        return m_min;
    }
}