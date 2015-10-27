#pragma once

#include "stdafx.h"


namespace leetcode
{
    /// <summary>
    ///  If you were only permitted to complete at most one transaction 
    ///  (ie, buy one and sell one share of the stock), 
    ///  design an algorithm to find the maximum profit.
    /// </summary>
    /// <param name=""> </param>
    /// <return> </return>
    int maxProfit1(const std::vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        size_t n = prices.size();
        int max_profit = 0;
        int best_time_buy = 0;
        int best_time_sell = 0;
        int min = prices[0];


        for (size_t i = 0; i < n; ++i)
        {
            // find the minimun number in the array,
            // which is the best time to buy.
            if (prices[i] < min)
            {
                min = prices[i];
                best_time_buy = i;
            }
            else
            {
                // if the current profit is greater than current max profit,
                // update the min price and best to sell.
                auto profit = prices[i] - min;
                if (profit > max_profit)
                {
                    max_profit = profit;
                    best_time_sell = i;
                }
            }
        }

        return max_profit;
    }

#pragma region Best Time to Buy and Sell Stock II
    /// <summary>
    ///  Say you have an array for which the ith element is the price of a given stock on day i.
    ///  Design an algorithm to find the maximum profit.
    ///  
    ///  You may complete as many transactions as you like(ie, buy one and sell one share of the stock multiple times).
    ///  However, you may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).
    /// </summary>
    int maxProfit2(std::vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        size_t n = prices.size();

        int max_profit = 0;
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (prices[i] < prices[i + 1])
            {
                max_profit += prices[i + 1] - prices[i];
            }
        }

        return max_profit;
    }
#pragma endregion 

#pragma region Best Time to Buy and Sell Stock III
    /// <summary>
    ///  Say you have an array for which the ith element is the price of a given stock on day i.
    ///  Design an algorithm to find the maximum profit. You may complete at most two transactions.
    ///  
    ///  Note: You may not engage in multiple transactions at the same time(ie,you must sell the stock before you buy again).
    ///  
    ///  The solution is 
    ///  1. from left to right, find the max profit for each element in the array and save in the left_maxprofit array.
    ///  2. from right to left, find the max profit for each element in the array and save in the right_maxprofit array.
    ///  Now, we have two arrays, for each element i, left_maxprofit[i] + right_maxprofit[i] is the max profit for tow transactions
    /// </summary>
    int maxProfit3(std::vector<int>& prices)
    {
        if (prices.empty())
            return 0;

        size_t n = prices.size();

        int maxProfit = 0;
        int pivot = prices[0];
        vector<int> leftProfit(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > pivot)
            {
                maxProfit = max(maxProfit, prices[i] - pivot);
            }
            else
            {
                pivot = prices[i];
            }

            leftProfit[i] = maxProfit;
        }

        maxProfit = 0;
        pivot = prices[n - 1];
        vector<int> rightProfit(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            if (prices[i] < pivot)
            {
                maxProfit = max(maxProfit, pivot - prices[i]);
            }
            else
            {
                pivot = prices[i];
            }
            rightProfit[i] = maxProfit;
        }

        maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, rightProfit[i] + leftProfit[i]);
        }

        return maxProfit;
    }
#pragma endregion


#pragma region  Best Time to Buy and Sell Stock IV
    //  Say you have an array for which the ith element is the price of a given stock on day i.
    //  Design an algorithm to find the maximum profit.You may complete at most k transactions.
    //  Thought:
    //  1. This problem is similar to painters partition problem.
    //     - we separate the input array to k sub arrays. 
    //     - We can use maxProfit1 (only 1 transaction) to get the max profit of each sub array.
    //  2. Use P(n, k) to denote the max profit of array [0...n] with at most k transactions.
    //     - If we separate the array at position i, then we have sub array [i+1, n] and the maxProfit of this sub array
    //     - so the recurrence is P(n,k) = P(i, k-1) + maxProfit(i+1, n)
    //  3. the optimal soltuion is max( P(i, k-1) + maxProfit(i+1, n)) for each 0< i <= n-1;
    namespace helper
    {
        int maxProfitInRange(const vector<int>& prices, const int start, const int end)
        {
            int maxProfit = 0;
            int pivot = prices[start];
            for (int i = start + 1; i <= end; i++)
            {
                if (prices[i] > pivot)
                {
                    maxProfit = max(maxProfit, prices[i] - pivot);
                }
                else
                {
                    pivot = prices[i];
                }
            }

            return maxProfit;
        }

        int  maxProfitRec(const vector<int>& prices, int k, int n)
        {
            if (k == 1)
                return maxProfitInRange(prices, 0, n);
            if (n == 1)
                return 0;

            int best = 0;
            for (int i = n - 2; i > 0; i--)
            {
                int rightMaxProfit = maxProfitInRange(prices, i + 1, n);
                int leftOPT = maxProfitRec(prices, k - 1, i);

                best = max(best, rightMaxProfit + leftOPT);
            }

            return best;
        }

        int  maxProfitDp(const vector<int>& prices, int k)
        {
            int n = prices.size();
            vector<vector<int>> dp(n, vector<int>(k, 0));
            dp[0][0] = 0;

            // base condition first column is the maxProfit(0...i)
            int maxProfit = 0;
            int pivot = prices[0];
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > pivot)
                {
                    maxProfit = max(maxProfit, prices[i] - pivot);
                }
                else
                {
                    pivot = prices[i];
                }

                dp[i][0] = maxProfit;
            }

            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < k; j++)
                {
                    int best = 0;
                    for (int p = 0; p < i; p++)
                    {
                        int rightMaxProfit = maxProfitInRange(prices, p, i);
                        int leftOPT = dp[p][j - 1];
                        best = max(best, rightMaxProfit + leftOPT);
                    }
                    dp[i][j] = best;
                }
            }

            return dp[n - 1][k - 1];
        }
    }
    int maxProfit4(vector<int>& prices, int k)
    {
        if (prices.size() < 2)
            return 0;

        return helper::maxProfitRec(prices, k, prices.size() - 1);
    }
#pragma endregion 
}