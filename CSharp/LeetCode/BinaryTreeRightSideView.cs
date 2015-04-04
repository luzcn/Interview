using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    using DataStructure;

    /**
     * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

        For example:
        Given the following binary tree,

           1           <---
         /   \
        2     3         <---
         \     \
          5     4       <---

        You should return [1, 3, 4]. 
     ***/

    class BinaryTreeRightSideView
    {
        public IList<int> RightSideView(TreeNode root)
        {
            IList<int> res = new List<int>();
            if (root == null)
                return res;

            res.Add(root.val);
            // BFS tree
            Queue<TreeNode> que1 = new Queue<TreeNode>();
            Queue<TreeNode> que2 = new Queue<TreeNode>();

            que1.Enqueue(root);

            while (que1.Count > 0)
            {
                var current = que1.Dequeue();
                if (current.left != null)
                {
                    que2.Enqueue(current.left);
                }
                if (current.right != null)
                {
                    que2.Enqueue(current.right);
                }

                if (que1.Count == 0)
                {
                    if (que2.Count > 0)
                    {
                        res.Add(que2.Last().val);
                    }
                    que1 = que2;
                    que2 = new Queue<TreeNode>();
                }
            }

            return res;
        }
    }
}
