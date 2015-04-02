using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{

    class BestTimeToBuyAndSellStock
    {
        /***
            Say you have an array for which the ith element is the price of a given stock on day i.

            If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
            design an algorithm to find the maximum profit.
        ***/
        public int MaxProfit1(int[] p)
        {
            int maxProfit = 0;
            if (p.Length <= 1)
                return 0;

            int current = p[0];

            for (int i = 1; i < p.Length; i++)
            {
                if (p[i] > current)
                {
                    var profit = p[i] - current;
                    maxProfit = Math.Max(maxProfit, profit);
                }
                else
                {
                    current = p[i];
                }
            }
            return maxProfit;
        }


        /***
            Say you have an array for which the ith element is the price of a given stock on day i.

            Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
            (ie, buy one and sell one share of the stock multiple times). 
            
            However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
        ***/
        public int MaxProfit2(int[] p)
        {
            // the solution is finding the contiguous increasing subarray.
            int maxProfit = 0;
            int n = p.Length;
            for (int i = 0; i < n - 1; i++)
            {
                if (p[i + 1] > p[i])
                {
                    maxProfit += p[i + 1] - p[i];
                }
            }

            return maxProfit;
        }


        /***
            Say you have an array for which the ith element is the price of a given stock on day i.

            Design an algorithm to find the maximum profit. You may complete at most two transactions.

            You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

            The solution is 1. from left to right, find the max profit for each element in the array and save in the left_maxprofit array.
            2. from right to left, find the max profit for each element in the array and save in the right_maxprofit array.
            Now, we have two arrays, for each element i, left_maxprofit[i] + right_maxprofit[i] is the max profit for tow transactions
        ***/


        public int MaxProfit3(int[] p)
        {
            int totalMaxProfit = 0;
            int n = p.Length;

            // from left to right, compute max profit for each element.
            int[] left_maxprofit = new int[n];
            int min = p[0];
            int current_maxprofit = 0;
            for (int i = 1; i < n; i++)
            {
                if (p[i] < min)
                {
                    min = p[i];
                }
                else
                {
                    current_maxprofit = Math.Max(current_maxprofit, p[i] - min);
                }
                left_maxprofit[i] = current_maxprofit;
            }


            // from right to left, find the max profit for each elements.
            int max = p[n - 1];
            current_maxprofit = 0;
            int[] right_maxprofit = new int[n];
            for (int i = n -2; i>=0;i--)
            {
                if (p[i] > max)
                {
                    max = p[i];
                }
                else
                {
                    current_maxprofit = Math.Max(current_maxprofit, max - p[i]);
                }
                right_maxprofit[i] = current_maxprofit;
            }

            for (int i = 0; i < n; i++)
            {
                if (left_maxprofit[i] + right_maxprofit[i] > totalMaxProfit)
                {
                    totalMaxProfit = left_maxprofit[i] + right_maxprofit[i];
                }
            }
            return totalMaxProfit;
        }
    }
}
