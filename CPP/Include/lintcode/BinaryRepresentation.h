#pragma once
#include "stdafx.h"
#include <sstream>
//  Given a(decimal - e.g. 3.72) number that is passed in as a string, 
//  return the binary representation that is passed in as a string.
//
//  If the fractional part of the number can not be represented accurately in binary 
//  with at most 32 characters, return ERROR.
//
//  Example
//  For n = "3.72", return "ERROR".
//  For n = "3.5", return "11.1".
namespace lintcode
{
    vector<string> split(string& s, char delim)
    {
        std::stringstream ss(s);
        string item;
        vector<string> res;
        while (std::getline(ss, item, delim))
        {
            res.push_back(item);
        }

        return res;
    }
    string binaryRepresentation(string n) 
    {
        // wirte your code here
    }
}