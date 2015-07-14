#pragma once

#include "stdafx.h"

/***
 *	Implement an algorithm to delete a node in the middle of a single linked list, given
 only access to that node
 EXAMPLE
 Input: the node from the linked list a->b->c->d->e
 Result: nothing is returned, but the new linked list looks like a->b->d->e
 */

namespace DeleteNodeInMiddle
{
    // We can not use traditional p.next = p.next.next solution, since we cannot access from the head node.
    // But, we can change the node value.
    void deleteMiddleNode(ListNode* node)
    {
        if (!node || !node->next)
        {
            return;
        }

        auto p = node->next;
        node->val = p->val;
        node->next = p->next;
    }
}


