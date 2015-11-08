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

            permuteRec(numList, result, new List<int>());

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
                num.RemoveAt(i);
                permuteRec(num, result, current);
                num.Insert(i, current[current.Count - 1]);
                current.RemoveAt(current.Count - 1);
            }
        }
    }


    /***
     *  Given a collection of numbers that might contain duplicates, return all possible unique permutations.
        For example,
        [1,1,2] have the following unique permutations:
        [1,1,2], [1,2,1], and [2,1,1]. 
     * 
     **/
    class Permutations2
    {
        public IList<IList<int>> PermuteUnique(int[] num)
        {
            IList<IList<int>> res = new List<IList<int>>();
            List<int> numList = new List<int>();
            foreach (var i in num)
            {
                numList.Add(i);
            }
            numList.Sort();

            List<bool> isUsing = new List<bool>();
            for (int i = 0; i < num.Length; i++)
            {
                isUsing.Add(false);
            }

            PermuteUniqueRec(numList, res, new List<int>(), isUsing);

            return res;
        }

        private void PermuteUniqueSet(List<int> num, HashSet<IList<int>> result, List<int> current)
        {
            if (num.Count == 0)
            {
                result.Add(new List<int>(current));
                return;
            }

            for (int i = 0; i < num.Count; i++)
            {
                current.Add(num[i]);
                num.RemoveAt(i);
                PermuteUniqueSet(num, result, current);
                num.Insert(i, current[current.Count - 1]);
                current.RemoveAt(current.Count - 1);
            }
        }


        private void PermuteUniqueRec(List<int> numList, IList<IList<int>> sol, List<int> current, List<bool> isUsing)
        {
            if (numList.Count == 0)
            {
                sol.Add(new List<int>(current));
                return;
            }

            for (int i = 0; i < numList.Count; i++)
            {
                if (i == 0)
                {
                    current.Add(numList[i]);
                    numList.RemoveAt(i);
                    isUsing[i] = true;
                    PermuteUniqueRec(numList, sol, current, isUsing);
                    numList.Insert(i, current[current.Count - 1]);
                    current.RemoveAt(current.Count - 1);
                    isUsing[i] = false;
                }
                else
                {
                    if (isUsing[i - 1] == false && numList[i - 1] == numList[i])
                        continue;

                    current.Add(numList[i]);
                    numList.RemoveAt(i);
                    isUsing[i] = true;
                    PermuteUniqueRec(numList, sol, current, isUsing);
                    numList.Insert(i, current[current.Count - 1]);
                    current.RemoveAt(current.Count - 1);
                    isUsing[i] = false;
                }
            }
        }
    }
}
