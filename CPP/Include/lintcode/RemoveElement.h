#pragma once
#include "stdafx.h"

//Given an array and a value, remove all occurrences of that value in place and return the new length.
//The order of elements can be changed, and the elements after the new length don't matter.
namespace lintcode
{
    /**
    *@param A: A list of integers
    *@param elem: An integer
    *@return: The new length after remove
    */
    int removeElement(vector<int> &A, int elem)
    {
        // write your code here
        int i = 0;
        int j = A.size() - 1;

        while (j >= 0 && A[j] == elem)
        {
            j--;
        }

        while (i <= j)
        {
            if (A[i] == elem)
            {
                // swap A[i] and A[j]
                A[i] = A[j];
                A[j] = elem;
                j--;
            }
            else
                i++;
        }
        return j + 1;
    }
}