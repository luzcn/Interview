#pragma once
#include "stdafx.h"


namespace leetcode
{
    //  Given a sorted linked list, delete all duplicates such that each element appear only once.
    //
    //  For example,
    //  Given 1->1->2, return 1->2.
    //  Given 1->1->2->3->3, return 1->2->3.
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        auto p = head;
        auto q = head->next;

        while (q)
        {
            // find duplicates
            while (q && q->val == p->val)
            {
                q = q->next;
            }

            p->next = q;
            p = q;
        }

        return head;
    }

    // Given a sorted linked list, delete all nodes that have duplicate numbers, 
    // leaving only distinct numbers from the original list.
    // For example,
    // Given 1->2->3->3->4->4->5, return 1->2->5.
    // Given 1->1->1->2->3, return 2->3.
    ListNode* deleteDuplicates2(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        ListNode res(-1);
        ListNode* h = &res;

        auto p = head;
        auto q = head->next;
        ListNode* prev = nullptr;

        while (q)
        {
            while (q && q->val == p->val)
            {
                q = q->next;
            }
        }

        return res.next;

    }
}