#pragma once

#include "stdafx.h"


namespace BestTimeToBuyAndSellStock
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
        for (size_t i = 0; i < n -1; ++i)
        {
            if (prices[i] < prices[i + 1])
            {
                max_profit += prices[i + 1] - prices[i];
            }
        }

        return max_profit;
    }

    /// <summary>
    ///  Say you have an array for which the ith element is the price of a given stock on day i.
    ///  Design an algorithm to find the maximum profit. You may complete at most two transactions.
    ///  
    ///  Note: You may not engage in multiple transactions at the same time(ie,you must sell the stock before you buy again).
    ///  
    ///  The solution is 1. from left to right, find the max profit for each element in the array and save in the left_maxprofit array.
    ///  2. from right to left, find the max profit for each element in the array and save in the right_maxprofit array.
    ///  Now, we have two arrays, for each element i, left_maxprofit[i] + right_maxprofit[i] is the max profit for tow transactions
    /// </summary>
    int maxProfit3(std::vector<int>& p)
    {
        if (p.empty())
            return;

        size_t n = p.size();

        std::vector<int> left_maxprofit_list(n);
        std::vector<int> right_maxprofit_list(n);

        // construct the left max profit array
        int left_min= p[0];
        int left_maxprofit = 0;
        for (size_t i = 0; i < n - 1; ++i)
        {
            if (p[i] < left_min)
            {
                left_min = p[i];
            }
            else
            {
                auto profit = p[i] - left_min;
                if (profit > left_maxprofit)
                {
                    left_maxprofit = profit;
                }
            }
            left_maxprofit_list[i] = left_maxprofit;
        }

        // construct the right max profit array
        int righ_max = p[n - 1];
        int righ_maxprofit = 0;
        for (size_t i = n - 1; n > 0; --n)
        {

        }
    }
}