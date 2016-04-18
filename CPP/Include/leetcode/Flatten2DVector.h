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
            if (vec2d.empty())
            {
                return;
            }

            it = vec2d.begin();
            end = vec2d.end();
            col_it = it->begin();

            // find the first non-empty vector
            while (it != end && col_it == it->end())
            {
                it++;
                col_it = it->begin();
            }
        }

        int next()
        {
            int data = *col_it;
            col_it++;

            // if current vector has finished, 
            // find the next non-empty vector begin iterator
            while (it != end && col_it == it->end())
            {
                it++;
                col_it = it->begin();
            }

            return data;
        }

        bool hasNext()
        {
            return it != end;
        }

        // the matrix begin and end iterators
        vector<vector<int>>::iterator it;
        vector<vector<int>>::iterator end;

        // the vector<int> interator
        vector<int>::iterator col_it;
    };

}