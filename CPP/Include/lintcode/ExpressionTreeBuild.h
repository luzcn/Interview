#pragma once
#include "stdafx.h"
#include <stack>

namespace lintcode
{
    class ExpressionTreeNode
    {
    public:
        string symbol;
        ExpressionTreeNode *left, *right;
        ExpressionTreeNode(string symbol)
        {
            this->symbol = symbol;
            this->left = this->right = NULL;
        }
    };

    bool isOperator(string& str)
    {
        if (str == "+" || str == "-"
            || str == "*" || str == "/")
            return true;

        return false;
    }

    bool isHigherOrEqualOrder(string& str1, string& str2)
    {
        if ((str1 == "*" || str1 == "/"))
            return true;
        if ((str1 == "+" || str1 == "-") && (str2 == "+" || str2 == "-"))
            return true;

        return false;
    }

    void process(std::stack<string>& op_stack, stack<ExpressionTreeNode*>& node_stack)
    {
        string op = op_stack.top();
        op_stack.pop();
        ExpressionTreeNode* opNode = new ExpressionTreeNode(op);

        auto rightChild = node_stack.top();
        node_stack.pop();

        auto leftChild = node_stack.top();
        node_stack.pop();

        opNode->left = leftChild;
        opNode->right = rightChild;

        node_stack.push(opNode);
    }

    // ExpressTreeBuild
    //(2 * 6 - (23 + 7) / (1 + 2))
    ExpressionTreeNode* build(vector<string> &expression)
    {
        if (expression.empty())
            return nullptr;

        std::stack<ExpressionTreeNode*> node_stack;
        std::stack<string> op_stack;

        int i = 0;
        while (i < expression.size())
        {
            string str = expression[i];
            if (str == "(")
            {
                op_stack.push("(");
            }
            else if (str == ")")
            {
                while (!op_stack.empty() && op_stack.top() != "(")
                {
                    process(op_stack, node_stack);
                }
                op_stack.pop();
            }
            else if (!isOperator(str))  // INT
            {
                ExpressionTreeNode* node = new ExpressionTreeNode(str);
                node_stack.push(node);
            }
            else
            {
                // Operators
                while (!op_stack.empty() && isHigherOrEqualOrder(op_stack.top(), str))
                {
                    process(op_stack, node_stack);
                }
                op_stack.push(str);
            }
            i++;
        }
        while (!op_stack.empty())
        {
            process(op_stack, node_stack);
        }

        if (node_stack.empty())
            return nullptr;

        return node_stack.top();
    }

}