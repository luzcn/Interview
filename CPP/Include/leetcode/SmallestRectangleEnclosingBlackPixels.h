#pragma once
#include "stdafx.h"

namespace leetcode
{
    int min_x = INT_MAX;
    int min_y = INT_MAX;

    int max_x = INT_MIN;
    int max_y = INT_MIN;

    void dfs(vector<vector<char>>& image, vector<vector<bool>>& visited,
        int i, int j)
    {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size())
            return;

        if (!visited[i][j] && image[i][j] == '1')
        {
            visited[i][j] = true;
            min_x = min(min_x, i);
            max_x = max(max_x, i);

            min_y = min(min_y, j);
            max_y = max(max_y, j);

            dfs(image, visited, i - 1, j);
            dfs(image, visited, i + 1, j);
            dfs(image, visited, i, j - 1);
            dfs(image, visited, i, j + 1);
        }
    }

    int minArea(vector<vector<char>>& image, int x, int y)
    {
        if (image.empty())
            return 0;

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));



        dfs(image, visited, x, y);

        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
}