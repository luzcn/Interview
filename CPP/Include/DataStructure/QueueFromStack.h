#pragma once
#include "stdafx.h"
#include <stack>

/// <summary>
///  Use two Stacks to simulate the queue behaviors.
/// </summary>
class QueueWithStack
{
public:
    QueueWithStack()
    {
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    bool empty()
    {
        return m_stack.empty();
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    int size()
    {
        return m_stack.size();
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    int front()
    {
        int result;
        while (!m_stack.empty())
        {
            auto elem = m_stack.top();
            m_stack_back.push(elem);
            m_stack.pop();
        }

        if (!m_stack_back.empty())
        {
            result =  m_stack_back.top();
        }
       
        while (!m_stack_back.empty())
        {
            auto elem = m_stack_back.top();
            m_stack.push(elem);
            m_stack_back.pop();
        }

        return result;
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    void pop()
    {
        if (empty())
            return;

        while (!m_stack.empty())
        {
            auto elem = m_stack.top();
            m_stack_back.push(elem);
            m_stack.pop();
        }

        if (!m_stack_back.empty())
        {
            m_stack_back.pop();
        }

        while (!m_stack_back.empty())
        {
            auto elem = m_stack_back.top();
            m_stack.push(elem);
            m_stack_back.pop();
        }
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    void push(int val)
    {
        m_stack.push(val);
    }

private:
    std::stack<int, std::vector<int>> m_stack;
    std::stack<int, std::vector<int>> m_stack_back;

};

/*
#include "DataStructure/QueueFromStack.h"

int _tmain(int argc, _TCHAR* argv [])
{
    QueueWithStack queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);


    while (!queue.empty())
    {
        std::cout << queue.front() << std::endl;
        queue.pop();
    }
    return 0;
}*/
