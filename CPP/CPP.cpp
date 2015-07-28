// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CareerCup\PatternMatching.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
    cout << careercup::KMP::kmp("bbabaabcdaab", "abaab");
    return 0;
}