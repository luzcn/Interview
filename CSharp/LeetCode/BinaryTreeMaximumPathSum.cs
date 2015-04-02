using System;
using CSharp.DataStructure;


namespace CSharp.LeetCode
{
    class BinaryTreeMaximumPathSum
    {
        #region Binary Tree max path sum in any nodes
        /// <summary>
        /// Given a binary tree, find the maximum path sum. 
        /// 
        /// The path may start and end at any node in the tree. 
        /// 
        /// For example:
        /// Given the below binary tree, 
        ///          1
        ///         / \
        ///        2   3
        /// 
        ///  Return 6. 
        /// 
        /// Thoughts: the node value can be negative
        /// For each node, there are 4 ways to get the maximum path sum
        /// 
        /// 1. node only
        /// 2. node + leftSub
        /// 3. node + rightSub
        /// 4. node + leftSub + rightSub
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int MaxPathSum(TreeNode root)
        {
            maxPathSumRec(root);
            return res;
        }
        /// <summary>
        /// helper function.
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private int maxPathSumRec(TreeNode node)
        {
            if (node == null)
                return 0;

            // recursively get sum of left and right path
            int left = Math.Max(maxPathSumRec(node.left), 0);
            int right = Math.Max(maxPathSumRec(node.right), 0);

            //update maximum here
            res = Math.Max(node.val + left + right, res);

            // return sum of largest path of current node
            return node.val + Math.Max(left, right);

        }
        #endregion

        #region Binary tree Max path sum in two leaf nodes
        /// <summary>
        /// Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
        /// The maximum sum path may or may not go through root.
        /// Expected time complexity is O(n).
        /// 
        /// http://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int MaxPathSumTwoLeaves(TreeNode root)
        {
            computePathSum(root);

            return res;
        }

        private int computePathSum(TreeNode node)
        {
            if (node == null)
                return 0;

            int leftSumMax = computePathSum(node.left);
            int rightSumMax = computePathSum(node.right);

            int currentSum = Math.Max((leftSumMax + rightSumMax + node.val), Math.Max(leftSumMax, rightSumMax));

            res = Math.Max(res, currentSum);

            return Math.Max(leftSumMax, rightSumMax) + node.val;
        }
        #endregion

        private int res = Int32.MinValue;
    }
}
