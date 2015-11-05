#pragma once
#include "stdafx.h"

//Sort a linked list in O(n log n) time using constant space complexity.
//
//Given 1 - 3->2->null, sort it to 1->2->3->null.

namespace lintcode
{
    ListNode* merge_two_sortedlist(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // create a temporary node as the return list head
        ListNode result(-1);

        auto p1 = list1;
        auto p2 = list2;
        auto h = &result;

        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                h->next = p1;
                p1 = p1->next;
            }
            else
            {
                h->next = p2;
                p2 = p2->next;
            }
            h = h->next;
        }
        while (p1)
        {
            h->next = p1;
            h = h->next;
            p1 = p1->next;
        }

        while (p2)
        {
            h->next = p2;
            h = h->next;
            p2 = p2->next;
        }

        return result.next;
    }

    // Merge Sort
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Divide
        int size = 0;
        auto p = head;
        while (p)
        {
            p = p->next;
            size++;
        }

        auto front = head;
        auto end = head;
        int count = 0;

        while (end && count < size / 2)
        {
            end = end->next;
            count++;
        }

        p = head;
        while (p->next != end)
        {
            p = p->next;
        }
        p->next = nullptr;

        auto L1 = sortList(front);
        auto L2 = sortList(end);

        // Merge
        return merge_two_sortedlist(L1, L2);
    }

}