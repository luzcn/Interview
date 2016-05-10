#pragma once
#include "stdafx.h"
#include <set>
#include <map>
#include <functional>
#include <iterator>

namespace leetcode
{
    struct EndPoint
    {
        int pos;
        int height;
        bool isLeft;

        EndPoint(int p, int h, bool is_left)
            :pos(p), height(h), isLeft(is_left)
        {
        }

    };

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int, int>> result;

        if (buildings.empty())
        {
            return result;
        }

        vector<EndPoint> points;
        for (auto& b : buildings)
        {
            points.push_back({ b[0], b[2], true });
            points.push_back({ b[1], b[2], false });
        }

        sort(points.begin(), points.end(), [&](EndPoint& p1, EndPoint& p2) {
            return p1.pos < p2.pos;
        });


        std::multiset<int, std::greater<int>> heights;  // the first element is the larget height
        std::map<int, int> endPointMap; // sorted

        for (auto& p : points)
        {
            if (p.isLeft)
            {
                heights.insert(p.height);
            }
            else
            {
                heights.erase(heights.find(p.height));
            }

            if (heights.empty())
            {
                endPointMap[p.pos] = 0;
            }
            else
            {
                endPointMap[p.pos] = *heights.begin();
            }
        }

        //std::unique_copy(endPointMap.begin(), endPointMap.end(), 
        //    back_inserter<vector<pair<int, int>>>(result),
        //    [&](pair<int, int> p1, pair<int, int> p2) {return p1.second == p2.second; });

        for (auto p : endPointMap)
        {
            if (!result.empty() && result.back().second == p.second)
            {
                continue;
            }

            result.push_back(p);
        }

        return result;
    }

}

#if 0
namespace leetcode
{
    struct EndPoint
    {
        int Pos;
        int Ri;
        int height;
        bool isLeft;
        int count;  // used to overlaped builds with same height

        EndPoint(int p, int r, int h, bool l)
            :Pos(p), Ri(r), height(h), isLeft(l), count(0)
        {}

    };
    struct comparator
    {
        bool operator()(int n1, int n2)
        {
            return n1 > n2;
        }
    };


    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int, int>> result;
        if (buildings.empty())
            return{};

        vector<EndPoint> points;
        std::map<int, EndPoint, std::greater<int>> map;


        for (auto& b : buildings)
        {
            points.push_back(EndPoint(b[0], b[1], b[2], true));
            points.push_back(EndPoint(b[1], b[1], b[2], false));
        }

        sort(points.begin(), points.end(), [&](EndPoint& p1, EndPoint& p2) {
            return p1.Pos < p2.Pos;
        });

        for (int i = 0; i < points.size() - 1; i++)
        {
            auto p1 = points[i];
            auto p2 = points[i + 1];

            if (!p1.isLeft && p2.isLeft && p1.height == p2.height && p1.Pos == p2.Pos)
            {
                points.erase(points.begin() + i);
                points.erase(points.begin() + i);
            }
        }
        for (auto& p : points)
        {
            if (p.isLeft)
            {
                if (map.empty())
                {
                    if (!result.empty() && result.back().first == p.Pos && result.back().second == 0)
                    {
                        result.back().second = p.height;
                    }
                    else
                    {
                        result.push_back({ p.Pos, p.height });
                    }
                }
                else
                {
                    auto it = map.begin();
                    int currentHi = it->first;
                    int pos = it->second.Pos;

                    if (p.height > currentHi)
                    {
                        if (p.Pos == pos)
                        {
                            result.back().second = p.height;
                        }
                        else
                        {
                            result.push_back({ p.Pos, p.height });
                        }
                    }
                }
                auto it = map.find(p.height);
                if (it != map.end())
                {
                    it->second.count++;
                }
                else
                {
                    map.emplace(p.height, p);
                }
            }
            else // the right endpoint
            {
                auto it = map.find(p.height);
                if (it->second.count == 0)
                {
                    map.erase(it);
                }
                else
                {
                    it->second.count--;
                }

                if (map.empty())
                {
                    result.push_back({ p.Pos, 0 });
                }
                else if (p.height > map.begin()->first && p.Pos != map.begin()->second.Ri)
                {
                    result.push_back({ p.Pos, map.begin()->first });
                }
        }
    }

        return result;
}
}
#endif