#pragma once
#include "stdafx.h"

//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//For k = 2, you should return : 2->1->4->3->5
//For k = 3, you should return : 3->2->1->4->5
namespace leetcode
{
    ListNode* reverseKGroupRec(ListNode* head, int k, int size)
    {
        if (!head || !head->next)
            return head;

        // need to keep the left out nodes order
        if (size < k)
            return head;

        int count = 0;
        auto p = head;
        ListNode* pre = nullptr;
        while (p && count < k)
        {
            auto t = p->next;
            p->next = pre;
            pre = p;
            p = t;
            count++;
        }

        head->next = reverseKGroupRec(p, k, size - k);

        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || !head->next)
            return head;

        int size = 0;
        auto p = head;
        while (p)
        {
            p = p->next;
            size++;
        }

        return reverseKGroupRec(head, k, size);
    }
}