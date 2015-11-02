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
            :M(vec2d)
        {
            it_row = M.begin();
            if (it_row != M.end())
            {
                it_col = it_row->begin();
                while (it_row != M.end() && it_col == it_row->end())
                {
                    it_row++;
                    it_col = it_row->begin();
                }
            }
        }

        int next()
        {
            int data = *it_col;
            it_col++;
            if (it_col == it_row->end())
            {
                while (it_row != M.end() && it_col == it_row->end())
                {
                    it_row++;
                    it_col = it_row->begin();
                }
            }
            return data;
        }

        bool hasNext()
        {
            return it_row != M.end(); //&& it_col != it_row->end();
        }
    private:
        vector<vector<int>>::iterator it_row;
        vector<int>::iterator it_col;
        vector<vector<int>> M;
    };

}