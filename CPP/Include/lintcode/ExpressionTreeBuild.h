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

    bool isHigherOrder(string& str1, string& str2)
    {
        if ((str1 == "*" || str1 == "/") && (str2 == "+" || str2 == "-"))
            return true;
        return false;
    }

    void process(std::stack<string>& operator_stack, stack<ExpressionTreeNode*>& node_stack)
    {
        string op = operator_stack.top();
        operator_stack.pop();
        ExpressionTreeNode* op_node = new ExpressionTreeNode(op);

        ExpressionTreeNode* rightChild = node_stack.top();
        node_stack.pop();
        ExpressionTreeNode* leftChild = node_stack.top();
        node_stack.pop();

        op_node->left = leftChild;
        op_node->right = rightChild;

        node_stack.push(op_node);
    }

    // ExpressTreeBuild
    //(2 * 6 - (23 + 7) / (1 + 2))
    ExpressionTreeNode* build(vector<string> &expression)
    {
        if (expression.empty())
            return nullptr;

        std::stack<ExpressionTreeNode*> node_stack;
        std::stack<string> operator_stack;

        int i = 0;
        while (i < expression.size())
        {
            string str = expression[i];
            if (str == "(")
            {
                operator_stack.push("(");
            }
            else if (str == ")")
            {
                while (!operator_stack.empty() && operator_stack.top() != "(")
                {
                    process(operator_stack, node_stack);
                }
                operator_stack.pop();
            }
            else if (!isOperator(str))  // INT
            {
                ExpressionTreeNode* node = new ExpressionTreeNode(str);
                node_stack.push(node);
            }
            else   // an operator
            {
                if (operator_stack.empty()) // if stack is empty, directly push in 
                    operator_stack.push(str);
                else if (isHigherOrder(operator_stack.top(), str))
                {
                    // if the stack top operatro has higher order of the current one,
                    // need to pop out and process first.
                    while (!operator_stack.empty() && isHigherOrder(operator_stack.top(), str))
                    {
                        process(operator_stack, node_stack);
                    }
                    operator_stack.push(str);
                }
                else
                {
                    operator_stack.push(str);
                }
            }

            i++;
        }

        while (!operator_stack.empty())
        {
            process(operator_stack, node_stack);
        }

        return node_stack.top();
    }

}