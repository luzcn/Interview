#pragma  once

#include "stdafx.h"


struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int v)
        :val(v), next(nullptr)
    {}
};

namespace MergeSortLinkedList
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
        while (p1 != nullptr)
        {
            h->next = p1;
            h = h->next;
            p1 = p1->next;
        }

        while (p2 != nullptr)
        {
            h->next = p2;
            h = h->next;
            p2 = p2->next;
        }

        return result->next;
    }

    ListNode* merge_sort_linkedlist(ListNode* head)
    {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return head;

        int count = 0;
        auto p = head;
        auto front = head;
        auto end = head;

        while (p != nullptr)
        {
            count++;
            p = p->next;
        }

        // Divide
        for (int i = 0; i < count / 2; ++i)
        {
            end = end->next;
        }

        p = head;
        while (p->next != end)
        {
            p = p->next;
        }
        p->next = nullptr;

        auto list1 = merge_sort_linkedlist(front);
        auto list2 = merge_sort_linkedlist(end);

        // Merge
        return merge_two_sortedlist(list1, list2);
    }


}

/*
int _tmain(int argc, _TCHAR* argv[])
{
    std::vector<ListNode*> list2 = { new ListNode(17), new ListNode(49), new ListNode(23), new ListNode(7),
        new ListNode(26), new ListNode(5), new ListNode(124), new ListNode(15) };

    list2[0]->next = list2[1];
    list2[1]->next = list2[2];
    list2[2]->next = list2[3];
    list2[3]->next = list2[4];
    list2[4]->next = list2[5];
    list2[5]->next = list2[6];
    list2[6]->next = list2[7];

    auto result = MergeSortLinkedList::merge_sort_linkedlist(list2[0]);

    while (result != nullptr)
    {
        std::cout << result->val << std::endl;
        result = result->next;
    }

    return 0;
}*/
