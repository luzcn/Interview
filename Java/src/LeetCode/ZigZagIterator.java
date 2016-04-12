package LeetCode;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class ZigZagIterator
{
	// Member fields
	private Queue<Iterator<Integer>> que = new LinkedList<Iterator<Integer>>();

	public ZigZagIterator(List<Integer> v1, List<Integer> v2)
	{
		if (!v1.isEmpty())
		{
			que.add(v1.iterator());
		}

		if (!v2.isEmpty())
		{
			que.add(v2.iterator());
		}
	}

	public boolean hasNext()
	{
		return !que.isEmpty();
	}

	public int next()
	{
		Iterator<Integer> it = que.poll();
		int result = it.next();
		if (it.hasNext())
		{
			que.add(it);
		}

		return result;
	}

}
