#pragma once

#include "stdafx.h"

namespace Sort
{
    void swap(std::vector<int>& v, int i, int j)
    {
        auto temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

#pragma region QuickSort
    void quick_sort_helper(std::vector<int>& v, int l, int r)
    {
        if (l >= r)
            return;

        auto prefix = l - 1;
        auto pivot = v[r];

        for (int i = l; i < r; ++i)
        {
            if (v[i] < pivot)
            {
                prefix++;
                swap(v, prefix, i);
            }
        }
        prefix++;
        swap(v, prefix, r);

        quick_sort_helper(v, l, prefix - 1);
        quick_sort_helper(v, prefix + 1, r);
    }

    void quick_sort(std::vector<int>& v)
    {
        if (v.empty())
            return;

        quick_sort_helper(v, 0, v.size() - 1);
    }
#pragma endregion

#pragma region MergeSort
    void merge(vector<int>& A, int l, int mid, int r)
    {
        int i = l;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= r)
        {
            if (A[i] < A[j])
            {
                temp.push_back(A[i]);
                i++;
            }
            else
            {
                temp.push_back(A[j]);
                j++;
            }
        }

        while (i <= mid)
        {
            temp.push_back(A[i]);
            i++;
        }

        while (j <= r)
        {
            temp.push_back(A[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++)
        {
            A[l + k] = temp[k];
        }
    }
    void merge_sort(vector<int>& v, int l, int r)
    {
        // Divide
        if (l >= r)
            return;

        int mid = (l + r) / 2;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, r);

        // merge
        merge(v, l, mid, r);
    }
#pragma endregion


}