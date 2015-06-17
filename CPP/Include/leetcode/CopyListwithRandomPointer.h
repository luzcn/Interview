#pragma  once

#include "stdafx.h"

struct RandomListNode
{
    RandomListNode* next;
    RandomListNode* random;
    int label;
    RandomListNode(int val)
        :label(val), next(nullptr), random(nullptr)
    {}
};

namespace leetcode
{
    /// <summary>
    ///  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
    ///  Return a deep copy of the list.
    ///  
    ///  http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html
    /// </summary>
    /// <param name=""> </param>
    /// <returns> </return>
    RandomListNode* copyRandomList(RandomListNode* head)
    {
        if (!head)
            return head;

        auto p = head;
        while (p)
        {
            RandomListNode* newNode = new RandomListNode(p->label);
            auto temp = p->next;

            p->next = newNode;
            newNode->next = temp;

            p = temp;
        }

        auto result = head->next;
        
        // Construct the random pointer.
        p = head;
        while (p)
        {
            if (p->random)
            {
                p->next->random = p->random->next;
            }
            else
            {
                p->next->random = nullptr;
            }
            p = p->next->next;
        }

        // Recover the next pointer.
        p = head;
        while (p)
        {
            auto temp = p->next;

            if (temp)
            {
                p->next = temp->next;
                p = temp;
            }
            p = temp;
        }

        return result;
    }
}

#if 0
RandomListNode* copyRandomList(RandomListNode* head)
{
    if (!head)
        return head;

    auto p = head;
    RandomListNode* result = new RandomListNode(-1);
    auto h = result;

    while (p)
    {
        RandomListNode* newNode = new RandomListNode(p->label);
        h->next = newNode;

        auto temp = p->next;
        newNode->random = p;
        p->next = newNode;

        p = temp;
        h = newNode;
    }

    auto q = result->next;
    while (q)
    {
        auto temp = q->random;

        // construct the random pointer
        if (q->random->random)
        {
            q->random = q->random->random->next;
        }
        else
        {
            q->random = nullptr;
        }

        // recover the next pointers of the original list.
        // This will fail, because if recover back the "q->random->random->next" 
        // may points back to the original list.

        //if (q->next)
        //{
        //    temp->next = q->next->random;
        //}
        //else
        //{
        //    temp->next = nullptr;
        //}

        q = q->next;
    }

    return result->next;
}
#endif // 0
