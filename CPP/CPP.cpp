// CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int value = 1;
    vector<vector<int>> M(n, vector<int>(n));

    int r1 = 0;
    int r2 = n - 1;

    int c1 = 0;
    int c2 = n - 1;

    while (r1 <= r2 && c1 <= c2)
    {
        // top row
        for (int j = c1; j <= c2; j++)
            M[r1][j] = value++;
        r1++;
        if (r1 > r2)  // if n==1
            break;

        // right column
        for (int i = r1; i <= r2; i++)
            M[i][c2] = value++;
        c2--;

        // bottom row
        for (int j = c2; j >= c1; j--)
            M[r2][j] = value++;
        r2--;

        // left column
        for (int i = r2; i >= r1; i--)
            M[i][c1] = value++;
        c1++;
    }

    return M;
}
int _tmain(int argc, _TCHAR* argv[])
{
    //auto t = generateMatrix(1);
    auto t = generateMatrix(20);

    for (auto v : t)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}