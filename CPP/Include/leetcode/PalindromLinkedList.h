#pragma once
#include "stdafx.h"

// Palindrome Linked List
//  Given a singly linked list, determine if it is a palindrome.
//
//  Follow up :
//  Could you do it in O(n) time and O(1) space ?

namespace leetcode
{
    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next)
            return true;

        auto p = head;
        int size = 0;
        while (p)
        {
            size++;
            p = p->next;
        }

        // find the middle node
        int count = 0;
        p = head;
        while (p && count++ < size / 2)
        {
            p = p->next;
        }

        auto q = head;
        ListNode* pre = nullptr;
        while (q && q != p)
        {
            auto temp = q->next;
            q->next = pre;
            pre = q;
            q = temp;
        }

        ListNode* first_head = pre;
        ListNode* second_head = nullptr;

        if (size % 2 != 0)
        {
            second_head = p->next;
        }
        else
        {
            second_head = p;
        }

        while (first_head && second_head)
        {
            if (first_head->val != second_head->val)
            {
                return false;
            }
            first_head = first_head->next;
            second_head = second_head->next;
        }

        if (first_head || second_head)
            return false;

        return true;
    }
}
