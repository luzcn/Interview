#pragma once

#include "stdafx.h"


/**
 *	Given a linked list and a positive number n:
 *	- print first n nodes then skip next n nodes
 *	- repeat until to the end of list.
 *
 *	1->2->3->4->5->6->7, given n = 2;
 *	out: 1->2->5->6
 *
 *	Given n = 3, out: 1->2->3->7
 */
namespace PrintLinkedList
{
    ListNode* printWithSkip(ListNode* head, int n)
    {
        if (!head || n <= 0)
        {
            return head;
        }

        auto p = head;
        bool skip = false;
        int count = 0;

        while (p)
        {
            if (count < n)
            {
                if (!skip)
                {
                    cout << p->val << endl;
                }
                count++;
                p = p->next;
            }
            else
            {
                skip = !skip;
                count = 0;
            }
        }

        return head;
    }
}

#if 0
#include "stdafx.h"
#include "CareerCup/PrintNodeWithSkips.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv [])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    ListNode n7(7);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    PrintLinkedList::printWithSkip(&n1, 2);

    /* auto p = &n1;
    while (p)
    {
    cout << p->val << endl;
    p = p->next;
    }*/
    return 0;
}
#endif