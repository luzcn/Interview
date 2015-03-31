#pragma once

#include "stdafx.h"

namespace SetColor
{
    void swap(int A [], int i, int j)
    {
        auto temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }

    void sortColors(int A [], int n)
    {
        int l = 0;
        int r = n - 1;

        auto p = l;
        while (p <= r)
        {
            switch (A[p])
            {
            case 0:
            {
                swap(A, l, p);
                l++;
                p++;
                break;
            }
            case 2:
            {
                swap(A, p, r);
                r--;
                break;
            }
            default:
            {
                p++;
                break;
            }
            }
        }
    }
}