#pragma once
#include "stdafx.h"
#include <unordered_set>

namespace leetcode
{
    // dfs brute force solution, O(2^n) time
    void GetAllSolution(int start, const string& s, const unordered_set<string> &dict,
        int len, string& result, vector<string>& solutions)
    {
        if (start == len)
        {
            solutions.push_back(result.substr(0, result.size() - 1));
            return;
        }

        for (int i = start; i < len; ++i)
        {
            auto prefix = s.substr(start, i - start + 1);

            if (dict.find(prefix) != dict.end())
            {
                result.append(prefix).append(" ");
                GetAllSolution(i + 1, s, dict, len, result, solutions);
                result.resize(result.size() - prefix.size() - 1);
            }
        }
    }

    // use the DP idea to prune unnecessary computations.
    void dfs(string& s, unordered_set<string>& dict, vector<string>& result,
            string& current, vector<bool>& possible, int start)
    {
        if (start >= s.size())
        {
            // use "current.substr" here, we should not modify "current", here
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            string prefix = s.substr(start, i - start + 1);

            if (dict.find(prefix) != dict.end() && possible[i + 1])
            {
                current.append(prefix).append(" ");
                int sizeBeforeChange = result.size();

                dfs(s, dict, result, current, possible, i + 1);

                current.resize(current.size() - prefix.size() - 1);

                if (result.size() == sizeBeforeChange)  
                {
                    // the "result" size does not chage, no solution found
                    // set the possible[i + 1] as false
                    possible[i + 1] = false;
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& dict)
    {
        vector<string> result;
        string current("");
        vector<bool> possible(s.size() + 1, true);  // the size if the input string length + 1


        dfs(s, dict, result, current, possible, 0);

        return result;
    }
}

#if 0
int _tmain(int argc, _TCHAR* argv[])
{
    unordered_set<string> dict = { "cats", "and", "dog", "cat", "sand" };

    string s("catsanddog");

    auto t = WordBreak2::wordbreak(s, dict);
    for (auto v : t)
    {
        cout << v << endl;
    }
    return 0;
}
#endif