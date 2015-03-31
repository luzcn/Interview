#pragma once
#include "stdafx.h"
#include <unordered_set>

namespace WordBreak2
{
    using namespace std;

#if 0   // not validated solution
    void breakRec(string s, unordered_set<string>& dict, vector<vector<string>>& sol, vector<string>& cur)
    {
        if (dict.find(s) != dict.end())
        {
            cur.push_back(s);
            return;
        }

        for (int i = 1; i <= s.size(); ++i)
        {
            auto prefix = s.substr(0, i);
            if (dict.find(prefix) != dict.end())
            {
                cur.push_back(prefix);
                breakRec(s.substr(i), dict, sol, cur);
                sol.push_back(cur);
                cur.clear();
            }
        }

    }

    vector<vector<string>> wordbreak(string s, unordered_set<string>& dict)
    {
        vector<vector<string>> sol;
        vector<string> prefix;

        breakRec(s, dict, sol, prefix);

        return sol;
    }
#endif

    /***
     *	Recursive bruteforce solution
     *	
     */
    void GetAllSolution(int start, const string& s, const unordered_set<string> &dict, int len, string& result, vector<string>& solutions)
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

    /***
     *	using the DP idea to prune unnecessary computations.
     */
    void GetAllSolution2(int start, const string& s, const unordered_set<string> &dict, int len,
        string& result, vector<string>& solutions, vector<bool>& possible)
    {
        if (start == len)
        {
            solutions.push_back(result.substr(0, result.size() - 1));  // eliminate the last redundant space.
            return;
        }

        for (int i = start; i < len; ++i)
        {
            auto prefix = s.substr(start, i - start + 1);

            if (dict.find(prefix) != dict.end() && possible[i+1])
            {
                result.append(prefix).append(" ");
                int beforeChange = solutions.size();
                GetAllSolution(i + 1, s, dict, len, result, solutions);
                if (solutions.size() == beforeChange)
                {
                    possible[i + 1] = false; // if no solution, set the possibility to false.
                }
                result.resize(result.size() - prefix.size() - 1);
            }
        }
    }
    vector<string> wordbreak(string s, unordered_set<string>& dict)
    {
        vector<string> sol;
        string result("");
        vector<bool> possible(s.size() + 1, true);


        GetAllSolution2(0, s, dict, s.size(), result, sol, possible);

        return sol;
    }
}

#if 0
int _tmain(int argc, _TCHAR* argv [])
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