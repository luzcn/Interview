// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DesignPattern\Observer.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv [])
{
    using namespace DesignPattern;
    Provider<int> p;
    Reporter<int> r1("reporter1");
    Reporter<int> r2("reporter2");
    Reporter<int> r3("reporter3");

    p.Register(&r1);
    p.Register(&r2);
    p.Register(&r3);

    p.Update(2);

    p.Unregister(&r2);

    p.Update(3);
    return 0;
}