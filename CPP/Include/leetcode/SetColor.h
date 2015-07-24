#pragma once

#include "stdafx.h"

namespace SetColor
{
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        if (nums.empty())    
            return;
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < nums.size() && nums[start] ==0)
        {
            start++;
        }
        while(end >=0 && nums[end] == 2)
        {
            end--;
        }
        
        int index = start;
        while(index <= end)
        {
            if (nums[index] == 0)
            {
                swap(nums, start, index);
                start++;
                index++;
            }
            else if (nums[index] == 2)
            {
                swap(nums, index, end);
                while(end >=0 && nums[end] == 2)
                {
                    end--;
                }
            }
            else
                index++;
        }
    }
private:
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
#ifdef 0
    void swap(int A[], int i, int j)
    {
        auto temp = A[j];
        A[j] = A[i];
        A[i] = temp;
    }

    void sortColors(int A[], int n)
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
#endif // 0

}