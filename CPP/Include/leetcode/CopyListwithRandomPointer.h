#pragma  once

#include "stdafx.h"

//A linked list is given such that each node contains an additional random pointer 
//which could point to any node in the list or null.
//
//Return a deep copy of the list.
// http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html

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
            p = p->next->next;
        }

        // Recover the next pointer.
        p = head;
        while (p)
        {
            auto nextNode = p->next;
            if (nextNode)
            {
                p->next = nextNode->next;
            }
            p = nextNode;
        }

        return result;
    }

    // use hash map
    RandomListNode* copyRandomList2(RandomListNode* head)
    {
        if (!head)
            return head;

        unordered_map<RandomListNode*, RandomListNode*> map;

        RandomListNode* p = head;
        map[p] = new RandomListNode(p->label);
        while (p)
        {
            // next pointer
            if (p->next)
            {
                map[p->next] = new RandomListNode(p->next->label);
                map[p]->next = map[p->next];
            }


            // random pointer
            if (p->random)
            {
                if (map.find(p->random) == map.end())
                {
                    map[p->random] = new RandomListNode(p->random->label);;
                }

                map[p]->random = map[p->random];
            }

            p = p->next;
        }

        return map[head];
    }

}

