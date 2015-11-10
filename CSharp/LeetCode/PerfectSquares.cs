using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class PerfectSquares
    {
        public int NumSquares(int n)
        {
            if (isPerfectSquare(n))
                return 1;

            Queue<int> que = new Queue<int>();
            Queue<int> que_temp = new Queue<int>();
            que.Enqueue(n);
            int distance = 0;

            while (que.Count > 0)
            {
                int current = que.Dequeue();

                for (int i = 1; i <= current / 2; i++)
                {
                    if (isPerfectSquare(i) && isPerfectSquare(current - i))
                    {
                        return distance + 2;
                    }
                    else if (isPerfectSquare(i))
                    {
                        que_temp.Enqueue(current - i);
                    }
                }

                if (que.Count == 0)
                {
                    distance++;
                    que = que_temp;
                    que_temp = new Queue<int>();
                }
            }

            return 0;
        }

        private bool isPerfectSquare(int n)
        {
            int sq = (int) Math.Sqrt(n);
            if (sq * sq == n)
            {
                return true;
            }

            return false;
        }
    }
}
