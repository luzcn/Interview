#pragma once
#include "stdafx.h"

namespace careercup
{
    // create a min heap by using an array
    class Heap
    {
    public:
        void heapify(vector<int> &A)
        {
            if (A.empty())
                return;

            for (int i = 0; i < A.size(); i++)
            {
                siftUp(A, i);
            }
        }
    private:
        void siftUp(vector<int> &A, int i)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int minValue = A[i];
            if (left < A.size() && A[left] < minValue)
            {
                minValue = A[left];
            }

            if (right < A.size() && A[right] < minValue)
            {
                minValue = A[right];
            }

            if (left < A.size() && minValue == A[left])
            {
                //swap
                int temp = A[i];
                A[i] = A[left];
                A[left] = temp;
            }
            else if (right < A.size() && minValue == A[right])
            {
                int temp = A[i];
                A[i] = A[right];
                A[right] = temp;
            }

            if (i > 0)
                siftUp(A, (i - 1) / 2);
        }
    };
}