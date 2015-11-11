using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
// There are a row of n houses, each house can be painted with one of the three colors: red, blue or green.
// The cost of painting each house with a certain color is different.
//
// You have to paint all the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
// For example, costs[0][0] is the cost of painting house 0 with color red; 
// costs[1][2] is the cost of painting house 1 with color green, and so on...Find the minimum cost to paint all houses.


namespace CSharp.LeetCode
{
    public class PaintHouse
    {
        public int minCost(int[,] costs)
        {
            return minCostDP(costs);
        }

        private int minCostDP(int[,] costs)
        {
            if (costs.GetLength(0) == 0)
                return 0;

            int n = costs.GetLength(0);
            int[] dp = new int[3];

            for (int i = 0; i < 3; i++)
            {
                dp[i] = costs[0, i];
            }

            for (int i = 1; i < n; i++)
            {
                int value0 = Math.Min(dp[1], dp[2]) + costs[i, 0];
                int value1 = Math.Min(dp[0], dp[2]) + costs[i, 1];
                int value2 = Math.Min(dp[0], dp[1]) + costs[i, 2];

                dp[0] = value0;
                dp[1] = value1;
                dp[2] = value2;
            }

            return dp.Min();
        }

        private int minCostKColors(int[,] costs, int k)
        {
            if (costs.GetLength(0) == 0)
                return 0;

            int n = costs.GetLength(0);

            int[] dp = new int[k];
            int min1 = Int32.MaxValue;  // the smallest element in dp array
            int min2 = Int32.MaxValue;  // the second smallest.
            for (int i = 0; i < k; i++)
            {
                dp[i] = costs[0, i];
                if (dp[i] < min1)
                {
                    min2 = min1;
                    min1 = dp[i];
                }
                else if (dp[i] < min2)
                {
                    min2 = dp[i];
                }
            }

            for (int i = 1; i < n; i++)
            {
                int currentMin1 = int.MaxValue;
                int currentMin2 = int.MaxValue;

                for (int j = 0; j < k; j++)
                {
                    if (dp[j] == min1)
                    {
                        dp[j] = min2 + costs[i, j];
                    }
                    else
                    {
                        dp[j] = min1 + costs[i, j];
                    }

                    if (dp[j] < currentMin1)
                    {
                        currentMin2 = currentMin1;
                        currentMin1 = dp[j];
                    }
                    else if (dp[j] < currentMin2)
                    {
                        currentMin2 = dp[j];
                    }
                }

                min1 = currentMin1;
                min2 = currentMin2;
            }

            return dp.Min();
        }
        /// <summary>
        /// dfs solution, need to call 3 time for k = 0, 1, 2 and returm min of these 3 results.
        /// </summary>
        /// <param name="costs"></param>
        /// <param name="n"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        private int dfs(int[,] costs, int n, int k)
        {
            if (n == 0)
                return costs[0, k];

            if (k == 0)
            {
                return Math.Min(dfs(costs, n - 1, 1), dfs(costs, n - 1, 2)) + costs[n, k];
            }
            else if (k == 1)
            {
                return Math.Min(dfs(costs, n - 1, 0), dfs(costs, n - 1, 2)) + costs[n, k];
            }
            else
            {
                return Math.Min(dfs(costs, n - 1, 0), dfs(costs, n - 1, 1)) + costs[n, k];
            }
        }
    }
}
