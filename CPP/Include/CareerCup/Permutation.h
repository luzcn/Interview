#pragma  once
#include "stdafx.h"

/***
 *	string permutation
 *
 *	The solution is recursive,
 *	- if there is only one character, then return.
 *	- if there are more than 1 character, take the first character,
 *	  then insert this character into the substring in all the possible positions.
 *
 *	  e.g. c => c
 *	  bc => bc, cb
 *	  abc => take "a" out, we have "bc", "cb" as the substrings. insert "a" into the substrings in all the possible positions.
 *	  so => abc, bac, bca, acb, cab, cba.
 */
namespace StringPermutation
{
    using namespace std;

    vector<string> stringPermutationRec(string s)
    {
        vector<string> permutations;
        
        if (s.empty())
        {
            permutations.push_back("");
            return permutations;
        }

        auto first = s.substr(0, 1);
        auto result = std::move(stringPermutationRec(s.substr(1)));

        for (auto word : result)
        {
            for (int i = 0; i <= word.size(); ++i)
            {
                auto prefix = word.substr(0, i);
                auto sufix = word.substr(i);

                permutations.push_back(prefix.append(first).append(sufix));
            }
        }
        return permutations;
    }
}

/***
 *	The set [1,2,3,?n] contains a total of n! unique permutations.

    By listing and labeling all of the permutations in order,
    We get the following sequence (ie, for n = 3):

        "123"
        "132"
        "213"
        "231"
        "312"
        "321"

    Given n and k, return the kth permutation sequence.

    Note: Given n will be between 1 and 9 inclusive.
 */
namespace PermutationSequence
{
    using namespace std;

    void getPermutationRec(vector<int>& list, vector<vector<int>>& solution, vector<int>& current, int index)
    {
        if (list.empty())
        {
            solution.push_back(current);
            return;
        }

        for (int i = index; i < list.size(); ++i)
        {
            current.push_back(list[i]);
            list.erase(list.begin() + i);
            getPermutationRec(list, solution, current, index);
            list.insert(list.begin() + i, current.back());
            current.pop_back();
        }
    }

    vector<vector<int>> getPermutation(int n, int k)
    {
        vector<int> list;
        for (int i = 1; i <= n; ++i)
        {
            list.push_back(i);
        }

        vector<vector<int>> solution;
        vector<int> current;

        getPermutationRec(list, solution, current, 0);

        return solution;
    }
}