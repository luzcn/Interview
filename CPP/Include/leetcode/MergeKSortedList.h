#pragma once
#include "stdafx.h"
#include <queue>

/***
 *	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 *	using heap (priority queue) to store all the head nodes of k sorted lists.
 *
 */
namespace MergeKSortedList
{
    using namespace std;

/*
    struct Comparator
    {
        bool operator() (ListNode* n1, ListNode* n2)
        {
            return n1->val > n2->val;
        }
    };*/

    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }

        auto compare = [](ListNode* n1, ListNode* n2){ return n1->val > n2->val; };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> que(lists.begin(), lists.end());


        ListNode result(0);
        auto current = &result;

        while (!que.empty())
        {
            current->next = que.top();
            que.pop();
            current = current->next;

            if (current->next)
            {
                que.push(current->next);
            }
        }

        return result.next;
    }
}

#if 0
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

    vector<ListNode*> v;
    v.push_back(list1[0]);
    v.push_back(list2[0]);

    auto result = MergeKSortedList::mergeKLists(v);

    while (result != nullptr)
    {
        std::cout << result->val << std::endl;
        result = result->next;
    }
    return 0;
}
#endif