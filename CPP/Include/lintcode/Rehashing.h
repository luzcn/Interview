#pragma once
#include "stdafx.h"

namespace lintcode
{
    int hashcode(int key, int capacity)
    {
        //return key > 0 ? key%capacity : (key%capacity + capacity) % capacity;
        if (key >= 0)
            return key % capacity;
        else
            return (key % capacity + capacity) % capacity;
    }

    vector<ListNode*> rehashing(vector<ListNode*> hashTable)
    {
        int capacity = hashTable.capacity()*2;
        vector<ListNode*> res;
        res.resize(capacity);

        for (int i = 0; i < hashTable.size(); i++)
        {
            auto p = hashTable[i];
            while (p)
            {
                int key = p->val;
                int index = hashcode(key, capacity);
                ListNode* newNode = new ListNode(key);
                if (!res[index])
                {
                    res[index] = newNode;
                }
                else
                {
                    auto q = res[index];
                    while (q->next)
                    {
                        q = q->next;
                    }
                    q->next = newNode;
                }

                p = p->next;
            }
        }

        return res;
    }
}