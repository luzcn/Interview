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
        void subsetsWithDup_rec(
            vector<int>& nums,
            vector<vector<int>>& res,
            vector<int>& current,
            vector<bool>& visited, int index)
        {
            res.push_back(current);

            for (int i = index; i < nums.size(); i++)
            {
                if (!visited[i])
                {
                    if (i != index && nums[i - 1] == nums[i] && !visited[i - 1])
                    {
                        continue;
                    }

                    visited[i] = true;
                    current.push_back(nums[i]);
                    subsetsWithDup_rec(nums, res, current, visited, i + 1);
                    current.pop_back();
                    visited[i] = false;
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
            std::vector<bool> visited(S.size(), false);

            details::subsetsWithDup_rec(S, solution, std::vector<int>(), visited, 0);

            return solution;
        }
    }

}