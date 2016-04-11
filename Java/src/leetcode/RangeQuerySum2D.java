/**
 * RangeQuerySum2D.java
 *
 * Nov 19, 2015
 * zhelu
 */
package leetcode;

public class RangeQuerySum2D
{
	private int[][] dp;

	// Constructor
	RangeQuerySum2D(int[][] matrix)
	{
		int m = matrix.length;
		int n = matrix[0].length;

		dp = new int[m + 1][n + 1];

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = matrix[i-1][j-1] + dp[i][j-1];
			}
		}
		
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] += dp[i - 1][j];
			}
		}
	}

	public int sumRegion(int row1, int col1, int row2, int col2)
	{
		return dp[row2+1][col2+1] - dp[row1][col1];
	}

	public static void main(String[] args)
	{
		int[][] matrix = { { 3, 0, 1, 4, 2 }, { 5, 6, 3, 2, 1 }, { 1, 2, 0, 1, 5 }, { 4, 1, 0, 1, 7 },
		        { 1, 0, 3, 0, 5 } };
		RangeQuerySum2D rq = new RangeQuerySum2D(matrix);

		System.out.println(rq.sumRegion(0,0, 1,1));
	}
}
