// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\ContainsDuplicate.h"

using namespace std;
bool isValid(vector<int> current, int r)
{
    for (int i = 0; i < r; i++)
    {
        if (current[i] == current[r]) // in same row
            return false;

        if (abs(current[i] - current[r]) == abs(i - r))
            return false;
    }
    return true;
}
void solve(vector<vector<int>>& res, vector<int> current, int col, int n)
{
    if (col == n)
    {
        res.push_back(current);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        current[col] = i;
        if (isValid(current, col))
        {
            solve(res, current, col + 1, n);
        }
    }
}

vector<vector<int>> solveQueen(int n)
{
    vector<vector<int>> res;
    vector<int> current(n);
    solve(res, current, 0, n);
    return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
    solveQueen(4);
    return 0;
}