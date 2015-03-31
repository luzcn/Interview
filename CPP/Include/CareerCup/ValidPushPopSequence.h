#pragma once

#include "stdafx.h"
#include <stack>

/**
 *	 Problem: Given two integer sequences, one of which is the push sequence of a stack,
 *	 please check whether the other sequence is a corresponding pop sequence or not.

 For example, if 1, 2, 3, 4, 5 is a push sequence, 4, 5, 3, 2, 1 is a corresponding pop sequence,
 but the sequence 4, 3, 5, 1, 2 is not.

 note: the pop sequence may not equal to push sequence. e.g. {5, 3, 1 } is also valid.
 */
namespace ValidPushPopSequence
{
    using namespace std;
    bool isValidPop(vector<int>& push_seq, vector<int>& pop_seq)
    {
        stack<int> s;
        s.push(push_seq[0]);

        int index_push = 1;
        int index_pop = 0;

        while (index_pop < pop_seq.size())
        {
            if (!s.empty() && pop_seq[index_pop] == s.top())   // if find one pop element in the helper stack, pop it.
            {
                s.pop();
                index_pop++;
            }
            // if not match, we have two choices:
            // 1. keep read from push sequence and push it to the helper stack;
            // 2. keep pop from the helper stack.
            // The terminate condition is both helper stack is empty and push sequence reaches end.
            else if (index_push < push_seq.size())
            {
                s.push(push_seq[index_push++]);
            }
            else if (!s.empty())
            {
                if (s.top() == pop_seq[index_pop])
                {
                    index_pop++;
                }
                s.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}