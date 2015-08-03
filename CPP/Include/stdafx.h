// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <stack>

using namespace std;


// TODO: reference additional headers your program requires here
class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int v)
        :val(v), left(nullptr), right(nullptr)
    {}
};

class ListNode
{
public:
    ListNode* next;
    int val;

    ListNode(int v)
        :val(v), next(nullptr)
    {}

};

class Point
{
public:
    Point(int _x, int _y)
        :x(_x), y(_y)
    {}

    int x, y;
};

class GraphNode
{
public:
    int val;
    vector<GraphNode*> adj_list;

    GraphNode(int v)
        :val(v)
    {
    }

    void add_edge(GraphNode* node)
    {
        adj_list.push_back(node);
    }
};