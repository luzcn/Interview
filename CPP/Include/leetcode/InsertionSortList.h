#pragma  once

#include "stdafx.h"

namespace leetcode
{
    ListNode* insert_node_tosortedlist(ListNode* head, ListNode* p)
    {
        if (!head)
            return p;
        if (!p)
            return head;

        auto first = head;
        auto second = head->next;

        if (p->val <= first->val)
        {
            p->next = first;
            return p;
        }

        while (first && second && first->val < p->val)
        {
            if (second->val >= p->val)
            {
                //insert
                first->next = p;
                p->next = second;
                return head;
            }
            first = first->next;
            second = second->next;
        }

        first->next = p;

        return head;
    }

    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return head;
        if (!head->next)
            return head;

        ListNode* h = nullptr;
        auto p = head;

        while (p)
        {
            auto temp = p;
            p = p->next;
            temp->next = nullptr;

            h = insert_node_tosortedlist(h, temp);
        }

        return h;
    }
}


#if 0
int _tmain(int argc, _TCHAR* argv [])
{
    std::vector<ListNode*> nodes = { new ListNode(12), new ListNode(3), new ListNode(90), new ListNode(323), new ListNode(2), new ListNode(7) };
    for (int i = 1; i < nodes.size(); ++i)
    {
        nodes[i - 1]->next = nodes[i];
    }

    //ListNode* p = new ListNode(0);

    auto t = InsertionSortList::insertionSortList(nodes[0]);
    while (t)
    {
        std::cout << t->val << std::endl;
        t = t->next;
    }

    return 0;
}
#endif // 0
