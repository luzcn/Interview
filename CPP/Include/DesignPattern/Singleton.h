#include "stdafx.h"
#include <mutex>

namespace DesignPattern
{
    class SingletonObject
    {
    private:
        // Private Constructor
        SingletonObject();

        // Stop the compiler generating methods of copy the object
        SingletonObject(const SingletonObject& copy) = delete;            // Not Implemented
        SingletonObject& operator=(const SingletonObject& copy) = delete; // Not Implemented

    public:
        static SingletonObject& getInstance()
        {
            // The only instance
            // Guaranteed to be lazy initialized
            // Guaranteed that it will be destroyed correctly
            static SingletonObject instance;
            return instance;
        }
    };

    class Singleton
    {
    public:
        static Singleton* getInstance()
        {
            if (!instance)
            {
                std::lock_guard<mutex> lock(m_mutex);
                if (!instance)
                {
                    instance = new Singleton();
                }
            }

            return instance;
        }

    private:
        Singleton() {};
        static mutex m_mutex;
        static Singleton* instance;
    };
}

