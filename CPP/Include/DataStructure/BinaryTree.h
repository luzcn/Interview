#pragma once

#include "stdafx.h"
#include <stack>
#include <queue>
#include <algorithm>

namespace BinaryTree
{
    using namespace std;

    namespace TreeTraversal
    {
        void in_order(TreeNode* root)
        {
            if (!root)
                return;

            in_order(root->left);
            std::cout << root->val << std::endl;
            in_order(root->right);
        }

        /// <summary>
        ///  In order traverse binary tree iterative solution.
        /// </summary>
        /// <param name=""> </param>
        void in_order_nonrec(TreeNode* root)
        {
            if (!root)
                return;

            std::stack<TreeNode*> s;

            bool done = false;
            auto current_node = root;

            while (!done)
            {
                if (current_node)
                {
                    s.push(current_node);
                    current_node = current_node->left;
                }
                else if (!s.empty())
                {
                    std::cout << s.top() << std::endl;
                    current_node = s.top()->right;
                    s.pop();
                }
                else
                    done = true;
            }
        }


        /// <summary>
        ///  The pre-order binary tree traverse none recursive implementation
        ///  
        ///  Note: using stack.
        /// </summary>
        /// <param name=""> </param>
        /// <return> </return>
        void pre_order_nonrec(TreeNode* root)
        {
            if (!root)
                return;

            std::stack<TreeNode*> s;
            s.push(root);

            while (!s.empty())
            {
                auto current_node = s.top();
                s.pop();
                std::cout << current_node->val << std::endl;

                if (current_node->right)
                {
                    s.push(current_node->right);
                }
                if (current_node->left)
                {
                    s.push(current_node->left);
                }
            }
        }

        /// <summary>
        ///  Similary to pre order, but for each node push in left child first.
        ///  After construct the output array, reverse the result array.
        /// </summary>
        /// <param name=""> </param>
        std::vector<int> post_order_nonrec(TreeNode* root)
        {
            std::vector<int> solution;
            if (!root)
                return solution;

            std::stack<TreeNode*> s;
            s.push(root);

            while (!s.empty())
            {
                auto current = s.top();
                s.pop();
                solution.push_back(current->val);

                if (current->left)
                {
                    s.push(current->left);
                }
                if (current->right)
                {
                    s.push(current->right);
                }
            }

            std::reverse(solution.begin(), solution.end());
            return solution;
        }

        /***
        *	Use queue to save all nodes in the same level.
        */
        vector<int> BFS(TreeNode* root)
        {
            vector<int> sol;
            if (!root)
                return sol;

            queue<TreeNode*> level;
            level.push(root);

            while (!level.empty())
            {
                auto current = level.front();
                level.pop();
                sol.push_back(current->val);

                if (current->left)
                {
                    level.push(current->left);
                }

                if (current->right)
                {
                    level.push(current->right);
                }
            }

            return sol;
        }
    }


    namespace TreePrintPath
    {
        void printAllPathRec(TreeNode* node, std::vector<std::vector<int>>& solution, std::vector<int>& current_path)
        {
            if (!node)
            {
                return;
            }

            current_path.push_back(node->val);

            // pre-order/in-order/post-order all works.
            printAllPathRec(node->left, solution, current_path);
            printAllPathRec(node->right, solution, current_path);

            if (!node->left && !node->right)
            {
                solution.push_back(current_path);
            }

            current_path.pop_back();
        }

        /// <summary>
        ///  
        /// </summary>
        /// <param name=""> </param>
        /// <returns> </return>
        std::vector<std::vector<int>> printAllPath(TreeNode* root)
        {
            std::vector<std::vector<int>> solution;
            if (!root)
                return solution;

            printAllPathRec(root, solution, std::vector<int>());

            return solution;
        }
    }

    namespace ISBST
    {
        bool isBST(TreeNode* root)
        {
            if (!root)
            {
                return true;
            }

            stack<TreeNode*> s;
            auto current = root;
            TreeNode* prev = nullptr;

            while (true)
            {
                if (current)
                {
                    s.push(current);
                    current = current->left;
                }
                else if (!s.empty())
                {
                    current = s.top();
                    s.pop();
                    if (prev && prev->val >= current->val)
                    {
                        return false;
                    }

                    prev = current;
                    current = current->right;
                }
                else
                {
                    break;
                }
            }
            return true;
        }
    }

    namespace BinaryTreeSerialization
    {
        // using pre-order traverse
        void writeBinaryTreeRec(TreeNode* node, std::vector<std::string>& solution)
        {
            if (!node)
            {
                solution.push_back("#");
                return;
            }

            solution.push_back(std::to_string(node->val));
            writeBinaryTreeRec(node->left, solution);
            writeBinaryTreeRec(node->right, solution);
        }

        void readBinaryTreeRec(TreeNode* node, const std::vector<std::string>& input, int index)
        {
            if (index == input.size())
                return;
            if (input[index] == "#")
                return;

            node = new TreeNode(std::atoi(input[index].c_str()));

            readBinaryTreeRec(node->left, input, index + 1);
            readBinaryTreeRec(node->right, input, index + 1);
        }

        std::vector<std::string> writeBinaryTree(TreeNode* root)
        {
            std::vector<std::string> solution;
            if (!root)
            {
                solution.push_back("#");
                return solution;
            }

            writeBinaryTreeRec(root, solution);
            return solution;
        }
    }

    namespace LeastCommonAncestor
    {
        TreeNode* LCA_BottomUp(TreeNode* node, int n1, int n2)
        {
            if (!node)
                return nullptr;

            if (node->val == n1 || node->val == n2)
                return node;


            auto L = LCA_BottomUp(node->left, n1, n2);
            auto R = LCA_BottomUp(node->right, n1, n2);

            if (L && R)
                return node;
            else if (L)
                return L;
            else
                return R;
        }
    }
}

#if 0
/***
*         1
*        / \
*       2   3
*      / \
*     7   6
*/
TreeNode* nodes[5] = { new TreeNode(1), new TreeNode(2), new TreeNode(3), new TreeNode(7), new TreeNode(6) };

nodes[0]->left = nodes[1];
nodes[0]->right = nodes[2];

nodes[1]->left = nodes[3];
nodes[1]->right = nodes[4];
#endif