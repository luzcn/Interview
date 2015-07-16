// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "leetcode\CountCompleteTreeNodes.h"
#include "CareerCup\FindKthSmallest.h"


using namespace std;

void print(const vector <vector<char>>& board)
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

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
void solve(vector<vector<char>>& board)
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
                bfs(board, i, j);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if (board[i][j] == '#')
            {
                board[i][j] = 'O';
            }
        }
    }
}


int _tmain(int argc, _TCHAR* argv [])
{
    vector<vector<char>> board{
        { 'X', 'O', 'X', 'O', 'X', 'O' },
        { 'O', 'X', 'O', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'O', 'X', 'O' },
        { 'O', 'X', 'O', 'X', 'O', 'X' }
    };
    print(board);

    cout << endl;

    solve(board);

    print(board);
    return 0;
}