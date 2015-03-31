using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /***
         Given a collection of numbers, return all possible permutations.

        For example,
        [1,2,3] have the following permutations:
        [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
    ***/
    class Permutations
    {
        public IList<IList<int>> Permute(int[] num)
        {
            IList<IList<int>> result = new List<IList<int>>();
            List<int> numList = new List<int>();
            foreach (var i in num)
            {
                numList.Add(i);
            }

            permuteRec(numList, result, new List<int>(), 0);

            return result;
        }

        private void permuteRec(List<int> num, IList<IList<int>> result, List<int> current)
        {
            if (num.Count == 0)
            {
                result.Add(new List<int>(current));
                return;
            }

            for (int i = 0; i < num.Count; i++)
            {
                current.Add(num[i]);
                num.Remove(i);
                permuteRec(num, result, current);
                num.Insert(i, current[current.Count - 1]);
                current.Remove(current.Count - 1);
            }
        }
    }
}
