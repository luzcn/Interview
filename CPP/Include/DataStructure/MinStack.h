#pragma once

#include "stdafx.h"
#include <limits>
#include <stack>

class MinStack
{
public:
    MinStack()
        :m_min(INT_MAX)
    {
    }

    void push(int val)
    {
        if (val <= m_min) // must be "<="
        {
            m_min_stack.push(m_min);
            m_min = val;
        }

        m_stack.push(val);
    }

    int top()
    {
        if (empty())
            throw std::exception("Stack empty");

        return m_stack.top();
    }

    bool empty()
    {
        return m_stack.empty();
    }

    void pop()
    {
        if (empty())
            throw std::exception("Stack empty");

        auto t = top();

        if (t == m_min)
        {
            m_min_stack.pop();
            if (!m_min_stack.empty())
            {
                m_min = m_min_stack.top();
            }
            else
            {
                m_min = INT_MAX;
            }
        }

        m_stack.pop();
    }

    int get_min()
    {
        return m_min;
    }

private:
    int m_min;
    // used as internal stack
    std::stack<int, std::vector<int>> m_stack;

    // to save the min elements
    std::stack<int, std::vector<int>> m_min_stack;
};


#if 0
class MinStack
{
public:
    MinStack()
        :current_min(std::numeric_limits<int>::max()), s(stack<int>()), stack_min(stack<int>())
    {
    }

    void push(int x)
    {
        s.push(x);
        if (x <= current_min)
        {
            stack_min.push(x);
            current_min = x;
        }
    }

    void pop()
    {
        if (!empty())
        {
            int t = s.top();

            if (!stack_min.empty() && t == stack_min.top())
            {
                stack_min.pop();
                if (!stack_min.empty())
                    current_min = stack_min.top();
                else
                    current_min = std::numeric_limits<int>::max();
            }
            s.pop();
        }
    }

    int top()
    {
        int result = 0;
        if (!empty())
        {
            result = s.top();
        }

        return result;
    }

    int getMin()
    {
        return current_min;
    }
private:
    std::stack<int> s;
    std::stack<int> stack_min;
    int current_min;

    bool empty()
    {
        return s.empty();
    }
};
#endif // 0
