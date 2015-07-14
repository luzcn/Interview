// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\MajorityElement2.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    vector<int> v{ -1, 1, 1, 2, 1, 4, 5, 6 };
    leetcode::majority2(v);

    return 0;
}