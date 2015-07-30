#pragma once
#include "stdafx.h"
#include <queue>

namespace SurroundedRegions
{
    namespace helper
    {
        // BFS solution
        void bfs(vector<vector<char>>& board, int i, int j)
        {
            if (board[i][j] == 'O')
            {
                std::queue<pair<int, int>> que;
                que.emplace(i, j);
                board[i][j] = '#';

                while (!que.empty())
                {
                    auto current = que.front();
                    que.pop();

                    int s = current.first;
                    int t = current.second;

                    if (s - 1 >= 0 && board[s - 1][t] == 'O')
                    {
                        que.emplace(s - 1, t);
                        board[s - 1][t] = '#';
                    }
                    if (s + 1 < board.size() && board[s + 1][t] == 'O')
                    {
                        que.emplace(s + 1, t);
                        board[s + 1][t] = '#';
                    }
                    if (t - 1 >= 0 && board[s][t - 1] == 'O')
                    {
                        que.emplace(s, t - 1);
                        board[s][t - 1] = '#';
                    }
                    if (t + 1 < board[0].size() && board[s][t + 1] == 'O')
                    {
                        que.emplace(s, t + 1);
                        board[s][t + 1] = '#';
                    }
                }
            }
        }

        // DFS solution
        void dfs(vector<vector<char>>& board, int i, int j)
        {
            if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
                return;

            if (board[i][j] != 'O')
                return;

            board[i][j] = '#';

            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }


    void solve_bfs(vector<vector<char>>& board)
    {
        if (board.empty())
            return;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    helper::bfs(board, visited, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }

    }


    void solve_dfs(vector<vector<char>>& board)
    {
        if (board.empty())
            return;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    helper::dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }


    void solve(vector<vector<char>>& board)
    {
        //solve_bfs(board);
        solve_dfs(board);

        // print out board
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}