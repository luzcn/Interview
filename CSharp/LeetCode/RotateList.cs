using CSharp.DataStructure;

namespace CSharp.LeetCode
{
    /// <summary>
    /// Given a list, rotate the list to the right by k places, where k is non-negative.
    //   For example:
    //  Given 1->2->3->4->5->NULL and k = 2,
    //  return 4->5->1->2->3->NULL.
    /// </summary>
    class RotateList
    {
        public ListNode RotateRight(ListNode head, int k)
        {
            if (head == null)
                return head;

            // get the total length
            int length = 0;
            int count = 0;
            var p = head;
            var q = head;
            while (q != null)
            {
                q = q.next;
                length++;
            }

            q = head;
            k = k % length; // if k > length, we use k % length

            // if k == 0, no need to rotate.
            if (k == 0)
                return head;

            // q will point to the last kth element.
            while (q.next != null && count < k)
            {
                q = q.next;
                count++;
            }

            while (q.next != null)
            {
                p = p.next;
                q = q.next;
            }


            ListNode result = null;

            result = p.next;
            p.next = null;
            q.next = head;
            return result;
        }
    }
}
