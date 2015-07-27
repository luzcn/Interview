// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\PopulatingNextRightNodeInEachNode.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

    auto n0 = leetcode::TreeLinkNode(0);
    auto n1 = leetcode::TreeLinkNode(1);
    auto n2 = leetcode::TreeLinkNode(2);
    auto n3 = leetcode::TreeLinkNode(3);
    auto n4 = leetcode::TreeLinkNode(4);

    auto n5 = leetcode::TreeLinkNode(5);

    n0.left = &n1;
    n0.right = &n2;

    n1.left = &n3;
    n1.right = &n4;

    n2.right = &n5;

    leetcode::connect2(&n0);


    cout << n3.next->val << endl;
    cout << n4.next->val << endl;
    return 0;
}