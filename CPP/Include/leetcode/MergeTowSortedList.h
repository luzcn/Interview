#pragma once

#include "stdafx.h"

namespace MergeTowSortedList
{
    ListNode* merge_two_sortedlist(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        // create a temporary node as the return list head
        ListNode* result = new ListNode(-1);

        auto p1 = list1;
        auto p2 = list2;
        auto h = result;

        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                h->next = p1;
                p1 = p1->next;
            }
            else
            {
                h->next = p2;
                p2 = p2->next;
            }
            h = h->next;
        }
        while (p1)
        {
            h->next = p1;
            h = h->next;
            p1 = p1->next;
        }

        while (p2)
        {
            h->next = p2;
            h = h->next;
            p2 = p2->next;
        }

        return result->next;
    }
}



/*
int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<ListNode*> list1 = { new ListNode(7), new ListNode(17), new ListNode(23), new ListNode(49) };
    std::vector<ListNode*> list2 = { new ListNode(18), new ListNode(24), new ListNode(39), new ListNode(73), new ListNode(152), new ListNode(1522) };

    list1[0]->next = list1[1];
    list1[1]->next = list1[2];
    list1[2]->next = list1[3];

    list2[0]->next = list2[1];
    list2[1]->next = list2[2];
    list2[2]->next = list2[3];
    list2[3]->next = list2[4];
    list2[4]->next = list2[5];

    auto result = MergeTowSortedList::merge_two_sortedlist(list1[0], list2[0]);

    while (result != nullptr)
    {
        std::cout << result->val << std::endl;
        result = result->next;
    }

    return 0;
}*/