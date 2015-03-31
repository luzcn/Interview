#pragma once
#include "stdafx.h"

/***
 *	Given a linked list, remove the nth node from the end of list and return its head.

    For example,

       Given linked list: 1->2->3->4->5, and n = 2.

       After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:
    Given n will always be valid.
    Try to do this in one pass. 
 */
namespace RemoveNthNodeFromEndofList
{
    ListNode* removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || n <= 0)
            return head;

        auto p = head;
        auto q = head;

        int count = 0;
        while (p && count < n)
        {
            p = p->next;
            count++;
        }

        // Need to remove the head node.
        if (!p)
        {
            head = head->next;
        }
        else
        {
            // Here, we can guarantee p is valid.
            while (p->next)
            {
                p = p->next;
                q = q->next;
            }

            if (q->next)
            {
                q->next = q->next->next;
            }
        }

        return head;
    }
}