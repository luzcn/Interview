// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\Triangle.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    vector<vector<int>> triangle{
        { -1 },
        { 2, 3 },
        { 1, -1, -3 },
    };

    cout << Triangle::minimumTotal(triangle) << endl;
    return 0;
}