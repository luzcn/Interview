#pragma once
#include "stdafx.h"

namespace careercup
{
    class Zone
    {
    public:
        bool isMine;
        bool isMarked;      // marked as mine
        bool isRevealed;    // is opened 
        int value;          // the number of mines in the surrounding  3*3 regions
        pair<int, int> location;

        
    };

    class Board
    {
        Board(int m, int n, int mines)
        {
            rows = m;
            cols = n;
            totalMines = mines;
            minesLeft = mines;
        }

        void leftClick(int x, int y)
        {
            computeValue();
            expand();
        }

        void rightClick(int x, int y)
        {
            // mark the zone
            zones[x][y].isMarked = true;
        }

        void startGame()
        {
            // generate board and set mines
        }

        bool win()
        {

        }
    private:
        vector<vector<Zone>> zones;
        int rows;
        int cols;
        int totalMines;

        int minesLeft;
        void computeValue()
        {}

        void expand()
        {}

    };
}