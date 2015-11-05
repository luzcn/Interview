#pragma once

#include "stdafx.h"
#include <sstream>

/// <summary>
///  The solution is succinct and elegant. 
/// </summary>
/// <param name=""> </param>
/// <returns> </return>
namespace ReverseWord
{
    void word_reverse(std::string& str)
    {
        std::istringstream iss(str);
        std::string items;
        std::string result;

        while (iss >> items)
        {
            items += " ";
            items += result;
            result = items;

            std::cout << items << std::endl;
        }

        str = result.substr(0, result.size() - 1);
    }

    // Remove the begin and end whitespaces.
    void trim(std::string& str)
    {
        // trim head
        str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), [](char c){ return isspace(c); }));

        // trim tail
        while (isspace(str.back()))
        {
            str.pop_back();
        }
    }

    // split the string with the delimiter 
    std::vector<std::string> split(const std::string& str, char delim)
    {
        std::vector<std::string> elems;
        std::istringstream iss(str);
        std::string item;

        while (std::getline(iss, item, delim))
        {
            elems.push_back(item);
        }

        return elems;
    }
}