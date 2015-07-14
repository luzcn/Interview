#pragma once
#include "stdafx.h"
#include <queue>

namespace leetcode
{
    /**
    Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

    Notes:

    You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively. 
    
    You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
    You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
    */

    class Stack 
    {
    public:
        // Push element x onto stack.
        void push(int x) 
        {
            que.push(x);
        }

        // Removes the element on top of the stack.
        void pop() 
        {
            while (que.size() > 1)
            {
                que_temp.push(que.front());
                que.pop();
            }

            que.pop();
            que = que_temp;
            que_temp = queue<int>();
        }

        // Get the top element.
        int top() 
        {
            while (que.size() > 1)
            {
                que_temp.push(que.front());
                que.pop();
            }

            auto res = que.front();
            que_temp.push(res);

            que = que_temp;
            que_temp = queue<int>();

            return res;
        }

        // Return whether the stack is empty.
        bool empty() 
        {
            return que.empty();
        }
    private:
        queue<int> que;
        queue<int> que_temp;
    };
}