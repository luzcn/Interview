#pragma once
#include "stdafx.h"

//Implement an assignment operator overloading method.
//
//Make sure that :
//
//The new data can be copied correctly
//The old data can be deleted / free correctly.
//We can assign like A = B = C
//
//Example
//If we assign like A = B, the data in A should be deleted, 
// and A can have a copy of data from B.If we assign like A = B = C, both A and B should have a copy of data from C.
//
//Consider about the safety issue if you can and make sure you released the old data.

namespace lintcode
{
    class Solution 
    {
    public:
        char *m_pData;
        Solution() 
        {
            this->m_pData = NULL;
        }
        Solution(char *pData) 
        {
            this->m_pData = pData;
        }

        // Implement an assignment operator
        Solution operator=(const Solution &object) 
        {
            // write your code here
            if (this == &object)
                return *this;

            // Allocate new memroy and copy
            if (!object.m_pData)
                return *this;

            size_t len = strlen(object.m_pData);
            char* newData = new char[len];
            std::copy(object.m_pData, object.m_pData + len, newData);

            // Delete old data
            if (m_pData) 
            {
                delete[] m_pData;
            }

            this->m_pData = newData;
            return *this;
        }
    };

}