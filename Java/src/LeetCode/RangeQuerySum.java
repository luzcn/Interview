package LeetCode;

class RangeQuerySum
{
	private int[] totalSums;

	RangeQuerySum(int[] nums)
	{
		totalSums = new int[nums.length + 1];

		totalSums[0] = 0;
		for (int i = 1; i <= nums.length; i++)
		{
			totalSums[i] = totalSums[i - 1] + nums[i - 1];
		}
	}

	public int sumRange(int i, int j)
	{
		return totalSums[j + 1] - totalSums[i];
	}
}
