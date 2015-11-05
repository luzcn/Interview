#pragma once
#include "stdafx.h"

namespace lintcode
{
    ListNode* insert(ListNode* head, ListNode* node)
    {
        if (!head)
            return node;

        auto h = head;
        ListNode* prev = nullptr;
        while (h && h->val < node->val)
        {
            prev = h;
            h = h->next;
        }

        if (prev)
        {
            node->next = h;
            prev->next = node;
            return prev;
        }
        else
        {
            node->next = h;
            return node;
        }
    }

    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode* h = nullptr;
        auto p = head;

        while (p)
        {
            auto temp = p->next;
            p->next = nullptr;

            h = insert(h, p);
            p = temp;
        }

        return h;

    }
}