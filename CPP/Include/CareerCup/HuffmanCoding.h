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
        std::priority_queue<PrefixTreeNode*, std::vector<PrefixTreeNode*>, comparator> heap;
        for (int i = 0; i < str.size(); i++)
        {
            PrefixTreeNode* node = new PrefixTreeNode(str[i], freq[i]);
            heap.push(node);
        }

        while (heap.size() > 1)
        {
            auto n1 = heap.top();
            heap.pop();

            auto n2 = heap.top();
            heap.pop();

            PrefixTreeNode* newNode = new PrefixTreeNode(n1->character + n2->character, n1->frequency + n2->frequency);
            newNode->left = n1;
            newNode->right = n2;
            heap.push(newNode);
        }

        return heap.top();
    }

    void preorder(PrefixTreeNode* root, vector<string>& res, string& current)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            res.push_back(current);
            cout << root->character << ": " << current << endl;
            return;
        }

        current += "0";
        preorder(root->left, res, current);
        current.pop_back();

        current += "1";
        preorder(root->right, res, current);
        current.pop_back();
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