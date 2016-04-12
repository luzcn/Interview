package LeetCode;

import java.util.ArrayList;

public class MaxProductOfWordLengths
{
	public int maxProduct(String[] words)
	{
		int result = 0;
		ArrayList<Integer> elements = new ArrayList<Integer>();
		int n = words.length;

		for (int i = 0; i < n; i++)
		{
			int ele = 0;
			for (int j = 0; j < words[i].length(); j++)
			{
				ele |= 1 << (Character.getNumericValue(words[i].charAt(j)));
			}
			elements.add(ele);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((elements.get(i) & elements.get(j)) == 0)
				{
					result = Math.max(result, words[i].length() * words[j].length());
				}
			}
		}
		return result;

	}

	public static void main(int argc, String[] args)
	{
		String[] words = {"te","etw"};
		String test = new String("tewtrwer");
		
		System.out.println(test.length());
		System.out.println(words.length);
	}
}
