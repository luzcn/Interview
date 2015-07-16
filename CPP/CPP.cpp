// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\CountCompleteTreeNodes.h"
#include "CareerCup\FindKthSmallest.h"


using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> res(nums.size());
    res[0] = 1;
    int n = nums.size();

    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int right_product = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        res[i] = res[i] * right_product;
        right_product *= nums[i];
    }

    return res;
}

int _tmain(int argc, _TCHAR* argv [])
{
    vector<int> v{ 1, 2, 3, 4 };
    productExceptSelf(v);

    return 0;
}