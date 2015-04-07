using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    using LeetCode;
    using CareerCup;
    using DataStructure;
    class Program
    {
        static void Main(string[] args)
        {
            ListNode n1 = new ListNode(1);
            ListNode n2 = new ListNode(2);
            ListNode n3 = new ListNode(3);
            ListNode n4 = new ListNode(4);
            ListNode n5 = new ListNode(5);

            n1.next = n2;
            n2.next = n3;
            n3.next = n4;
            n4.next = n5;

            ReverseLinkedList rl = new ReverseLinkedList();
            //var t = rl.reverse(n1);
            var t = rl.swapInPair(n1);

            while (t != null)
            {
                Console.Write(t.val + " ");
                t = t.next;
            }

            Console.WriteLine();
        }
    }
}
