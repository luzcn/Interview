using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharp.DataStructure;

namespace CSharp.LeetCode
{
    /*
    Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

    Calling next() will return the next smallest number in the BST.

    Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
    */
    class BSTIterator
    {
        public BSTIterator(TreeNode root)
        {
            stack = new Stack<TreeNode>();
            var current = root;
            while (current != null)
            {
                stack.Push(current);
                current = current.left;
            }
        }

        /** @return whether we have a next smallest number */
        public bool HasNext()
        {
            return stack.Count > 0;
        }

        /** @return the next smallest number */
        public int Next()
        {
            int res = 0;
            if (stack.Count > 0)
            {
                var current = stack.Peek();
                stack.Pop();
                res = current.val;

                current = current.right;
                while (current != null)
                {
                    stack.Push(current);
                    current = current.left;
                }
            }

            return res;
        }

        private Stack<TreeNode> stack;
    }
}
