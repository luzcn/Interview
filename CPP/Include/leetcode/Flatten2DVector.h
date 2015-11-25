#pragma once
#include "stdafx.h"

//implement an iterator to flatten a 2d vector.
//
//For example,
//Given 2d vector =
//
//[
//    [1, 2],
//    [3],
//    [4, 5, 6]
//]
//
//By calling next repeatedly until hasNext returns false, 
// the order of elements returned by next should be : [1, 2, 3, 4, 5, 6].

// some test case: {[[]]}, { [[1],[],[],[3,4,5]]}
namespace leetcode
{
    class Vector2D {
    public:
        Vector2D(vector<vector<int>>& vec2d)
        {
            m_row = vec2d.begin();
            m_end = vec2d.end();

            if (m_row != m_end)
            {
                m_col = m_row->begin();
            }

            // find the first non-empty vector
            while (m_row != m_end && m_col == m_row->end())
            {
                m_row++;
                if (m_row != m_end)
                {
                    m_col = m_row->begin();
                }
            }
        }

        int next()
        {
            int data = *m_col;
            m_col++;

            // if current vector has finished, 
            // find the next non-empty vector
            while (m_row != m_end && m_col == m_row->end())
            {
                m_row++;
                if (m_row != m_end)
                {
                    m_col = m_row->begin();
                }
            }

            return data;
        }

        bool hasNext()
        {
            return m_row != m_end;
        }

        vector<vector<int>>::iterator m_row;
        vector<int>::iterator m_col;
        vector<vector<int>>::iterator m_end;
    };

}