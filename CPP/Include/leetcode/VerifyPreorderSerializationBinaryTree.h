#pragma once
#include "stdafx.h"
#include <sstream>
//  One way to serialize a binary tree is to use pre - order traversal.When we encounter a non - null node, 
//  we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//_9_
/// \
//3     2
/// \ / \
//4   1  #  6
/// \ / \ / \
//# # # #   # #
//
//For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree.Find an algorithm without reconstructing the tree.
//
//Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
//You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
//Example 1:
//"9,3,4,#,#,1,#,#,2,#,6,#,#"
//Return true
//
//Example 2 :
//    "1,#"
//    Return false
//
//    Example 3 :
//    "9,#,#,1"
//    Return false

namespace leetcode
{
    vector<string> split(string& preorder, char delim)
    {
        std::stringstream ss(preorder);
        vector<string> result;
        string element;

        while (std::getline(ss, element, delim))
        {
            result.push_back(element);
        }

        return result;
    }

    struct Node
    {
        Node(const string& val)
            :value(val), isVisited(false)
        {}

        bool isVisited;
        string value;
    };

    bool isValidSerialization(string preorder)
    {
        if (preorder.empty())
            return false;

        vector<string> dataList = std::move(split(preorder, ','));

        stack<Node> nodeStack;
        if (dataList[0] != "#")
        {
            nodeStack.emplace(dataList[0]);
        }

        for (int i = 1; i < dataList.size(); i++)
        {
            if (nodeStack.empty())
                return false;

            string nodeValue = dataList[i];

            if (!nodeStack.empty())
            {
                if (!nodeStack.top().isVisited)
                {
                    nodeStack.top().isVisited = true;
                }
                else
                {
                    nodeStack.pop();
                }
            }

            if (nodeValue != "#")
            {
                nodeStack.emplace(nodeValue);
            }
        }

        return nodeStack.empty();
    }

bool isValidSerialization2(string preorder)
{
    vector<string> data = std::move(split(preorder, ','));

    stack<bool> st;

    if (data[0] != "#")
    {
        st.push(false);
    }

    for (int i = 1; i < data.size(); i++)
    {
        if (st.empty())
            return false;

        if (!st.top())
        {
            st.top() = true;
        }
        else
        {
            st.pop();
        }

        if (data[i] != "#")
        {
            st.push(false);
        }
    }
    return st.empty();
}
}