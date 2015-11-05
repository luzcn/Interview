using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class VerifyPreorderSequenceBST
    {
        /// <summary>
        /// Given a BST preorder sequce, verify if it is valid 
        /// </summary>
        /// <param name="preorder"></param>
        /// <returns></returns>
        public bool VerifyPreorder(int[] preorder)
        {
            if (preorder.Length <= 1)
                return true;

            Stack<int> st = new Stack<int>();
            int rootValue = Int32.MinValue;
            int n = preorder.Length;

            st.Push(preorder[0]);

            for (int i = 1; i < n; i++)
            {
                if (preorder[i] < rootValue)
                    return false;

                if (preorder[i] > preorder[i-1]) // found one right child
                {
                    while(st.Count > 0 && preorder[i] > st.Peek())
                    {
                        rootValue = st.Peek();
                        st.Pop();
                    }
                }

                st.Push(preorder[i]);
            }

            return true;
        }
    }
}
