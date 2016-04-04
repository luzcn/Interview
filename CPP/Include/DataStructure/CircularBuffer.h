#pragma once
#include "stdafx.h"

namespace datastructure
{
    // using a vector to simulate the circular buffer
    // buffer[index] = data;
    // index = (index + 1) % cap;
    class CircularBuffer
    {
    public:
        CircularBuffer(int capacity)
            :cap(capacity), index(0), buffer(vector<int>(capacity, 0))
        {}

        void add(int data)
        {
            buffer[index] = data;
            index = (index + 1) % cap;
        }

        void printAll()
        {
            for (int i = index; i < index + cap; i++)
            {
                cout << buffer[i % cap] << endl;
            }
        }
    private:
        int cap;
        int index;
        vector<int> buffer;
    };

}

