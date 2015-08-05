#pragma once
#include "stdafx.h"

namespace leetcode
{
    void restoreRec(vector<string>& res, vector<string>& current, string& s, int index, int dots)
    {
        if (dots == 0)
        {
            auto suffix = s.substr(index);
            if (!suffix.empty() && suffix.size() <= 3 && stoi(suffix) <= 255 && suffix[0] != '0' || suffix.size() == 1)
            {
                string result = "";
                for (auto str : current)
                {
                    result += str + ".";
                }
                result += s.substr(index, s.size() - index + 1);
                res.push_back(result);
            }
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            auto prefix = s.substr(index, i - index + 1);
            if (prefix.size() == 1 || prefix.size() <= 3 && stoi(prefix) <= 255 && prefix[0] != '0')
            {
                current.push_back(prefix);
                dots--;
                restoreRec(res, current, s, i + 1, dots);
                current.pop_back();
                dots++;
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12)
            return{};

        vector<string> current;

        restoreRec(res, current, s, 0, 3);
        return res;
    }
}