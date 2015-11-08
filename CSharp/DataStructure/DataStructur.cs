using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.DataStructure
{
    class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode(int value)
        {
            this.val = value;
            left = null;
            right = null;
        }
    }

    class ListNode
    {
        public int val;
        public ListNode next;

        public ListNode(int value)
        {
            this.val = value;
        }
    }
}
