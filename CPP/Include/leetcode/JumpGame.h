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
namespace JumpGame
{
#pragma region DP Solution
    /**
     *  DP solution:
     *  defined jump[i] as the maximum remaining steps from 0 to i.
     *
     *  jump[0] = 0;
     *  jump[i] = max(jump[i-1] - 1, A[i - 1] -1); i > 0.
     *
     *  for example: A = [2,3,1,1,4]
     *  at position A[3], it can be reached from A[1] or A[2], we need to get the maximum remaining steps.
     *  set dp[0] = 0,
     *  dp[1] = max(2-1, 0-1) = 1;
     *  dp[2] = max(3-1, 1 -1) = 2;
     *  dp[3] = max(2-1,  1-1) = 1;
     *  dp[4] = max(1-1,1-1) = 0.
     */
    bool canJumpDP(int A [], int n)
    {
        if (n <= 0)
            return false;
        if (A[0] >= n - 1)
            return true;

        vector<int> jump(n, 0);
        for (int i = 1; i < n; i++)
        {
            jump[i] = max(jump[i - 1], A[i - 1]) - 1;
            if (jump[i] < 0)
                return false;
        }
        return jump[n - 1] >= 0;
    }
#pragma endregion


#pragma region Simple Solution
    bool camJump(int A [], int n)
    {
        if (n <= 0)
            return false;

        int max_jump = 0;  // the farthest position it can jump.
        for (int i = 0; i < n; i++)
        {
            if (max_jump >= n - 1)  // it can reach the end of the array
            {
                return true;
            }
            max_jump = max(max_jump, A[i] + i);  // update the maximum can jump length.

            if (max_jump == i)  // it cannot jump anymore.
                return false;
        }

        return true;
    }
#pragma endregion
}

/**
 *	 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Your goal is to reach the last index in the minimum number of jumps.

 For example:
 Given array A = [2,3,1,1,4]

 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 http://www.cnblogs.com/TenosDoIt/p/3719630.html
 */
namespace JumpGame2
{
    /**
     *	The greedy algorithm.
     *
     *	for each position i, A[i] + i is the furthest can jump.
     *	if A[i] +i = i, cannot move anymore.
     *	if A[i] + i > 0, we need to jump at least one step to reach the end, so jump++;
     *	if A[i]+i >= n - 1, can jump to the end, return jump.
     *
     *	find the maximum number from the range of [i+1, i + A[i]], update the furthest can jump.
     *
     *	o(n^2) worst case.
     *	
     *	http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
     */
    int jump(int A [], int n)
    {
        if (n <= 0)
        {
            return -1;
        }

        int current = 0;
        int jump = 0;
        int current_furthest = 0;

        vector<int> path;

        while (current < n)
        {
            current_furthest = current + A[current];
            if (current_furthest == current)
            {
                // cannot move anymore
                return -1;
            }
            if (current_furthest > 0)
            {
                path.push_back(current);
                jump++;
            }
            if (current_furthest >= n - 1)
            {
                return jump;
            }

            // find the max number in [i+1, i + A[i]], can update the current_furthest.
            int max = 0;
            for (int i = current + 1; i <= current_furthest; i++)
            {
                if (A[i] >= max)
                {
                    max = A[i];
                    current = i;
                }
            }
        }

        return jump;
    }

#pragma region Improved Greedy
    int jump2(int A [], int n)
    {
        if (n <= 1)
        {
            return 0;
        }

        int current = 0, furthurst = 0;
        int jump = 0;

        // current > furthurst means cannot move anymore.
        while (current <= furthurst)
        {
            auto prev_furthurst = furthurst; // save for the next iteration use.
            jump++;

            for (int i = current; i <= prev_furthurst; i++)
            {
                auto p = i + A[i];

                if (p >= n - 1)
                    return jump;

                if (p > furthurst)
                    furthurst = p;
            }

            // we only need to check the number between the [prev_furthust + 1, furthurst], 
            // since all numbers in [current, prev_furthust] has already been checked.
            current = prev_furthurst + 1;
        }
        return 0;
    }
#pragma endregion

#pragma region DP Solution

#pragma endregion

}