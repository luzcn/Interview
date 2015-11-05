using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharp.DataStructure;

namespace CSharp.LeetCode
{
    /**
        Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

        You should preserve the original relative order of the nodes in each of the two partitions.

        For example,
        Given 1->4->3->2->5->2 and x = 3,
        return 1->2->2->4->3->5. 
    **/
    class PartitionList
    {
        ListNode partition(ListNode head, int x)
        {
            if (head == null)
                return null;

            ListNode less = new ListNode(-1);
            ListNode large = new ListNode(-1);
            var p = less;
            var q = large;

            var h = head;
            while(h != null)
            {
                if (h.val < x)
                {
                    p.next = h;
                    h = h.next;
                    p = p.next;
                    p.next = null;
                }
                else
                {
                    q.next = h;
                    h = h.next;
                    q = q.next;
                    q.next = null;
                }
            }
            if (q != null)
            {
                q.next = large.next;
            }

            return less.next;
        }
    }
}