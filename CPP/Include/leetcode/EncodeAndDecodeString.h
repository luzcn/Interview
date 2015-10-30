#pragma once
#include "stdafx.h"

namespace leetcode
{
    string encode(vector<string> strList)
    {
        string str_encode = "";
        for (auto& str : strList)
        {
            str_encode += "#" + to_string(str.size()) + "#" + str;
        }

        return str_encode;
    }

    vector<string> decode(string str)
    {
        if (str.empty() || str[0] != '#')
            return{};

        int i = 0; 
        vector<string> res;
        while (i < str.size())
        {
            int nextStrLen = 0;
            string temp = "";
            if (i < str.size() && str[i] == '#')
            {
                i++;
            }
            while (i < str.size() && isdigit(str[i]))
            {
                nextStrLen = nextStrLen * 10 + str[i] - '0';
                i++;
            }
            if (i < str.size() && str[i] == '#')
            {
                i++;
            }

            for (int j = 0; j < nextStrLen; j++)
            {
                if (i < str.size())
                {
                    temp.push_back(str[i]);
                    i++;
                }
            }
            res.push_back(temp);
        }

        return res;
    }
}