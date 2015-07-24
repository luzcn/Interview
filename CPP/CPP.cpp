// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\ContainsDuplicate.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
    //[-1,-1], 1, -1
    vector<int> v{ 7,1,3 };
    cout << leetcode::containsNearbyAlmostDuplicate(v,2,3);

    return 0;
}