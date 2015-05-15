// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\SurroundedRegions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<vector<char>> board{
        { 'x', 'x', 'x', 'x' },
        { 'x', 'O', 'O', 'x' },
        { 'x', 'x', 'O', 'X' },
        { 'x', 'O', 'x', 'x' },
    };

    //vector<vector<char>> board{
    //    { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' }
    //};
    
    SurroundedRegions::solve(board);
    return 0;
}

