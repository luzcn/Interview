#pragma once
#include "stdafx.h"


/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses
have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/

namespace leetcode
{
#pragma region HouseRob 1
    // The recursive solution.    
    int robRec(vector<int>& num, int i)
    {
        if (i >= num.size())
            return 0;

        if (i == num.size() - 1)
            return num[i];

        return std::max(num[i] + robRec(num, i + 2), robRec(num, i + 1));
    }

    // The DP solution
    int robDP(vector<int>& num)
    {
        if (num.size() == 0)
            return 0;

        int n = num.size();
        vector<int> res(n + 1, 0);
        res[1] = num[0];  // if there is only one house, we can only rob this one.

        for (int i = 2; i <= n; i++)
        {
            res[i] = max(res[i - 2] + num[i - 1], res[i - 1]);
        }

        return res[n];
    }

    int rob(vector<int> &num)
    {
        if (num.size() == 0)
            return 0;

        return robRec(num, 0);
    }
#pragma endregion


#pragma region HouseRob 2

    // The houses are arranged as a circle.
    // Thought: What have been changed after circle?
    // The only difference is that we cannot rob the first house, 
    // if we rob the last one, and also no last house if we rob the first one.
    // so we can DP scan the array twice, the first is nums[0...n-2] and second time is num[1...n-1]. 
    int rob2(vector<int>& nums)
    {
        if (nums.empty())
            return 0;

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp(n + 1, 0);

        // include the first element, no last element
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int max1 = dp[n - 1];

        // include the last element, no first element
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        int max2 = dp[n];

        return std::max(max1, max2);
    }
#pragma endregion


#pragma region House Robber 3
    int robRec(TreeNode* node)
    {
        if (!node)
            return 0;

        if (!node->left && !node->right)
            return node->val;

        int v1 = 0;
        int v2 = 0;
        if (node->left)
        {
            v1 = robRec(node->left->left) + node->val;
            v2 = robRec(node->left->right) + node->val;
        }

        int v3 = robRec(node->left);
        int v4 = robRec(node->right);

        return max(max(v1, v2), max(v3, v4));

    }


    int rob3(TreeNode* root)
    {
        if (!root)
            return 0;

        return robRec(root);
    }
#pragma endregion
}
