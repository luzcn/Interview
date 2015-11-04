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
    // The idea is from a robot, get all the shortest distance for every node except blocks.
    void bfs(const vector<vector<int>>& board, int x, int y, vector<vector<int>>& totalDistance)
    {
        std::queue<pair<int, int>> que;
        que.emplace(x, y);

        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<int>> distance(board.size(), vector<int>(board[0].size(), 0));

        int m = board.size();
        int n = board[0].size();

        while (!que.empty())
        {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            if (!visited[i][j] && board[i][j] != -1)
            {
                // mark current point as visited.
                visited[i][j] = true;

                // move up
                if (i > 0 && !visited[i - 1][j])
                {
                    if (board[i - 1][j] != -1)
                    {
                        //if (distance[i][j] + 1 < distance[i - 1][j])
                        distance[i - 1][j] = distance[i][j] + 1;
                        totalDistance[i - 1][j] += distance[i - 1][j];

                        que.push(pair<int, int>(i - 1, j));
                    }
                    else
                    {
                        distance[i - 1][j] = 100; // INT_MAX;
                        totalDistance[i - 1][j] = INT_MAX;
                    }
                }
                // move down
                if (i < m - 1 && !visited[i + 1][j])
                {
                    if (board[i + 1][j] != -1)
                    {
                        //if (distance[i][j] + 1 < distance[i + 1][j])
                        distance[i + 1][j] = distance[i][j] + 1;
                        totalDistance[i + 1][j] += distance[i + 1][j];

                        que.push(pair<int, int>(i + 1, j));
                    }
                    else
                    {
                        distance[i + 1][j] = 100; // INT_MAX;
                        totalDistance[i + 1][j] = INT_MAX;
                    }
                }

                // move left
                if (j > 0 && !visited[i][j - 1])
                {
                    if (board[i][j - 1] != -1)
                    {
                        //if (distance[i][j] + 1 < distance[i][j - 1])
                        distance[i][j - 1] = distance[i][j] + 1;
                        totalDistance[i][j - 1] += distance[i][j - 1];

                        que.push(pair<int, int>(i, j - 1));
                    }
                    else
                    {
                        distance[i][j - 1] = 100;// INT_MAX;
                        totalDistance[i][j - 1] = INT_MAX;
                    }
                }

                // move right
                if (j < n - 1 && !visited[i][j + 1])
                {
                    if (board[i][j + 1] != -1)
                    {
                        //if (distance[i][j] + 1 < distance[i][j + 1])
                        distance[i][j + 1] = distance[i][j] + 1;
                        totalDistance[i][j + 1] += distance[i][j + 1];

                        que.push(pair<int, int>(i, j + 1));
                    }
                    else
                    {
                        distance[i][j + 1] = 100; // INT_MAX;
                        totalDistance[i][j + 1] = INT_MAX;
                    }
                }

            }
        }

        //return distance;
    }


    int bestMerge(vector<vector<int>>& board)
    {
        vector<vector<int>> totalDistance(board.size(), vector<int>(board[0].size(), 0));

        // find all the robots first.
        vector<pair<int, int>> robots;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 1)
                    robots.push_back(pair<int, int>(i, j));
            }
        }

        for (auto& p : robots)
        {
            bfs(board, p.first, p.second, totalDistance);

        }
        print(totalDistance);

        return 1;
    }
}

#if 0
int main()
{
    vector<vector<int>> M{
        { 0,   0,   0,   0,   1 },
        { 0,   1,   -1,   0 ,  0 },
        { 0,   -1,   0,   0,   0 },
        { 0,   0,   0,   1,   0 },
        { 0,   0,   0,   0,   0 }
    };

    careercup::bestMerge(M);
    return 0;
}
#endif