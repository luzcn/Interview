using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    /**
     * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
     * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
     * You may assume all four edges of the grid are all surrounded by water.

        Example 1:

        11110
        11010
        11000
        00000

        Answer: 1

        Example 2:

        11000
        11000
        00100
        00011

        Answer: 3
     **/
    class NumberOfIslands
    {
        // DFS solution
        public int NumIslands(char[][] grid)
        {
            int count = 0;
            if (grid.GetLength(0) == 0)
                return 0;

            for (int i = 0; i < grid.GetLength(0); i++)
            {
                for (int j = 0; j < grid.GetLength(1); j++)
                {
                    if (grid[i][j] == '1')
                    {
                        count++;
                        flood_fill(grid, i, j);
                    }
                }
            }

            return count;
        }


        private void flood_fill(char[][] grid, int i, int j)
        {
            if (i < 0 || j < 0 || i >= grid.GetLength(0) || j >= grid.GetLength(1))
                return;

            if (grid[i][j] != '1')
                return;

            grid[i][j] = '2';

            flood_fill(grid, i - 1, j);
            flood_fill(grid, i + 1, j);
            flood_fill(grid, i, j - 1);
            flood_fill(grid, i, j + 1);
        }
    }
}
