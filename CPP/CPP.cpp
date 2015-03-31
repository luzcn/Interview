// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\HouseRobber.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    vector<int> num = { 2,1,4 };
    cout << HouseRobber::rob(num);
	return 0;
}

