#pragma once

#include "stdafx.h"
#include <functional>
#include <numeric>

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
    // http://leetcode.tgic.me/best-time-to-buy-and-sell-stock-iv/index.html
    // http://blog.csdn.net/feliciafay/article/details/45128771
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
    }

    int maxProfit4DP(vector<int>& prices, int k)
    {
        if (k >= prices.size())
            return maxProfit2(prices);

        int n = prices.size();
        vector<vector<int>> history(n, vector<int>(k + 1, 0));
        vector<vector<int>> profit(n, vector<int>(k + 1, 0));

        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++)
            {
                history[i][j] = max(history[i - 1][j] + diff, profit[i - 1][j - 1]);
                profit[i][j] = max(history[i][j], profit[i - 1][j]);
            }
        }

        return profit[n - 1][k];
    }


    // O(n) solution
    int maxProfit4(vector<int>& prices, int k)
    {
        vector<int> profits;
        stack<pair<int, int>> valley_peak_stack; // valley-peak pairs

        // Step 1: find out all the possible profit
        int v = 0, p = -1;

        while (true)
        {
            // find the valley point
            v = p + 1;
            while (v < prices.size() - 1 && prices[v] >= prices[v + 1])
            {
                v++;
            }

            // find the peak point
            p = v;
            while (p < prices.size() - 1 && prices[p] <= prices[p + 1])
            {
                p++;
            }

            if (v == p)
            {
                // both valley and peak reach the end of tha array
                break;
            }

            // (v1, p1) the valley-peak pair already saved in the stack.
            // (v, p) the new valley-peak pair

            // case two: v1 >= v2  
            while (!valley_peak_stack.empty() && prices[valley_peak_stack.top().first] >= prices[v])
            {
                // no need to combine these two vally-peak pair

                // put the profit (p1 - v1)
                profits.push_back(prices[valley_peak_stack.top().second] - prices[valley_peak_stack.top().first]);

                // the valley-peak (v1, p1) has been processed, no need to keep in stack 
                valley_peak_stack.pop();
            }

            // If prices[v1] < prices[v2] and prices[p1] <= prices[p2], 
            // then it is meaningful to combine the two transactions
            // update (v1, p1) to (v1, p2), and save the profit of (v2, p1)
            while (!valley_peak_stack.empty() && prices[valley_peak_stack.top().second] <= prices[p])
            {
                profits.push_back(prices[valley_peak_stack.top().second] - prices[v]);  // (v2, p1)

                // update v2 to v1, now the pair is (v1, p2)
                v = valley_peak_stack.top().first;

                valley_peak_stack.pop();
            }

            // save the new-found valley-peak pair
            valley_peak_stack.emplace(v, p);
        }

        // save all the remaining valley-peak pairs to the profits
        while (!valley_peak_stack.empty())
        {
            profits.push_back(prices[valley_peak_stack.top().second] - prices[valley_peak_stack.top().first]);
            valley_peak_stack.pop();
        }

        // Step 2: find out the k highest profits
        int max_profit = 0;
        if (k >= profits.size())
        {
            max_profit = std::accumulate(profits.begin(), profits.end(), 0);
        }
        else
        {
            nth_element(profits.begin(), profits.begin() + k, profits.end(), std::greater<int>());
            max_profit = accumulate(profits.begin(), profits.begin() + k, 0);
        }

        return max_profit;
    }
#pragma endregion 

#pragma region Best Time to Buy and Sell Stock with Cooldown

    // dfs with memoization

    int maxProfit5(vector<int>& prices)
    {
        if (prices.size() <= 1)
            return 0;

        int n = prices.size();

        // buy[i]: the max profit till i position, the ending transaction is buy
        vector<int> buy(n, 0);

        // sell[i]: the max profit till i position, the ending transaction is sell
        vector<int> sell(n, 0);


        // buy[i]: To make a decision whether to buy at i, 
        // we either take a rest, by just using the old decision at i - 1, or sell at / before i - 2, 
        // then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.

        // sell[i] : To make a decision whether to sell at i, 
        // we either take a rest, by just using the old decision at i - 1, 
        // or buy at / before i - 1, then sell at i.

        //buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
        //sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);

        buy[0] = -prices[0];    // you can buy on first day, the profit is -prices[0]
        sell[0] = 0;            // you can not sell on first day, the profit is 0

        for (int i = 1; i < n; i++)
        {
            buy[i] = max(buy[i - 1], i >= 2 ? sell[i - 2] - prices[i] : -prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return sell[n - 1];
    }

    // O(1) space
    int maxProfit5_1(vector<int>& prices)
    {
        if (prices.size() <= 1)
            return 0;

        int n = prices.size();

        // you can buy on first day, the profit is -prices[0].
        int b0 = -prices[0];
        int b1 = b0;

        int s0 = 0, s1 = 0, s2 = 0;

        for (int i = 1; i < n; i++)
        {
            b0 = max(b1, s2 - prices[i]);
            s0 = max(s1, b1 + prices[i]);

            b1 = b0;

            s2 = s1;
            s1 = s0;
        }

        return s0;
    }
#pragma endregion
}