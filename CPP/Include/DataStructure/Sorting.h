#pragma once

#include "stdafx.h"

namespace datastructure
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

#pragma region Radix Sort
    void radixSort(vector<int>& nums)
    {
        int maxElement = *std::max_element(nums.begin(), nums.end());
        int base = 1;

        // For each digit, using counting sort
        while (maxElement / base > 0)
        {
            vector<int> count(10, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                count[(nums[i] / base) % 10]++;
            }

            vector<int> result(nums.size(), 0);

            for (int j = 1; j < 10; j++)
            {
                count[j] += count[j - 1];
            }

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                result[count[(nums[i] / base) % 10] - 1] = nums[i];
                count[(nums[i] / base) % 10]--;
            }

            // copy back to the orignial array
            for (int i = 0; i < nums.size(); i++)
            {
                nums[i] = result[i];
            }

            base *= 10;
        }
    }
#pragma endregion

#pragma region Counting Sort
    vector<int> countSort(vector<int>& nums, int k)
    {
        vector<int> C(k + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            C[nums[i]]++;
        }

        vector<int> res(nums.size());

        // Sum each element in C with previouse one,
        // now, the value of C[j] is the position the "j" needs to put in out put array
        for (int j = 1; j < C.size(); j++)
        {
            C[j] += C[j - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int data = nums[i];     // the elements need to sort
            int pos = C[data] - 1;  // the sorted position where this data need to put
            res[pos] = data;        // put data 
            C[data]--;              // decrease the postion by 1
        }

        return res;
    }
#pragma endregion

}