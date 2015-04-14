// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\DungeonGame.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<vector<int>> grid = {
        { -2, -3, 3 },
        { -5, -10, 1 },
        { 10, 30, -5 }
    };

    cout << DungeonGame::calculateMinimumHP(grid);
    return 0;
}

