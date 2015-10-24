#pragma once
#include "stdafx.h"

namespace leetcode
{
    // l: the number of "("
    // r: the number of ")"
    void generateRec(int l, int r, vector<string>& result, string current)
    {
        // find one valid string
        if (l == 0 && r == 0)
        {
            result.push_back(current);
            return;
        }

        // if l == 0, it means finished insert all the "(", cannot insert anymore.
        if (l > 0)
            generateRec(l - 1, r, result, current + "(");

        // we can only insert ")" when the generated string has more "(" than ")"
        if (r > l)
            generateRec(l, r - 1, result, current + ")");
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current = "";

        generateRec(n, n, result, current);

        return result;
    }
}