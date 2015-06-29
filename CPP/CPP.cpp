// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DesignPattern\Singleton.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    auto& p = DesignPattern::SingletonObject::getInstance();
    return 0;
}