using System;

namespace InterviewPractice.LeetCode.String
{
    class LongestPalindromicSubstring
    {
        public string LongestPalindrome(string s)
        {
            var res = LongestPalindrome_DP(s);
            return res;
        }

        #region DP solution
        /// <summary>
        /// DP solution, O(n^2) time and O(n^2) space
        /// 
        /// 1. DP[i][i] = true
        /// 2. DP[i][j] = true, if DP[i+1][j-1]==true && s[i] == s[j], j-i>1
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        private string LongestPalindrome_DP(string s)
        {
            int n = s.Length;
            int begin = 0;
            int maxLen = 0;

            bool[,] DP = new bool[1000, 1000];
            for (int i = 0; i < 1000; i++)
            {
                DP[i, i] = true;
            }

            // consider the 2 contiguous characters.
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    DP[i, i + 1] = true;
                    begin = i;
                    maxLen = 2;
                }
            }

            //
            int len = 3;
            while (len <= n)
            {
                for (int i = 0; i < n - len + 1; i++)
                {
                    int j = i + len - 1;
                    if (s[i] == s[j] && DP[i + 1, j - 1] == true)
                    {
                        DP[i, j] = true;
                        begin = i;
                        maxLen = len;
                    }
                }
                len++;
            }
            return s.Substring(begin, maxLen);
        }
        #endregion

        #region Brutal Force Solution
        /// <summary>
        /// Brutral force solution
        /// O(n^3)
        /// 
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        private string LongestPalindrome_BrutalForce(string s)
        {
            string result = string.Empty;
            int n = s.Length;

            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    var sub = s.Substring(i, j - i + 1);
                    if (IsPalindrom(sub) && sub.Length > result.Length)
                    {
                        result = sub;
                    }
                }
            }
            return result;
        }

        private bool IsPalindrom(string s)
        {
            int l = 0;
            int r = s.Length - 1;

            while (l <= r)
            {
                if (s[l] != s[r])
                    return false;
                l++;
                r--;
            }

            return true;
        }
        #endregion
    }
}
