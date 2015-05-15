#pragma once
#include "stdafx.h"
#include <queue>

namespace SurroundedRegions
{
    // BFS solution
#pragma region BFS
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        std::queue<pair<int, int>> que;

        if (board[i][j] == 'O' && !visited[i][j])
        {
            que.emplace(i, j);
            while (!que.empty())
            {
                auto v = que.front();
                que.pop();

                auto s = v.first;
                auto t = v.second;
                visited[s][t] = true;

                if (s - 1 >= 0 && board[s - 1][t] == 'O' && !visited[s - 1][t])
                {
                    que.emplace(s - 1, t);
                }
                if (s + 1 < m && board[s + 1][t] == 'O' && !visited[s + 1][t])
                {
                    que.emplace(s + 1, t);
                }
                if (t - 1 >= 0 && board[s][t - 1] == 'O' && !visited[s][t - 1])
                {
                    que.emplace(s, t - 1);
                }
                if (t + 1 < n && board[s][t + 1] == 'O' && !visited[s][t + 1])
                {
                    que.emplace(s, t + 1);
                }
            }
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
                    bfs(board, visited, i, j);
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
#pragma endregion


#pragma region DFS
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        if (board[i][j] != 'O') return;
        if (visited[i][j]) return;

        visited[i][j] = true;
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i + 1, j);
        dfs(board, visited, i, j - 1);
        dfs(board, visited, i, j + 1);
    }

    void solve_dfs(vector<vector<char>>& board)
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
                    dfs(board, visited, i, j);
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
#pragma endregion
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