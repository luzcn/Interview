#include "stdafx.h"

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
}

