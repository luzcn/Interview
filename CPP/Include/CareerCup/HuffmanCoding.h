#pragma once
#include "stdafx.h"
#include <queue>

namespace careercup
{
    struct PrefixTreeNode
    {
        PrefixTreeNode(string c, int f)
            :character(c),
            frequency(f),
            left(nullptr),
            right(nullptr)
        {
        }

        string character;
        int frequency;
        PrefixTreeNode* left;
        PrefixTreeNode* right;
    };

    class comparator
    {
    public:
        bool operator() (PrefixTreeNode* a, PrefixTreeNode* b)
        {
            return a->frequency > b->frequency;
        }
    };
    PrefixTreeNode* HuffmanCoding(vector<string>& str, vector<int> freq)
    {
        // At least two characters
        _ASSERT(str.size() >= 2);

        // create a min-heap
        std::priority_queue<PrefixTreeNode*, std::vector<PrefixTreeNode*>, comparator> minHeap;

        for (int i = 0; i < str.size(); i++)
        {
            PrefixTreeNode* node = new PrefixTreeNode(str[i], freq[i]);
            minHeap.push(node);
        }

        while (minHeap.size() > 1)
        {
            PrefixTreeNode* n1 = minHeap.top();
            minHeap.pop();

            PrefixTreeNode* n2 = minHeap.top();
            minHeap.pop();

            PrefixTreeNode* newNode = new PrefixTreeNode(n1->character + n2->character, n1->frequency + n2->frequency);
            newNode->left = n1;
            newNode->right = n2;

            minHeap.push(newNode);
        }

        return minHeap.top();
    }

    void preorder(PrefixTreeNode* root, vector<string>& result, string& currentCode)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            result.push_back(currentCode);
            cout << root->character << ": " << currentCode << endl;
            return;
        }

        currentCode += "0";
        preorder(root->left, result, currentCode);
        currentCode.pop_back();

        currentCode += "1";
        preorder(root->right, result, currentCode);
        currentCode.pop_back();
    }

    vector<string> printCode(PrefixTreeNode* root)
    {
        if (!root)
            return{};

        vector<string> code;
        string current = "";

        preorder(root, code, current);
        return code;
    }
}