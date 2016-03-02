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
        vector<bool>& visited)
    {
        if (current.size() == s.size())
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
                permuteRec(s, result, current, visited);
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

        permuteRec(s, result, current, visited);

        return result;
    }
        
    // string permutation without duplication.
    void permutationDistinct(string& s, vector<bool>& visited, vector<string>& result, string& current)
    {
        if (current.size() == s.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (!visited[i])
            {
                if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])
                    continue;

                visited[i] = true;
                current.push_back(s[i]);

                permutationDistinct(s, visited, result, current);

                visited[i] = false;
                current.pop_back();
            }
        }
    }


    // Given a string, get all the premutation of upper case
    // "abc" => "Abc", "aBc",..., "ABc", "ABC"
    vector<string> dfs(string& str, vector<string>& current, int index)
    {
        if (index == str.size())
        {
            current.push_back(str);
            return current;
        }

        // make a copy of the return "current".
        auto result = dfs(str, current, index + 1);
        for (string s : result)
        {
            string left = s.substr(0, index);
            char c = str[index];
            left.push_back(toupper(c));

            string right = s.substr(index + 1);

            current.push_back(left + right);
        }
        return current;
    }

}