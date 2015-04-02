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
#include <math.h>
#include <algorithm>

using namespace std;


// TODO: reference additional headers your program requires here
class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int v)
        :val(v)
    {}
};

class ListNode
{
public:
    ListNode* next;
    int val;

    ListNode(int v)
        :val(v)
    {}

};