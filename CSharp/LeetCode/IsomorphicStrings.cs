using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class IsomorphicString
    {
        public bool IsIsomorphic(string s, string t)
        {
            if (s.Length != t.Length)
                return false;

            Dictionary<char, char> map = new Dictionary<char, char>();

            for (int i = 0; i < s.Length; i++)
            {
                char cs = s[i];
                char ct = t[i];

                if (map.ContainsKey(cs))
                {
                    if (map[cs] != ct)
                        return false;
                }
                else
                    map.Add(cs, ct);
            }

            return true;
        }
    }
}
