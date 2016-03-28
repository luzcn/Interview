#pragma once
#include "stdafx.h"
#include <sstream>

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

    // using c++ stringstream 
    class Codec
    {
    public:

        // Encodes a list of strings to a single string.
        string encode(vector<string> strs)
        {
            string code;
            for (string& s : strs)
            {
                code += s + '\0';
            }

            return code;
        }

        // Decodes a single string to a list of strings.
        vector<string> decode(string s)
        {
            std::stringstream ss(s);
            vector<string> result;
            string element;

            while (std::getline(ss, element, '\0'))
            {
                result.push_back(element);
            }

            return result;

        }
    };
}