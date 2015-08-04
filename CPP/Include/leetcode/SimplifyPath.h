#pragma once
#include "stdafx.h"
#include <sstream>

namespace leetcode
{
    vector<string> split(string s, char delim)
    {
        vector<string> res;
        std::stringstream iss(s);
        string item;

        while (std::getline(iss, item, delim))
        {
            res.push_back(item);
        }

        return res;
    }

    string simplifyPath(string path)
    {
        auto elems = split(path, '/');
        vector<string> temp;

        for (string& s : elems)
        {
            if (!s.empty() && s != ".")
            {
                if (s == "..")
                {
                    if (!temp.empty())
                        temp.pop_back();
                }
                else
                {
                    temp.push_back("/" + s);
                }
            }
        }

        if (temp.empty())
            return "/";

        string res = "";
        for (auto& s : temp)
        {
            res += s;
        }
        return res;
    }
}
