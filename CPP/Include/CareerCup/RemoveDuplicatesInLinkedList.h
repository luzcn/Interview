#pragma  once

#include "stdafx.h"
#include <unordered_map>

struct ListNode
{
    ListNode(int v)
        :val(v), next(nullptr)
    {}

    int val;
    ListNode* next;
};
namespace RemoveDuplicates
{
    /// <summary>
    ///  1->1->1->4->4->9 ==> 1->4->9
    /// </summary>
    /// <param name=""> </param>
    /// <return> </return>
    void remove_duplicate_in_sorted_linkedlist(ListNode* head)
    {
        // no elements
        if (head == nullptr)
            return;

        // only one elements
        if (head->next == nullptr)
            return;

        //ListNode* h = head;
        ListNode* p = head;
        ListNode* q = p->next;

        while (q != nullptr)
        {
            if (p->val == q->val) // duplicates
            {
                p->next = q->next;
            }
            else
            {
                p = q;
            }
            q = q->next;
        }
    }

    void remove_duplicate_in_unsorted_linkedlist(ListNode* head)
    {
        // no elements
        if (head == nullptr)
            return;

        // only one elements
        if (head->next == nullptr)
            return;

        ListNode* p = head;
        //ListNode* q = p->next;
        std::unordered_map<int, int> hash_map;
        hash_map.emplace(p->val, 1);

        while (p->next != nullptr)
        {
            if (hash_map.count(p->next->val) == 0)
            {
                hash_map.emplace(p->next->val, 1);
                p = p->next;
            }
            else
            {
                p->next = p->next->next;
            }
        }
    }

}


/*
int _tmain(int argc, _TCHAR* argv [])
{
    ListNode* n[8] = { new ListNode(1), new ListNode(1), new ListNode(2),
        new ListNode(2), new ListNode(2), new ListNode(8), new ListNode(8), new ListNode(9) };

    n[0]->next = n[1];
    n[1]->next = n[2];
    n[2]->next = n[3];
    n[3]->next = n[4];
    n[4]->next = n[5];
    n[5]->next = n[6];
    n[6]->next = n[7];
    //n[7]->next = n[8];

    RemoveDuplicates::remove_duplicate_in_sorted_linkedlist(n[0]);

    auto p = n[0];
    while (p != nullptr)
    {
        std::cout << p->val << std::endl;
        p = p->next;
    }

    for (auto t : n)
    {
        delete t;
    }
    return 0;
}*/