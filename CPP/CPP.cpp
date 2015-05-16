// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\SudokuSolver.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<string> input = {
        "..5..7.13",
        "3.2......",
        "....8..9.",
        ".........",
        "5..6..4..",
        "....9...4",
        "..4..5...",
        ".5...8...",
        "........9"
    };

    cout << SudokuSolver::valid(input, 0, 0, 2);

    return 0;
}