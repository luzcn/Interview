using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InterviewPractice.LeetCode
{
    class AddBinary
    {
        public string add(string a, string b)
        {
            string res = string.Empty;
            int carry = 0;
            int i = a.Length - 1;
            int j = b.Length - 1;

            while (i >= 0 && j >= 0)
            {
                var va = a[i] - '0';
                var vb = b[i] - '0';
                res = (va + vb + carry) % 2 + res;
                carry = (va + vb + carry) / 2;
                i--;
                j--;
            }

            while (i >= 0)
            {
                var va = a[i] - '0';
                res = (va + carry) % 2 + res;
                carry = (va + carry) / 2;
                i--;
            }

            while (j >= 0)
            {
                var vb = b[j] - '0';
                res = (vb + carry) % 2 + res;
                carry = (vb + carry) / 2;
                j--;
            }
            if (carry == 1)
                res = "1" + res;

            return res;
        }
    }
}
