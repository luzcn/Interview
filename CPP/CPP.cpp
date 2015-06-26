// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CareerCup\ClosestPairs.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    vector<Point> p{ { 2, 3 }, { 12, 30 }, { 40, 50 }, { 5, 1 }, { 12, 10 }, { 3, 4 } };
    cout << careercup::closestPair(p) << endl;

    return 0;
}