#pragma once
#include "stdafx.h"
#include <stack>

namespace leetcode
{
    class Queue {
    public:
        // Push element x to the back of queue.
        void push(int x)
        {
            mainStack.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void)
        {
            while (mainStack.size() > 1)
            {
                auto num = mainStack.top();
                mainStack.pop();
                tempStack.push(num);
            }
            mainStack.pop();

            while (!tempStack.empty())
            {
                mainStack.push(tempStack.top());
                tempStack.pop();
            }
        }

        // Get the front element.
        int peek(void)
        {
            while (mainStack.size() > 1)
            {
                auto num = mainStack.top();
                mainStack.pop();
                tempStack.push(num);
            }
            auto res = mainStack.top();

            while (!tempStack.empty())
            {
                mainStack.push(tempStack.top());
                tempStack.pop();
            }

            return res;
        }

        // Return whether the queue is empty.
        bool empty(void)
        {
            return mainStack.empty();
        }
    private:
        std::stack<int> mainStack;
        std::stack<int> tempStack;
    };
}