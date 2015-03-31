#pragma once
#include "stdafx.h"

namespace PartitionList
{
    /***
     *	Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

         You should preserve the original relative order of the nodes in each of the two partitions.

         For example,
         Given 1->4->3->2->5->2 and x = 3,
         return 1->2->2->4->3->5.
     */
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return head;

        ListNode* result1 = new ListNode(-1);
        ListNode* result2 = new ListNode(-1);

        auto h1 = result1;
        auto h2 = result2;

        auto p = head;

        while (p)
        {
            if (p->val < x)
            {
                h1->next = p;
                h1 = h1->next;
            }
            else
            {
                h2->next = p;
                h2 = h2->next;
            }

            p = p->next;
        }

        h1->next = result2->next;
        h2->next = NULL;  // must set the end to null, otherwise, it will hang.

        return result1->next;
    }
}