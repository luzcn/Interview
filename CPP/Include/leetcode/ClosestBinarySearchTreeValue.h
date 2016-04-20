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
    // top down approach
    void dfs(TreeNode* node, double target, int& result)
    {
        if (!node)
            return;

        if ((double)node->val == target)
        {
            result = node->val;
            return;
        }
        else if (abs((double)node->val - target) < abs((double)result - target))
        {
            result = node->val;
        }

        if ((double)node->val < target)
        {
            dfs(node->right, target, result);
        }
        else
        {
            dfs(node->left, target, result);
        }
    }

    // bottom up approach
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
        int result = root->val;

        // binary search
        while (root)
        {
            if (abs((double)root->val - target) < abs((double)result - target))
            {
                result = root->val;
            }

            root = root->val < target ? root->right : root->left;
        }

        return result;
    }


    // Given a non - empty binary search tree and a target value, find k values in the BST that are closest to the target.
    //    Note:
    // Given target value is a floating point.
    //    You may assume k is always valid, that is : k <= total nodes.
    //    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
    //    Follow up :
    //Assume that the BST is balanced, could you solve it in less than O(n) runtime(where n = total nodes)?
    class Solution 
    {
    public:
        vector<int> closestKValues(TreeNode* root, double target, int k)
        {
            vector<int> result;
            inorder(root, target, k, result);

            return result;
        }

    private:
        void inorder(TreeNode* node, double target, int k, vector<int>& result)
        {
            if (!node)
                return;

            inorder(node->left, target, k, result);

            if (result.size() < k)
            {
                result.push_back(node->val);
            }
            else if (abs((double)node->val - target) < abs((double)result[0] - target))
            {
                // BST inorder is sorted array,
                // if we have dis(node->val) < dis(result[0]) and node->val > result[0], 
                // we can guarantee all elements [1...k-1] are closer than result[0].
                result.erase(result.begin());
                result.push_back(node->val);
            }

            inorder(node->right, target, k, result);
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
