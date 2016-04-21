#pragma once

#include "stdafx.h"

/**
 *	 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.

 A = [3,2,1,0,4], return false.
 */
namespace leetcode
{

    //DP solution:
    //defined jump[i] as the maximum remaining steps from 0 to i.
    //
    //jump[0] = 0;
    //jump[i] = max(jump[i-1] - 1, A[i - 1] -1); i > 0.
    //
    //for example: A = [2,3,1,1,4]
    //at position A[3], it can be reached from A[1] or A[2], we need to get the maximum remaining steps.
    //set dp[0] = 0,
    //dp[1] = max(2-1, 0-1) = 1;
    //dp[2] = max(3-1, 1 -1) = 2;
    //dp[3] = max(2-1,  1-1) = 1;
    //dp[4] = max(1-1,1-1) = 0.

    bool canJumpDP(vector<int>& nums)
    {
        if (nums.empty())
        {
            return false;
        }
        int n = nums.size();
        if (nums[0] >= n - 1)
        {
            return true;
        }

        vector<int> jump(n, 0);
        for (int i = 1; i < n; i++)
        {
            jump[i] = max(jump[i - 1], nums[i - 1]) - 1;

            if (jump[i] < 0)
            {
                return false;
            }
        }

        return jump[n - 1] >= 0;
    }


    // The greedy solution
    // start the "range" from nums[0],
    // if we found any nums[i]+i > range, we extend the range to this larger one
    // once we have range can reach the end of array, return true
    bool camJumpGreedy(vector<int>& nums)
    {
        if (nums.empty())
        {
            return false;
        }

        int n = nums.size();
        int range = 0;
        for (int i = 0; i <= range; i++)
        {
            if (range >= n - 1)
            {
                return true;
            }

            range = max(range, nums[i] + i);
        }

        return false;
    }

    // Given an array of non-negative integers, you are initially positioned at the first index of the array.
    // Each element in the array represents your maximum jump length at that position.
    //
    // Your goal is to reach the last index in the minimum number of jumps.
    //
    // For example:
    // Given array A = [2,3,1,1,4]
    // The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
    //
    // You can assume that you can always reach the last index.
    //
    // BFS to find the shortest path
    class Solution
    {
    public:
        int jump(vector<int>& nums)
        {
            if (nums.size() <= 1)
            {
                return 0;
            }

            int n = nums.size();
            int steps = 0;
            int start = 0;
            int furthest = nums[0];

            while (furthest < n - 1)
            {
                int prev_furthest = furthest;
                steps++;

                for (int j = start; j <= prev_furthest; j++)
                {
                    if (j + nums[j] >= n - 1)
                    {
                        break;
                    }

                    furthest = max(furthest, j + nums[j]);
                }
                start = prev_furthest + 1;
            }

            return steps + 1;
        }
    private:
        // TLE 
        int bfs(vector<int>& nums)
        {
            if (nums.empty() || nums[0] >= nums.size() - 1)
            {
                return 0;
            }

            int steps = 0;          // the jump steps
            std::queue<int> que;    // the index
            std::queue<int> que_temp;
            que.push(0);

            while (!que.empty())
            {
                int i = que.front();
                que.pop();

                if (i + nums[i] >= nums.size() - 1)
                {
                    break;
                }

                for (int j = i + 1; j <= nums[i] + i; j++)
                {
                    que_temp.push(j);
                }

                if (que.empty())
                {
                    steps++;
                    swap(que, que_temp);
                }
            }

            return steps;
        }
    };

}
