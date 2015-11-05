#pragma once
#include "stdafx.h"

/***
 *	 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
    reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

    You must do this in-place without altering the nodes' values.

    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}. 
 */

namespace ReorderList
{
    namespace details
    {
        ListNode* reverse_linkedlist(ListNode* head)
        {
            if (!head || !head->next)
                return head;

            auto p = head;
            ListNode* pre = nullptr;

            while (p)
            {
                auto temp = p->next;
                p->next = pre;
                pre = p;
                p = temp;
            }

            return pre;
        }

        ListNode* merge(ListNode* head1, ListNode* head2)
        {
            auto p = head1;
            auto q = head2;
            ListNode* h = head1;

            while (p && q)
            {
                auto temp_p = p->next;
                auto temp_q = q->next;

                p->next = q;
                q->next = temp_p;

                p = temp_p;
                q = temp_q;

            }
            while (h->next)
            {
                h = h->next;
            }

            if (p)
                h->next = p;
            if (q)
                h->next = q;

            return head1;
        }
    }

    /// <summary>
    ///  
    /// </summary>
    /// <param name=""> </param>
    /// <return> </return>
    void reorder_list(ListNode* head)
    {
        if (!head || !head->next)
            return;

        // split to 2 parts
        int size = 0;
        auto p = head;
        while (p)
        {
            size++;
            p = p->next;
        }

        auto second_head = head;
        for (int i = 0; i < size / 2; ++i)
        {
            second_head = second_head->next;
        }
        p = head;
        while (p->next != second_head)
        {
            p = p->next;
        }
        p->next = nullptr;

        second_head = details::reverse_linkedlist(second_head);

        // Merge
        auto result = details::merge(head, second_head);

    }
}