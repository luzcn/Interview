#pragma once

#include "stdafx.h"

namespace ReverserLinkedList
{
    // Reverse the whole linked list iterative solution.
    ListNode* rever_linkedlist(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        ListNode* pre = nullptr;
        auto p = head;

        while (p)
        {
            auto temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }

        return pre;
    }

    // Reverse linked list recursive solution
    ListNode* reverseRec(ListNode* node, ListNode* pre)
    {
        if (!node)
            return nullptr;

        if (!node->next)
        {
            node->next = pre;
            return node;
        }

        auto r = reverseRec(node->next, node);
        node->next = pre;
        return r;
    }

    //Reverse a linked list from position m to n. Do it in-place and in one-pass.
    //For example:
    //Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    //return 1->4->3->2->5->NULL.
    //Note:
    //Given m, n satisfy the following condition:
    //1 ≤ m ≤ n ≤ length of list. 
    ListNode* reverse_linkedlist_inRange(ListNode* head, int m, int n)
    {
        if (!head || !head->next)
            return head;

        // Create a dummy node to keep the return head node unchanged.
        ListNode* result = new ListNode(-1);
        ListNode* pre = nullptr;
        auto p = head;
        int count = 1;

        // find the node at position m.
        while (p && count < m)
        {
            pre = p;
            p = p->next;
            count++;
        }

        // The node at position m - 1, which will point next to the begin node of the reversed sublist
        // if m == 0, it is NULL.
        auto begin = pre;

        // The node at position m, which will be the end node after reverse.
        auto end = p;

        // Reverse the nodes from position m to n.
        // After revers, the nodes between begin->next and end are the reversed sub list.
        while (p && count <= n)
        {
            auto temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            count++;
        }

        // Set the last node of the reversed sublist point next to the n+1 node.
        // if n+1 > list size, point to NULL.
        end->next = p;


        if (begin)
        {
            begin->next = pre;
        }

        if (m == 1)
        {
            result->next = pre;
        }
        else
        {
            result->next = head;
        }

        return result->next;
    }
}
