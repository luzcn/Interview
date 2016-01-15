#pragma  once
#include "stdafx.h"

namespace LinkedListCycle
{
    /// <summary>
    ///  The solution is simple and intuitive,
    ///  both p and q start from the head, p traverse the list in 1 step, q in 2 steps.
    ///  if p and q can meet again, then there is cycle.
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        auto p = head;
        auto q = head;

        while (p && q)
        {
            p = p->next;
            if (q->next)
            {
                q = q->next->next;
            }
            else
            {
                return false;
            }

            if (p == q)
            {
                return true;
            }
        }

        return false;
    }

    ListNode* detectCycleStartNode(ListNode* head)
    {
        if (!head)
            return head;

        auto p = head;
        auto q = head;

        // Detect has cycle.
        while (p && q)
        {
            p = p->next;
            if (q->next)
            {
                q = q->next->next;
            }
            else
            {
                return nullptr;
            }

            if (p == q)
            {
                break;
            }
        }

        if (!p || !q)
        {
            return nullptr;
        }

        // if p and q meets, there is a cycle.
        // Start from the head and this meeting point, if they meet again, 
        // the meet point is the cycle begin node.
        p = head;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }
}