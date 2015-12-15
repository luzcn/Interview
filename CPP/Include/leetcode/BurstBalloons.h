#pragma once
#include "stdafx.h"

// Given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by array nums.
// You are asked to burst all the balloons.
// If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
// Here left and right are adjacent indices of i.After the burst, the left and right then becomes adjacent.
//
// Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ? n ? 500, 0 ? nums[i] ? 100
//
//Example :
//
//    Given[3, 1, 5, 8]
//
//    Return 167
//
//    nums = [3, 1, 5, 8] -->[3, 5, 8] -->[3, 8]   -->[8]  -->[]
//    coins = 3 * 1 * 5 + 3 * 5 * 8 + 1 * 3 * 8 + 1 * 8 * 1 = 167
namespace leetcode
{
    // back track 
    int dfs(vector<int>& nums, int& result, int sum, int start, vector<bool>& bursted)
    {
        if (start >= nums.size())
        {
            return sum;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!bursted[i])
            {
                bursted[i] = true;
                int left = 1;
                int right = 1;

                int j = i - 1;
                while (j >= 0)
                {
                    if (!bursted[j])
                    {
                        left = nums[j];
                        break;
                    }
                    j--;
                }

                j = i + 1;
                while (j < nums.size())
                {
                    if (!bursted[j])
                    {
                        right = nums[j];
                        break;
                    }
                    j++;
                }

                //dfs(nums, result, sum + nums[i] * left * right, i + 1, bursted);
                result = max(result, dfs(nums, result, sum + nums[i] * left * right, i + 1, bursted));
                bursted[i] = false;
            }
        }

        return 0;
    }

    // divide conquer
    int maxCoinsRec(const vector<int>& nums, vector<vector<int>>& memo,int left, int right)
    {
        if (left + 1 == right)
            return 0;

        if (memo[left][right] > 0)
            return memo[left][right];

        int ans = 0;
        for (int i = left + 1; i < right; i++)
        {
            ans = max(ans,
                nums[i] * nums[left] * nums[right]
                + maxCoinsRec(nums, memo, left, i)
                + maxCoinsRec(nums, memo, i, right));

            memo[left][right] = ans;
        }

        return ans;
    }

    int maxCoinsDP(const vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int k = 2; k < n; k++)
        {
            for (int left = 0; left < n - k; left++)
            {
                int right = left + k;
                for (int i = left + 1; i < right; i++)
                {
                    dp[left][right] = max(dp[left][right],
                        nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n - 1];
    }

    int maxCoins(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> v(nums.begin(), nums.end());
        v.insert(v.begin(), 1);
        v.push_back(1);

        vector<vector<int>> memo(n + 2, vector<int>(n + 2, 0));

        return maxCoinsRec(v, memo, 0, v.size() - 1);
    }
}