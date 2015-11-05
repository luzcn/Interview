#pragma once
#include "stdafx.h"

namespace leetcode
{
    //Given a singly linked list, determine if it is a palindrome.
    bool isPalindrome(ListNode* head)
    {
        if (!head || !head->next)
            return true;

        // Get the size
        auto p = head;
        int size = 0;
        while (p)
        {
            size++;
            p = p->next;
        }

        // Find the mid elemnt
        p = head;
        auto q = head;
        while (q && q->next)
        {
            p = p->next;
            q = q->next->next;
        }
        auto mid = p;
        p = head;

        // Reverse the first half
        ListNode* pre = nullptr;
        while (p != mid)
        {
            auto temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }

        auto first = pre;
        ListNode* second = nullptr;
        if (size % 2 == 0)
            second = mid;
        else
            second = mid->next;

        while (first&&second)
        {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        if (first || second)
            return false;

        return true;
    }
}