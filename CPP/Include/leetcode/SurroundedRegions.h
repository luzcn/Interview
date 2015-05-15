#pragma once
#include "stdafx.h"
#include <queue>

namespace SurroundedRegions
{
    // BFS solution
    void solve_bfs(vector<vector<char>>& board)
    {
        if (board.empty())
            return;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        std::queue<pair<int, int>> que;


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // start searching from the boarder lines
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
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

    void solve(vector<vector<char>>& board)
    {
        solve_bfs(board);

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