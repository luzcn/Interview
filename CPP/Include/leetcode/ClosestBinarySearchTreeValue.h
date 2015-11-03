#pragma once
#include "stdafx.h"

// Given a non-empty binary search tree and a target value, 
// find the value in the BST that is closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.
namespace leetcode
{
    TreeNode* dfs(TreeNode* node, const double& target)
    {
        if (!node)
            return nullptr;

        TreeNode* closestNode = nullptr;
        if ((double)node->val == target)
        {
            return node;
        }
        else if (target < (double)node->val)
        {
            closestNode = dfs(node->left, target);
        }
        else
        {
            closestNode = dfs(node->right, target);
        }

        if (closestNode && abs(closestNode->val - target) < abs(node->val - target))
        {
            return closestNode;
        }
        else
        {
            return node;
        }

    }
    int closestValue(TreeNode* root, double target)
    {
        if (!root)
            return INT_MAX;

        return dfs(root, target)->val;
    }


    //Given a non - empty binary search tree and a target value, find k values in the BST that are closest to the target.
    //    Note:
    //Given target value is a floating point.
    //    You may assume k is always valid, that is : k <= total nodes.
    //    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
    //    Follow up :
    //Assume that the BST is balanced, could you solve it in less than O(n) runtime(where n = total nodes)?
    class Solution
    {
    public:
        // O(n) time, O(k + height) space.
        vector<int> closestKValues(TreeNode* root, double target, int k)
        {
            // inorder iterative 
            stack<TreeNode*> stack;
            vector<int> result;
            if (!root)
                return result;

            auto current = root;
            while (true)
            {
                if (current)
                {
                    stack.push(current);
                    current = current->left;
                }
                else if (!stack.empty())
                {
                    current = stack.top();
                    stack.pop();
                    if (result.size() < k)
                    {
                        result.push_back(current->val);
                    }
                    else
                    {
                        if (target > current->val || abs(current->val - target) < abs(result[0] - target))
                        {
                            result.erase(result.begin());
                            result.push_back(current->val);
                        }
                    }
                    current = current->right;
                }
                else
                    break;
            }
            return result;
        }
    };
}
#if 0
class Solution
{
public:
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        vector<int> result;
        auto closest = getClosestNode(root, target);
        this->parentsPred.pop();
        this->parentsSucc.pop();

        result.push_back(closest->val);

        auto pred = getPredecessor(root, closest);
        auto succ = getSuccessor(root, closest);
        while (result.size() < k)
        {
            if (pred && succ)
            {
                if (abs(pred->val - target) < abs(succ->val - target))
                {
                    result.push_back(pred->val);
                    pred = getPredecessor(root, pred);
                }
                else
                {
                    result.push_back(succ->val);
                    succ = getSuccessor(root, succ);
                }
            }
            else if (succ)
            {
                result.push_back(succ->val);
                succ = getSuccessor(root, succ);
            }
            else if (pred)
            {
                result.push_back(pred->val);
                pred = getPredecessor(root, pred);
            }
            else
                break;
        }

        return result;
    }
private:
    TreeNode* getPredecessor(TreeNode* root, TreeNode* targetNode)
    {
        TreeNode* pred = nullptr;
        // if it has left node, find the right-most node in the left sub tree.
        if (targetNode->left)
        {
            pred = targetNode->left;
            while (pred->right)
            {
                parentsPred.push(pred);
                pred = pred->right;
            }
        }
        else
        {
            // find the parent node.
            if (parentsPred.empty())
                return nullptr;

            auto p = parentsPred.top();
            auto n = targetNode;
            parentsPred.pop();

            while (!parentsPred.empty() && p->left == n)
            {
                n = p;
                p = parentsPred.top();
                parentsPred.pop();
            }

            if (p->left == n)
                return nullptr;
            else
                pred = p;
        }

        return pred;
    }

    TreeNode* getSuccessor(TreeNode* root, TreeNode* targetNode)
    {
        TreeNode* successor = nullptr;

        // if it has right node, 
        if (targetNode->right)
        {
            auto temp = targetNode->right;
            parentsSucc.push(temp);
            while (temp->left)
            {
                temp = temp->left;
                parentsSucc.push(temp);
            }
            successor = temp;
        }
        else
        {
            // find the parent
            if (parentsSucc.empty())
                return nullptr;

            auto  p = parentsSucc.top();
            parentsSucc.pop();
            auto n = targetNode;

            while (!parentsSucc.empty() && p->right == n)
            {
                n = p;
                p = parentsSucc.top();
                parentsSucc.pop();
            }
            if (p->right == n)
                return nullptr;
            else
                successor = p;
        }

        return successor;
    }

    TreeNode* getClosestNode(TreeNode* node, double target)
    {
        if (!node)
            return nullptr;

        parentsPred.push(node);
        parentsSucc.push(node);
        TreeNode* t = nullptr;

        if ((double)node->val == target)
        {
            return node;
        }
        else if (target < (double)node->val)
        {
            t = getClosestNode(node->left, target);
        }
        else
        {
            t = getClosestNode(node->right, target);
        }

        if (t && abs(t->val - target) < abs(node->val - target))
        {
            return t;
        }
        else
            return node;
    }

    stack<TreeNode*> parentsPred;
    stack<TreeNode*> parentsSucc;
};
#endif
