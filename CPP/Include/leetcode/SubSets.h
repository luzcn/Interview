#pragma once
#include "stdafx.h"

namespace SubSets
{
    namespace details
    {
        /// <summary>
        ///  The recursive helper function.
        /// </summary>
        /// <param name=""> </param>
        /// <returns> </return>
        void power_set(const std::vector<int>& S, std::vector<std::vector<int>>& solution, 
            std::vector<int>& current_list, size_t index)
        {
            solution.push_back(current_list);

            if (index >= S.size())  // This is statement is useless.
                return;

            for (size_t i = index; i < S.size(); ++i)
            {
                current_list.push_back(S[i]);
                power_set(S, solution, current_list, i + 1);
                current_list.pop_back();
            }
        }


        /// <summary>
        ///  The recursive helper function.
        /// </summary>
        /// <param name=""> </param>
        /// <returns> </return>
        void subsetsWithDup_rec(const std::vector<int>& S, std::vector<std::vector<int>>& solution, 
            std::vector<int>& current_list, std::vector<bool>& can_use, size_t index)
        {
            solution.push_back(current_list);

            for (size_t i = index; i < S.size(); ++i)
            {
                if (i == 0)
                {
                    can_use[i] = false;
                    current_list.push_back(S[i]);
                    subsetsWithDup_rec(S, solution, current_list, can_use, i + 1);
                    current_list.pop_back();
                    can_use[i] = true;
                }
                else
                {
                    if (S[i - 1] == S[i] && can_use[i -1])
                        continue;

                    can_use[i] = false;
                    current_list.push_back(S[i]);
                    subsetsWithDup_rec(S, solution, current_list, can_use, i + 1);
                    current_list.pop_back();
                    can_use[i] = true;
                }
            }
        }
    }

    /// <summary>
    ///  Find the all the subset of a given set.
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    std::vector<std::vector<int>> subsets(std::vector<int>& S)
    {
        std::vector<std::vector<int>> solution;

        details::power_set(S, solution, std::vector<int>(), 0);

        return solution;
    }

    /***
    * Given a collection of integers that might contain duplicates, S, return
    * all possible subsets.
    *
    * Note:
    *
    * Elements in a subset must be in non-descending order. The solution set
    * must not contain duplicate subsets.
    *
    * For example, If S = [1,2,2], a solution is:
    *
    * [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
    *
    */
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &S) 
    {
        std::vector<std::vector<int>> solution;
        std::vector<bool> can_use(S.size());

        details::subsetsWithDup_rec(S, solution, std::vector<int>(), can_use, 0);

        return solution;
    }
}

#if 0
int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<int> v = { 1, 2, 3 };

    auto result = SubSets::subsets(v);
    for (auto v : result)
    {
        std::cout << "[";
        for (auto t : v)
        {
            std::cout << t << ",";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
#endif