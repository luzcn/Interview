using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class BasicCalculator
    {
        public int calculte(string s)
        {
            Stack<int> ops = new Stack<int>();
            ops.Push(1);
            ops.Push(1);

            int i = 0;
            int res = 0;
            while (i < s.Length)
            {
                if (Char.IsDigit(s[i]))
                {
                    int num = 0;
                    while (i < s.Length && Char.IsDigit(s[i]))
                    {
                        num = num * 10 + s[i] - '0';
                        i++;
                    }

                    res += num * ops.Pop();
                }
                else if (s[i] == '+' || s[i] == '(')
                {
                    ops.Push(ops.Peek());
                    i++;
                }
                else if (s[i] == '-')
                {
                    ops.Push(-1 * ops.Peek());
                    i++;
                }
                else if (s[i] == ')')
                {
                    ops.Pop();
                    i++;
                }
                else
                    i++;

            }

            return res;
        }

    }
}
