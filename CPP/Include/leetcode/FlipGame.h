#pragma once
#include "stdafx.h"

//  You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
//  you and your friend take turns to flip two consecutive "++" into "--". 
//
//  The game ends when a person can no longer make a move and therefore the other person will be the winner.
//  Write a function to compute all possible states of the string after one valid move.
//
//  For example, given s = "++++", after one move, it may become one of the following states:
//  [
//      "--++",
//      "+--+",
//      "++--"
//  ]
//    If there is no valid move, return an empty list[].
namespace leetcode
{
    vector<string> generatePossibleNextMoves(string s)
    {
        if (s.size() <= 1)
            return{};

        vector<string> result;

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '+' && s[i - 1] == '+')
            {
                s[i] = '-';
                s[i - 1] = '-';
                result.push_back(s);
                s[i] = '+';
                s[i - 1] = '+';
            }
        }

        return result;
    }


    // flip game 2
    // given a string, determine can you guarantee a win. What is the time complexity?
    // dfs soltuion goes throug all the possible moves, 
    // if the first player has move, change the string, recursively check if the changed string can lead to a win.
    // If the changed string can win, check next possible move of the first player. 
    //
    // The time complexity is T(N) = T(N-2) + T(n-3) +[T(2) + T(N-4)] + [T(3) + T(N-5)] ... + [T(N-5) + T(3)] + ...T(n-2)
    // T(N) = 2*T(i) (i = 3...n-2). so it takes O(2^N)
    //https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
    bool dfs(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '+' && s[i - 1] == '+')
            {
                s[i] = '-';
                s[i - 1] = '-';

                if (!dfs(s))
                    return true;

                s[i] = '+';
                s[i - 1] = '+';
            }
        }
    }

    bool canWin(string s)
    {
        if (s.size() <= 1)
            return false;

        return dfs(s);
    }


    // O(n^2) game theory solution
    int firstMissingNumber(unordered_set<int> lut)
    {
        int m = lut.size();
        for (int i = 0; i < m; ++i)
        {
            if (lut.count(i) == 0) return i;
        }
        return m;
    }

    bool canWin2(string s)
    {
        int curlen = 0, maxlen = 0;
        vector<int> board_init_state;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '+') curlen++;              // Find the length of all continuous '+' signs
            if (i + 1 == s.size() || s[i] == '-')
            {
                if (curlen >= 2)
                    board_init_state.push_back(curlen);    // only length >= 2 counts

                maxlen = max(maxlen, curlen);       // Also get the maximum continuous length
                curlen = 0;
            }
        }

        // For instance ++--+--++++-+ will be represented as (2, 4)
        vector<int> g(maxlen + 1, 0);    // Sprague-Grundy function of 0 ~ maxlen
        for (int len = 2; len <= maxlen; ++len)
        {
            unordered_set<int> gsub;    // the S-G value of all subgame states
            for (int len_first_game = 0; len_first_game < len / 2; ++len_first_game)
            {
                int len_second_game = len - len_first_game - 2;

                // Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
                gsub.insert(g[len_first_game] ^ g[len_second_game]);
            }
            g[len] = firstMissingNumber(gsub);
        }

        int g_final = 0;
        for (auto& s : board_init_state)
        {
            g_final ^= g[s];
        }
        return g_final != 0;    // Theorem 1: First player must win iff g(current_state) != 0
    }
}