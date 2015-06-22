// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\BasicCalculator.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    cout << 2 - (3 + 5) * 2 / (3 + 4) - 10 << endl;
    cout << leetcode::calculate3("2-(3+5)*2/(3+4) - 10*(2)") << endl;
    return 0;
}