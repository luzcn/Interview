#pragma once
#include "stdafx.h"

// Given two 1d vectors, implement an iterator to return their elements alternately.
//
// For example, given two 1d vectors :
//
// v1 = [1, 2]
// v2 = [3, 4, 5, 6]
//
// By calling next repeatedly until hasNext returns false, 
// the order of elements returned by next should be : [1, 3, 2, 4, 5, 6].
//
//  Follow up : What if you are given k 1d vectors ? How well can your code be extended to such cases ?

// This problem is easy to use Java, because it provides the Iterator member function hasNext()
// In c++, we need to save the end() iterator to comparing with current iterator.
namespace leetcode
{
    class ZigzagIterator 
    {
    public:
        ZigzagIterator(vector<int>& v1, vector<int>& v2)
        {
            r1 = v1.begin();
            end1 = v1.end();

            r2 = v2.begin();
            end2 = v2.end();
            k = 0;
        }

        int next()
        {
            int data = 0;

            switch (k % 2)
            {
            case 0: // v1
                if (r1 != end1)
                {
                    data = *r1;
                    r1++;
                }
                else
                {
                    data = *r2;
                    r2++;
                }
                k++;
                break;
            case 1:
                if (r2 != end2)
                {
                    data = *r2;
                    r2++;
                }
                else
                {
                    data = *r1;
                    r1++;
                }
                k++;
                break;
            default:
                break;
            }

            return data;
        }

        bool hasNext()
        {
            return r1 != end1 || r2 != end2;
        }
    private:
        vector<int>::iterator r1, end1;
        vector<int>::iterator r2, end2;

        int k;
    };


    // follow up k vectors
    class ZigzagIteratorK
    {
    public:
        ZigzagIteratorK(vector<vector<int>>& vec)
            :v(vec), row(0), col(0)
        {
            k = vec.size();
        }

        int next()
        {

        }

        bool hasNext()
        {
            return row < v.size();
        }

    private:
        vector<vector<int>>& v;
        int row;
        int col;
        int k;
    };
}