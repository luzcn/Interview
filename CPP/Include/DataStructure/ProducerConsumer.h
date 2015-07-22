#pragma once
#include "stdafx.h"
#include <memory>
#include <mutex>
#include <condition_variable>
#include <queue>

namespace producer_consumer
{
    template<typename T>
    class producer_consumer_queue
    {
    public:
        producer_consumer_queue(size_t size)
            :m_max_size(size)
        {}

        void push(T item)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_queue.size >= m_max_size)
            {
                cv_pop.wait(lock, [&](){ return m_queue.size() < m_max_size; });
            }

            m_queue.push(item);
            cv_push.notify_one();

        }

        void pop()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_queue.empty())
            {
                cv_push.wait(lock, [&](){ return !m_queue.empty(); });
            }

            m_queue.pop();
            cv_pop.notify_one();
        }

        size_t size()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_queue.size();
        }
    private:
        std::condition_variable cv_push;
        std::condition_variable cv_pop;
        std::mutex m_mutex;
        std::queue<T> m_queue;
        std::size_t m_max_size;
    };
}
