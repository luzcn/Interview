#pragma once
#include "stdafx.h"

// partition a string to k strings
// "abcd", partition to 3 strings, => a|b|cd, a|bc|d, ab|c|d
namespace careercup
{
    void partition(int start, const string& s, string& result, vector<string>& solutions, int k)
    {
        if (k == 0)
        {
            result.append(s.substr(start));
            solutions.push_back(result);
            result = result.substr(0, result.size() - s.substr(start).size());
            return;
        }

        for (int i = start; i < s.size() - 1; i++)
        {
            auto prefix = s.substr(start, i - start + 1);
            result.append(prefix).append("|");
            partition(i + 1, s, result, solutions, k - 1);
            result = result.substr(0, result.size() - prefix.size() - 1);
        }
    }


}

#if 0
int main(int argc, char** args)
{
    vector<string> res;
    string str = "abcdefg";
    string current = "";
    partition(0, str, current, res, 2);

    return 0;
}
#endif