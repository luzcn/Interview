using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.CareerCup
{
    using DataStructure;
    class ReverseLinkedList
    {
        public ListNode reverse(ListNode head)
        {
            if (head == null || head.next == null)
                return head;

            return reverse_rec(head, null);
        }

        /// <summary>
        /// swap the node in each two pairs
        /// i.e. 1->2->3->4->5 ==> 2->1->4->3->5
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        public ListNode swapInPair(ListNode head)
        {
            if (head == null || head.next == null)
                return head;

            var p = head;
            int size = 0;
            while (p != null)
            {
                size++;
                p = p.next;
            }

            return reverseKGroup(head, 3, size);
        }

        private ListNode reverseKGroup(ListNode ptr, int k, int size)
        {
            if (ptr == null || size < k)
                return ptr;

            int count = 0;
            ListNode pre = null;
            ListNode current = ptr;

            while (ptr != null && count < k)
            {
                var temp = ptr.next;
                ptr.next = pre;
                pre = ptr;
                ptr = temp;
                count++;
            }
            current.next = reverseKGroup(ptr, k, size - k);

            return pre;
        }

        /// <summary>
        /// Reverse the whole linked list in recursive.
        /// </summary>
        /// <param name="p"></param>
        /// <param name="pre"></param>
        /// <returns></returns>
        private ListNode reverse_rec(ListNode p, ListNode pre)
        {
            if (p == null)
                return pre;

            var temp = p.next;
            p.next = pre;

            return reverse_rec(temp, p);
        }

        /// <summary>
        /// Reverse in none recursive.
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        private ListNode reverse_NonRec(ListNode head)
        {
            var p = head;
            ListNode pre = null;

            while (p != null)
            {
                var temp = p.next;
                p.next = pre;
                pre = p;
                p = temp;
            }

            return pre;
        }
    }
}
