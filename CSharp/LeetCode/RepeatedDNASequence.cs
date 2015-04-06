using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace CSharp.LeetCode
{
    class RepeatedDNASequence
    {

        private long strTolong(string s)
        {
            long res = 0;
            for (int i = 0; i < 10; i++)
            {
                if (s[i] == 'A')
                {
                    res = res * 10 + 1;
                }
                if (s[i] == 'C')
                {
                    res = res * 10 + 2;
                }
                if (s[i] == 'T')
                {
                    res = res * 10 + 3;
                }
                if (s[i] == 'G')
                {
                    res = res * 10 + 4;
                }
            }

            return res;
        }

        private string longTostr(long s)
        {
            string res = string.Empty;
            for (int i = 0; i < 10; i++)
            {
                var d = s % 10;
                if (d == 1)
                    res = "A" + res;
                if (d == 2)
                    res = "C" + res;
                if (d == 3)
                    res = "T" + res;
                if (d == 4)
                    res = "G" + res;

                s = s / 10;
            }

            return res;
        }
        public IList<string> FindRepeatedDnaSequences(string s)
        {
            Dictionary<long, int> map = new Dictionary<long, int>();
            int n = s.Length;

            for (int i = 0; i < n - 9; i++)
            {
                var sub = s.Substring(i, 10);
                var value = strTolong(sub);
                if (map.ContainsKey(value))
                {
                    map[value]++;
                }
                else
                {
                    map.Add(value, 1);
                }
            }

            IList<string> res = new List<string>();

            foreach (var p in map)
            {
                if (p.Value > 1)
                {
                    var str = longTostr(p.Key);
                    res.Add(str);
                }
            }

            return res;
        }
    }
}
