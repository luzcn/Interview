#pragma once
#include "stdafx.h"
#include <list>

//A strobogrammatic number is a number that looks the same when rotated 180 degrees(looked at upside down).
//
//Write a function to determine if a number is strobogrammatic.The number is represented as a string.
//
//For example, the numbers "69", "88", and "818" are all strobogrammatic.
namespace leetcode
{
    bool valid(char c1, char c2)
    {
        if (c1 == '6' && c2 == '9' || c1 == '9' && c2 == '6')
            return true;

        if (c1 == '0' && c2 == '0')
            return true;

        if (c1 == '8' && c2 == '8')
            return true;

        if (c1 == '1' && c2 == '1')
            return true;

        return false;
    }

    // Strobogrammatic number 1
    bool isStrobogrammatic(string num)
    {
        if (num.empty())
            return false;

        int l = 0, r = num.size() - 1;

        while (l <= r)
        {
            char c1 = num[l];
            char c2 = num[r];
            if (!valid(c1, c2))
                return false;

            l++;
            r--;
        }

        return true;
    }

    //A strobogrammatic number is a number that looks the same when rotated 180 degrees(looked at upside down).
    //
    //Find all strobogrammatic numbers that are of length = n.
    //
    //For example,
    //Given n = 2, return["11", "69", "88", "96"].
    class strobogrammatic2
    {
    public:
        vector<string> findStrobogrammatic(int n)
        {
            if (n <= 0)
                return{};

            if (n == 1)
            {
                return{ "0","1","8" };
            }

            vector<string> result;
            std::list<char> current;

            dfs(result, current, n);


            return result;
        }
    private:
        void dfs(vector<string>& result, std::list<char>& current, int len)
        {
            if (current.size() > len)
                return;

            if (current.size() == len)
            {
                if (current.front() != '0')
                {
                    string str(current.begin(), current.end());
                    result.push_back(str);
                }
                return;
            }

            for (int i = 0; i < data.size(); i++)
            {
                if (current.empty() && len % 2 == 1)
                {
                    if ((data[i] == '6' || data[i] == '9'))
                    {
                        // the total length is odd number, cannot use '6' or '9' in the middle.
                        continue;
                    }

                    current.push_back(data[i]);
                }
                else
                {
                    current.push_back(data[i]);
                    current.push_front(mapStrobo[data[i]]);
                }

                dfs(result, current, len);
                current.pop_back();
                if (!current.empty())
                {
                    current.pop_front();
                }
            }
        }

        vector<char> data{ '0','1','6','8','9' };
        unordered_map<char, char> mapStrobo{
            { '0','0' },
            { '1','1' },
            { '8','8' },
            { '6','9' },
            { '9','6' }
        };
    };



    //Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
    void dfsRange(vector<char>& list, int& count, string& current,
        const string& low, const string& high, int length)
    {
        if (current.size() > length)
            return;

        if (current.size() == length && stol(current) <= stol(high) && stol(current) >= stol(low))
        {
            count++;
            return;
        }

        for (int i = 0; i < list.size(); i++)
        {
            if (current.size() == length - 2 && list[i] == '0')
                continue;

            if (current.empty())
            {
                if ((list[i] == '9' || list[i] == '6') && length % 2 == 1) // odd
                {
                    continue;
                }

                current.push_back(list[i]);
                if (length % 2 == 0)
                {
                    if (list[i] == '9')
                        current.insert(current.begin(), '6');
                    else if (list[i] == '6')
                        current.insert(current.begin(), '9');
                    else
                        current.insert(current.begin(), list[i]);
                }
            }
            else
            {
                current.push_back(list[i]);

                if (list[i] == '9')
                    current.insert(current.begin(), '6');
                else if (list[i] == '6')
                    current.insert(current.begin(), '9');
                else
                    current.insert(current.begin(), list[i]);
            }

            dfsRange(list, count, current, low, high, length);

            current.pop_back();
            if (!current.empty())
                current.erase(current.begin());
        }
    }

    int countByLength(int n)
    {
        if (n == 1)
        {
            // 0, 1, 8
            return 3;
        }

        if (n == 2)
        {
            // 11, 88, 69, 96
            return 4;
        }

        int last = (n % 2 == 1) ? 3 : 1;
        int first = 4;
        int count = 1;

        while (n > 3)
        {
            count *= 5;
            n -= 2;
        }

        return count*first*last;
    }

    int strobogrammaticInRange(string low, string high)
    {
        int m = low.size() + 1;
        int n = high.size() - 1;
        int count = 0;

        for (int i = m; i <= n; i++)
        {
            count += countByLength(i);
        }

        vector<char> charset{ '0','1','6','8','9' };

        string current;
        dfsRange(charset, count, current, low, high, low.size());

        if (high.size() > low.size())
            dfsRange(charset, count, current, low, high, high.size());

        return count;
    }
}

//for (string& s : result)
//{
//    auto t = s;
//    std::reverse(t.begin(), t.end());
//    if (n % 2)
//    {
//        t.pop_back();
//    }
//
//    for (int i = 0; i < t.size(); i++)
//    {
//        if (t[i] == '9')
//            t[i] = '6';
//        else if (t[i] == '6')
//            t[i] = '9';
//    }
//    s = t.append(s);
//
//}