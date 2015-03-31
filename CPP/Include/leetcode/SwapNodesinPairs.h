#pragma once

#include "stdafx.h"

/*
 *	 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed.
 */
namespace SwapNodesinPairs
{
    ListNode* reverseInKNodes(ListNode* node, int k)
    {
        if (!node)
        {
            return nullptr;
        }

        int num = 0;
        auto currentNode = node; // need to remeber this node first.
        auto p = node;
        ListNode* pre = nullptr;

        while (p && num < k)
        {
            auto temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            num++;
        }

        currentNode->next = reverseInKNodes(p, k);

        return pre;
    }

    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
    }
}