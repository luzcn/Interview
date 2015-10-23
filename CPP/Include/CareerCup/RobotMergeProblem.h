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
// ???????????????,?????bfs, ???????????????dis??,??????????????????
namespace careercup
{

    void bfs(vector<vector<int>>& board,  int x, int y)
    {
        vector<vector<int>> distance(board.size(), vector<int>(board[0].size(), 100));
        distance[x][y] = 0;
        std::queue<pair<int, int>> que;
        que.emplace(x, y);

        while(!que.empty())
        { }
    }
}