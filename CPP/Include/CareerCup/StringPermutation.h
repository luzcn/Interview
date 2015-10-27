#pragma  once
#include "stdafx.h"

/***
 *	string permutation
 *
 *	The solution is recursive,
 *	- if there is only one character, then return.
 *	- if there are more than 1 character, take the first character,
 *	  then insert this character into the substring in all the possible positions.
 *
 *	  e.g. c => c
 *	  bc => bc, cb
 *	  abc => take "a" out, we have "bc", "cb" as the substrings. insert "a" into the substrings in all the possible positions.
 *	  so => abc, bac, bca, acb, cab, cba.
 */
namespace careercup
{

    void permuteRec(const string& s, vector<string>& result, string& current, 
        vector<bool>& visited, int index)
    {
        if (index == s.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                current.push_back(s[i]);
                permuteRec(s, result, current, visited, index + 1);
                current.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<string> stringPermute(string s)
    {
        vector<string> result;
        string current = "";
        vector<bool> visited(s.size(), false);

        permuteRec(s, result, current, visited, 0);

        return result;

    }
}