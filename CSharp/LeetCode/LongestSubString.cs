using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class LongestSubString
    {
        /// <summary>
        /// Given a string, find the length of the longest substring without repeating characters. 
        /// 
        /// Tow pointers solution.
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public int longestSubStringWithoutRepeatChars(string s)
        {
            if (s.Length < 2)
                return s.Length;
            int maxLen = 1;
            int start = 0;

            Dictionary<char, int> map = new Dictionary<char, int>();

            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (map.ContainsKey(c) && start <= map[c])
                {
                    start = map[c] + 1;
                }

                map[c] = i;
                maxLen = Math.Max(maxLen, i - start + 1);
            }

            return maxLen;
        }

        /// <summary>
        ///  Given a string, find the length of the longest substring T that contains at most 2 distinct characters. 
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public int LongestSubstringwithAtMosTwoUniqueChars(string s)
        {
            if (s.Length < 2)
                return s.Length;
            int start = 0;
            int maxLen = 0;
            Dictionary<char, int> map = new Dictionary<char, int>();

            for (int i = 0; i < s.Length; i++)
            {
                char c = s[i];
                if (map.Count == 2 && !map.ContainsKey(c))
                {
                    int leftMost = map.OrderBy(pair => pair.Value).First().Value;

                    start = leftMost + 1;
                    map.Remove(s[leftMost]);
                }

                map[c] = i;
                maxLen = Math.Max(maxLen, i - start + 1);
            }

            return maxLen;
        }
    }
}
