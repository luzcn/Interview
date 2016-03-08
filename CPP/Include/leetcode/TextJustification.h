#pragma once
#include "stdafx.h"

//Given an array of words and a length L, format the text such that each line has exactly L characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line.Pad extra spaces ' ' when necessary so that each line has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, 
// the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//    L : 16.
//
//    Return the formatted lines as :
//
//[
//    "This    is    an",
//    "example  of text",
//    "justification.  "
//]
//
//Note: Each word is guaranteed not to exceed L in length.

namespace leetcode
{
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> result;

        if (words.empty())
            return result;

        int n = words.size();

        int i = 0;
        while (i < n)
        {
            // the start position of word in the input words list
            int start = i;

            // the sum of words size.
            int sum = 0;

            while (i < n && sum + words[i].size() <= maxWidth)
            {
                sum += words[i].size() + 1; // need to add space, so +1
                i++;
            }

            // the last word that can fit into maxWidth
            int end = i - 1;

            int intervalCount = end - start;
            int averageSpace = 0, leftSpace = 0;

            if (intervalCount > 0)
            {
                averageSpace = (maxWidth - sum + intervalCount + 1) / intervalCount;
                leftSpace = (maxWidth - sum + intervalCount + 1) % intervalCount;
            }

            string line;
            for (int j = start; j < end; j++)
            {
                line += words[j];

                if (i == words.size()) // the last line
                    line.append(1, ' ');
                else
                {
                    line.append(averageSpace, ' ');

                    if (leftSpace > 0)
                    {
                        line.append(1, ' ');
                        leftSpace--;
                    }
                }
            }
            line += words[end];

            if (line.size() < maxWidth)
            {
                line.append(maxWidth - line.size(), ' ');
            }

            result.push_back(line);
        }

        return result;
    }
}