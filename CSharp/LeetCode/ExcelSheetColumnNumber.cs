using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice.LeetCode
{
    class ExcelSheetColumnNumber
    {
        public int TitleToNumber(string s)
        {
            int res = 0;
            for (int i = 0; i < s.Length; i++)
            {
                res += System.Convert.ToInt32((s[i] - 'A' + 1));
            }
            return res;
        }
    }
}
