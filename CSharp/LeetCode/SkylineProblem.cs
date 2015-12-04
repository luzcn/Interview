using System;
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
            points.Sort((EndPoint p1, EndPoint p2) => p1.pos.CompareTo(p2.pos));

            SortedSet<int> heights = new SortedSet<int>();

            return result;
        }

        private class EndPoint
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
        }
    }
}
