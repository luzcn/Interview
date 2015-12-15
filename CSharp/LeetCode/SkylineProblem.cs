using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp.LeetCode
{
    class SkylineProblem
    {
        public IList<int[]> GetSkyline(int[,] buildings)
        {
            IList<int[]> result = new List<int[]>();

            if (buildings.GetLength(0) == 0)
                return result;

            List<EndPoint> points = new List<EndPoint>();
            for (int i = 0; i < buildings.GetLength(0); i++)
            {
                points.Add(new EndPoint(buildings[i, 0], buildings[i, 2], true));
                points.Add(new EndPoint(buildings[i, 1], buildings[i, 2], false));
            }
            points.Sort();

            // height, count
            SortedDictionary<int, int> heights = new SortedDictionary<int, int>();

            // position, height
            SortedDictionary<int, int> coordinates = new SortedDictionary<int, int>();

            foreach (var p in points)
            {
                if (p.isLeft)
                {
                    if (heights.ContainsKey(p.height))
                    {
                        heights[p.height]++;
                    }
                    else
                    {
                        heights.Add(p.height, 1);
                    }
                }
                else
                {
                    if (--heights[p.height] ==0)
                    {
                        heights.Remove(p.height);
                    }
                }

                if (heights.Count == 0)
                {

                    coordinates[p.pos] = 0;
                }
                else
                {
                    coordinates[p.pos] = heights.Last().Key;
                }
            }

            foreach(var c in coordinates)
            {
                if (result.Count == 0)
                {
                    result.Add(new int[] { c.Key, c.Value });
                }
                else if (result.Last()[1] != c.Value)
                {
                    result.Add(new int[] { c.Key, c.Value });
                }
            }
            return result;
        }

        private class EndPoint:IComparable<EndPoint>
        {
            public int pos { get; set; }
            public int height { get; set; }
            public bool isLeft { get; set; }

            public EndPoint(int p, int h, bool l)
            {
                pos = p;
                height = h;
                isLeft = l;
            }

            public int CompareTo(EndPoint other)
            {
                if (other != null)
                    return pos.CompareTo(other.pos);
                else
                    throw new ArgumentException("Argument is not valid");
            }
        }

    }
}
