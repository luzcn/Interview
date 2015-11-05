using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CSharp.DataStructure;

namespace CSharp.LeetCode
{
    class LowestCommonAncestor
    {
        // Given a binary tree, find the lowest common ancestor of two given nodes in the tree.
        public TreeNode LCA(TreeNode node, int n1, int n2)
        {
            if (node == null)
                return null;

            if (node.val == n1 || node.val == n2)
                return node;

            var L = LCA(node.left, n1, n2);
            var R = LCA(node.right, n1, n2);

            if (L != null && R != null)
                return node;
            else if (L != null)
            {
                return L;
            }
            else
                return R;
        }
    }
}
