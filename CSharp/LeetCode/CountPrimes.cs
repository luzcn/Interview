using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class CountPrimes
    {
        public int count(int n)
        {
            int count = 0;
            Boolean[] is_prime = new Boolean[n + 1];
            for (int i = 0; i <= n; i++)
            {
                is_prime[i] = true;
            }

            for (int i = 2; i < n; i++)
            {
                if (is_prime[i])
                {
                    count++;
                    for (int j = i*2; j < n; j += i)
                    {
                        is_prime[j] = false;
                    }
                }
            }
            return count;
        }
    }
}
