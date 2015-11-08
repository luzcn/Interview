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


    //Given an input string, reverse the string word by word.A word is defined as a sequence of non - space characters.
    //    The input string does not contain leading or trailing spaces and the words are always separated by a single space.
    //    For example,
    //    Given s = "the sky is blue",
    //    return "blue is sky the".
    //    Could you do it in - place without allocating extra space ?
    void swapRange(string& s, int i, int j)
    {
        while (i < j)
        {
            auto temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }
    }
    void reverseWord(string& s)
    {
        if (s.size() <= 1)
            return;

        // reverse the entire string
        swapRange(s, 0, s.size() - 1);

        int i = 0;
        int j = 0;
        while (j < s.size())
        {
            while (j < s.size() && !iswspace(s[j]))
            {
                j++;
            }
            swapRange(s, i, j - 1);
            j++;
            i = j;
        }
    }
}