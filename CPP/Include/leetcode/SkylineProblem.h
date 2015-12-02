#pragma once
#include "stdafx.h"
#include <set>

namespace leetcode
{
    //struct Building
    //{
    //    int Li; // the left index
    //    int Ri; // the right index
    //    int Hi; // the height of the building

    //    Building(int l, int r, int h)
    //        :Li(l), Ri(r), Hi(h)
    //    {}
    //};

    struct comparator
    {
        bool operator()(int n1, int n2)
        {
            return n1 > n2;
        }
    };

    struct EndPoint
    {
        int pos;
        int height;
        bool isLeft;

        EndPoint(int p, int h, bool isLeftPoint)
            :pos(p), height(h), isLeft(isLeftPoint)
        {}
    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int, int>> result;
        if (buildings.empty())
            return{};

        vector<EndPoint> points;
        std::multiset<int, comparator> st;

        for (auto& b : buildings)
        {
            points.push_back(EndPoint(b[0], b[2], true));
            points.push_back(EndPoint(b[1], b[2], false));
        }

        sort(points.begin(), points.end(), [&](const EndPoint& p1, const EndPoint& p2) {
            return p1.pos < p2.pos;
        });

        for (auto& p : points)
        {
            if (p.isLeft)
            {
                if (st.empty() || *st.begin() < p.height)
                {
                    result.push_back({ p.pos, p.height });
                }

                st.insert(p.height);
            }
            else // right point 
            {
                st.erase(p.height);

                if (st.empty())
                {
                    result.push_back({ p.pos, 0 });
                }
                else if (*st.begin() < p.height)
                {
                    result.push_back({ p.pos, *st.begin() });
                }

                // special case, these two buildings are contiguously connected and have same height
            }
        }

        return result;
    }
}