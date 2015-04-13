// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CareerCup\FloodFill.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<vector<int>> grid = {
        { 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 0, 0, 1, 1, 0, 1, 1 },
        { 1, 2, 2, 2, 2, 0, 1, 0 },
        { 1, 1, 1, 2, 2, 0, 1, 0 },
        { 1, 1, 1, 2, 2, 2, 2, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 1 },
        { 1, 1, 1, 1, 1, 2, 2, 1 },
    };

    FloodFill::flood_fill(grid, 3, 3, 2, 3);

    for (auto i : grid)
    {
        for (auto t : i)
        {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}

