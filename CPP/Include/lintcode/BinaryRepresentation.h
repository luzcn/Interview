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
        if (n.empty())
            return "";

        // WRONG !!! not working
        int int_part = stoi(n);
        float fractional_part = stod(n);
        
        string intStr = "";
        string fractionalStr = "";
        while (int_part > 0)
        {
            int c = int_part % 2;
            intStr = to_string(c).append(intStr);
            int_part >>= 1;
        }


        while (fractional_part != 0)
        {
            if (fractionalStr.size() > 31)
                return "ERROR";
            double r = fractional_part * 2;
            if (r >= 1.0)
            {
                fractionalStr += "1";
                fractional_part = r - 1.0;
            }
            else
            {
                fractionalStr += "0";
                fractional_part = r;
            }
        }

        if (fractionalStr.empty() && intStr.empty())
            return "0";
        else if (fractionalStr.empty())
            return intStr;
        else if (intStr.empty())
            return  "0." + fractionalStr;

        return intStr + "." + fractionalStr;
    }
}