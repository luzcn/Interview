#pragma once
#include <string>
#include <vector>
#include <stack>

//Given a tree string expression in balanced parenthesis format :
//(A(B(C)(D))(E)(F))
//
//        A
//      / | \
//     B  E  F
//    / \
//   C   D
//
//Return the corresponding tree(ie the root node).
//You can assume that the input is valid.
namespace careercup
{
    using namespace std;
    struct Tree
    {
        string val;
        vector<Tree*> children;

        Tree(const string& _val)
            :val(_val)
        {}
    };

    Tree* constructTree(string exp)
    {
        Tree* root = new Tree("Root");
        stack<Tree*> stack;
        stack.push(root);

        int i = 0;
        
        while (i < exp.size())
        {
            if (exp[i] == '(')
            {
                string str = "";
                i++;
                while (exp[i] != ')' && exp[i] != '(')
                {
                    str += exp[i];
                    i++;
                }
                stack.push(new Tree(str));
            }
            else if (exp[i] == ')')
            {
                if (!stack.empty())
                {
                    if (stack.top() == root)
                    {
                        return root;
                    }
                    else
                    {
                        auto t = stack.top();
                        stack.pop();

                        stack.top()->children.push_back(t);
                    }
                    i++;
                }
            }
        }
        return root;
    }
}