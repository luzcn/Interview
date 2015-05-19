// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\SudokuSolver.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<string> input = {
        "..4...63.", 
        ".........", 
        "5......9.", 
        "...56....", 
        "4.3.....1", 
        "...7.....", 
        "...5.....", 
        ".........", 
        "........."
    };

    cout << SudokuSolver::valid(input, 0, 7, 2) << endl;
    return 0;
}