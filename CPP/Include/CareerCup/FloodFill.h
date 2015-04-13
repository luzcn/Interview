#pragma once
#include "stdafx.h"

/*
how to implement fill() in paint?

In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color.
Following is the problem statement to do this task.

Given a 2D screen, location of a pixel in the screen and a color,
replace color of the given pixel and all adjacent same colored pixels with the given color.

Example:

Input:
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
};
x = 4, y = 4, newColor = 3
The values in the given 2D screen indicate colors of the pixels.
x and y are coordinates of the brush, newColor is the color that
should replace the previous color on screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1},
};

*/
namespace FloodFill
{
    void flood_fill(vector<vector<int>>& grid, int x, int y, int oldColor, int newColor)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
            return;

        if (grid[x][y] != oldColor)
            return;

        grid[x][y] = newColor;
        flood_fill(grid, x - 1, y, oldColor, newColor);
        flood_fill(grid, x, y - 1, oldColor, newColor);
        flood_fill(grid, x + 1, y, oldColor, newColor);
        flood_fill(grid, x, y + 1, oldColor, newColor);
    }
}