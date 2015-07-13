// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CareerCup\FindKthSmallest.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    vector<int> v{ 2, 3234, 43, 234, 4, 657, 2, 1234, 568, 89 };
    cout << careercup::findKthSmallest(v, 7);

    return 0;
}