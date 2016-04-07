#pragma once
#include "stdafx.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <functional>

namespace careercup
{
    class Cell
    {
    public:
        Cell()
            :isMine(false), isMarked(false), isRevealed(false), value(0)
        {}

        bool isMine;
        bool isMarked;      // marked as mine
        bool isRevealed;    // is opened 
        int value;          // the number of mines in the surrounding  3*3 regions
        //pair<int, int> location;
    };

    class Game
    {
    public:
        Game(int m, int n, int mines)
            :rows(m), cols(n), totalMines(mines)
        {
            game = vector<vector<Cell>>(m, vector<Cell>(n));

            // 1. generate mines
            generateMines();

            // 2. compute neibor mines for each not mine cells
            forAll([&](int i, int j) {
                if (!game[i][j].isMine)
                {
                    game[i][j].value = computeNeighbor(i, j);
                }
            });
        }

        void leftClick(int i, int j)
        {
            if (game[i][j].isMine)
            {
                cout << "You lost !" << endl;
            }
            else
            {
                expand(i, j);
            }

        }
        void print()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (!game[i][j].isRevealed)
                        cout << '.' << "\t";
                    else
                        cout << game[i][j].value << "\t";
                }

                cout << endl;
            }

            cout << "---------------------Mines-------------------" << endl;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (game[i][j].isMine)
                        cout << "M" << "\t";
                    else
                        cout << game[i][j].value << "\t";
                }
                cout << endl;
            }
        }
    private:
        // randomly generate 
        void generateMines()
        {
            int mines = 0;

            // random seed
            srand(time(NULL));

            while (mines < totalMines)
            {
                int x = rand() % rows;
                int y = rand() % cols;

                if (!game[x][y].isMine)
                {
                    game[x][y].isMine = true;
                    mines++;
                }
            }
        }

        // bfs, reveals the not mine cells, stops at the mine or not 0 value
        void expand(int i, int j)
        {
            std::queue<pair<int, int>> que;
            que.push({ i, j });

            while (!que.empty())
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                game[x][y].isRevealed = true;
                if (game[x][y].value > 0)
                    continue;

                for (auto& dir : four_dirs)
                {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    if (inBound(newX, newY) && !game[newX][newY].isMine && !game[newX][newY].isRevealed)
                    {
                        que.push({ newX, newY });
                    }
                }
            }
        }

        bool inBound(int i, int j)
        {
            if (i < 0 || i >= rows || j < 0 || j >= cols)
                return false;

            return true;
        }

        // compute how many mines in the 8 neighbors
        int computeNeighbor(int i, int j)
        {
            int mines = 0;
            for (auto& dir : dirs)
            {
                int x = i + dir.first;
                int y = j + dir.second;

                if (inBound(x, y) && game[x][y].isMine)
                {
                    mines++;
                }
            }

            return mines;
        }

        void forAll(std::function<void(int, int)> action)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    action(i, j);
                }
            }
        }

        vector<vector<Cell>> game;
        int rows;
        int cols;
        int totalMines;
        vector<pair<int, int>> dirs{ {1,0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1,1} };
        vector<pair<int, int>> four_dirs{ { 1,0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };
    };
}