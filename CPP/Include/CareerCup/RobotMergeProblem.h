#pragma once
#include "stdafx.h"
#include <queue>

/*//problem: robot merge point
//input:
//robot: 1
//obstacle: X
[
    0   0   0   M   1
    0   1   X   0   0
    0   X   0   0   0
    0   0   0   1   0
    0   0   0   0   0
]
//output:
//best merge point: M
3 + 1 + 3 = 7
Definition: Best merge point: minimal sum of path num between robots and merge point*/
// need to consider the situation, there could be a robot surrounded by blocks, 
// so there should be no merge point.
namespace careercup
{
    struct MyPoint
    {
        MyPoint(int _x, int _y, int d)
            :x(_x), y(_y), distance(d)
        {}

        int x;
        int y;
        int distance;
    };

    void print(vector<vector<int>>& M)
    {
        for (auto v : M)
        {
            for (auto i : v)
            {
                cout << i << "\t";
            }
            cout << endl;
        }
        cout << "---------------------" << endl;

    }

    // BFS solution,
    // The idea is from a robot, compute the distance to each reachable cell.
    // for those unreachable cells, set distance to INT_MAX
    void bfs(const vector<vector<int>>& board, int i, int j, vector<vector<int>>& total_distance)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        std::queue<MyPoint> que;
        que.push({ i, j, 0 });

        while (!que.empty())
        {
            auto p = que.front();
            que.pop();

            int x = p.x;
            int y = p.y;
            int d = p.distance;

            if (x < 0 || x >= m || y < 0 || y >= n
                || visited[x][y] || board[x][y] == -1)
            {
                continue;
            }

            visited[x][y] = true;
            if (total_distance[x][y] != INT_MAX)
            {
                total_distance[x][y] += d;
            }

            que.push({ x - 1, y, d + 1 });
            que.push({ x + 1, y, d + 1 });
            que.push({ x, y - 1, d + 1 });
            que.push({ x, y + 1, d + 1 });
        }

        // Rest the unreachable cells to INT_MAX
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 0 && !visited[i][j])
                {
                    total_distance[i][j] = INT_MAX;
                }
            }
        }
    }
    int bestMerge(vector<vector<int>>& board)
    {
        if (board.empty())
            return -1;

        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> total_distance(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    bfs(board, i, j, total_distance);
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0)
                    result = min(result, total_distance[i][j]);
            }
        }

        print(total_distance);

        return result;
    }
}


