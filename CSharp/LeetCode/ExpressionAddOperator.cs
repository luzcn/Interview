using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class ExpressionAddOperator
    {
        public IList<string> AddOperators(string num, int target)
        {
            IList<string> result = new List<string>();
            addOperatorDFS(num, target, result, 0, 0, "");

            return result;
        }

        private void addOperatorDFS(string num, int target, IList<string> result,
            long diff, long currentValue, string expression)
        {
            if (num.Length == 0 && currentValue == target)
            {
                result.Add(expression);
                return;
            }

            for (int i = 0; i < num.Length; i++)
            {
                string prefix = num.Substring(0, i + 1);
                string last = num.Substring(i + 1);
                if (prefix.Length > 1 && prefix[0] == '0')
                    return;

                if (expression.Length == 0)
                {
                    addOperatorDFS(last, target, result, Convert.ToInt64(prefix), Convert.ToInt64(prefix), prefix);
                }
                else
                {
                    // + operator
                    addOperatorDFS(last, target, result, Convert.ToInt64(prefix), currentValue + Convert.ToInt64(prefix), expression + "+" + prefix);
                    addOperatorDFS(last, target, result, -Convert.ToInt64(prefix), currentValue - Convert.ToInt64(prefix), expression + "-" + prefix);
                    addOperatorDFS(last, target, result, diff * Convert.ToInt64(prefix), (currentValue - diff) + diff * Convert.ToInt64(prefix), expression + "*" + prefix);
                }
            }
        }
    }
}
