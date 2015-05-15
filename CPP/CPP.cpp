// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\SurroundedRegions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    //vector<vector<char>> board{
    //    { 'x', 'x', 'x', 'x' },
    //    { 'x', 'O', 'O', 'x' },
    //    { 'x', 'x', 'O', 'X' },
    //    { 'x', 'O', 'x', 'x' },
    //};

    //vector<vector<char>> board{
    //    { 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}
    //};
    string s = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXO";
    vector<vector<char>> board;
    vector<char> t;

    for (int i = 0; i < s.size(); i++)
    {
        t.push_back(s[i]);
    }
    board.push_back(t);

    SurroundedRegions::solve(board);
    return 0;
}