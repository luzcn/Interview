#pragma once
#include "stdafx.h"

//Sort a linked list in O(n log n) time using constant space complexity.
// 
namespace leetcode
{
    ListNode* mergeTowSortedList(ListNode* h1, ListNode* h2)
    {
        if (!h1)
            return h2;
        
        if (!h2)
            return h1;

        ListNode result(0);
        ListNode* h = &result;

        auto p = h1;
        auto q = h2;

        while (p || q)
        {
            if (p && q)
            {
                if (p->val < q->val)
                {
                    h->next = p;
                    h = h->next;
                    p = p->next;
                }
                else
                {
                    h->next = q;
                    h = h->next;
                    q = q->next;
                }
            }
            else if (p)
            {
                h->next = p;
                break;
            }
            else
            {
                h->next = q;
                break;
            }
        }

        return result.next;
    }

    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next)
            return head;

        int size = 0;
        auto p = head;
        while (p)
        {
            size++;
            p = p->next;
        }

        p = head;
        int count = 0;
        ListNode* prev = nullptr;

        while (count++ < size / 2)
        {
            prev = p;
            p = p->next;
        }
        prev->next = nullptr;

        // divide 
        ListNode* left = sortList(head);
        ListNode* right = sortList(p);

        // merge two sorted list;
        return mergeTowSortedList(left, right);
    }
}