#pragma  once
#include "stdafx.h"

/***
 *	You have two numbers represented by a linked list, where each node contains a single digit The digits are stored in reverse order, 
 *	such that the 1¡¯s digit is at the head of the list Write a function that adds the two numbers and returns the sum as a linked list.
    EXAMPLE
    Input: (3 -> 1 -> 5), (5 -> 9 -> 2)
    Output: 8 -> 0 -> 8

    some testcase:
    0->2; null => 0->2
    0->2->0, 1->1 => 1->3->0 
    9->9, 9->9 => 8->9->1
 */
namespace careercup
{
    ListNode* addNumbers(ListNode* head1, ListNode* head2)
    {
        if (!head1)
        {
            return head2;
        }
        if (!head2)
        {
            return head1;
        }

        auto p = head1;
        auto q = head2;
        ListNode result(-1);
        auto h = &result;
        int carry = 0;

        while (p && q)
        {
            auto sum = p->val + q->val + carry;
            if (sum > 9)
            {
                sum = sum - 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            h->next = newNode;
            h = newNode;
        }

        while (p)
        {
            h->next = p;
            h = p;
            p = p->next;
        }
        while (q)
        {
            h->next = q;
            h = q;
            q = q->next;
        }

        return result.next;
    }
}