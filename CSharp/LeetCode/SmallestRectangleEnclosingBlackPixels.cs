using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    public class SmallestRectangleEnclosingBlackPixels
    {
        public int MinArea(char[,] image, int x, int y)
        {
            bool[,] visited = new bool[image.GetLength(0), image.GetLength(1)];


            Console.WriteLine(image.GetLength(0));
            Console.WriteLine(image.GetLength(1));

            dfs(image, visited, x, y);

            return (max_x - min_x + 1) * (max_y - min_y + 1);
        }

        private void dfs(char[,] image, bool[,] visited, int i, int j)
        {
            if (i < 0 || i >= image.GetLength(0) || j < 0 || j >= image.GetLength(1))
                return;

            if (visited[i, j] == false && image[i, j] == '1')
            {
                visited[i, j] = true;

                min_x = Math.Min(min_x, i);
                max_x = Math.Max(max_x, i);

                min_y = Math.Min(min_y, j);
                max_y = Math.Max(max_y, j);

                dfs(image, visited, i - 1, j);
                dfs(image, visited, i + 1, j);
                dfs(image, visited, i, j - 1);
                dfs(image, visited, i, j + 1);
            }

        }

        private int min_x = int.MaxValue;
        private int min_y = int.MaxValue;

        private int max_x = int.MinValue;
        private int max_y = int.MinValue;
    }
}
