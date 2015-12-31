#pragma once
#include "stdafx.h"
//Design and implement a TwoSum class.It should support the following operations : add and find.
//
// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.
//
// For example,
//
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false
namespace leetcode
{
    class TwoSum 
    {
    public:

        // Add the number to an internal data structure.
        void add(int number)
        {
            for (int& i : m_data)
            {
                m_set.insert(i + number);
            }

            m_data.push_back(number);
        }

        // Find if there exists any pair of numbers which sum is equal to the value.
        bool find(int value)
        {
            return m_set.find(value) != m_set.end();
        }

    private:
        vector<int> m_data;
        unordered_set<int> m_set;
    };
}