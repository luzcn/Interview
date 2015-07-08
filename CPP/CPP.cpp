// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DesignPattern\Observer.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    int n = 2;

    printf("%d", n&(n - 1));
    return 0;
}