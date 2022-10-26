#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, B;
int board[501][501];
int rest = 2147483647;
int resh = -1;

int main()
{
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int h = 0; h <= 256; h++)
    {
        int up = 0;
        int down = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] - h >= 0)
                    down += board[i][j] - h;
                else
                    up += h - board[i][j];
            }

        if (down + B >= up) // inv = B + down(removed block). up operation should be less than inv
        {
            int time = down * 2 + up;
            if (time < rest)
            {
                rest = time;
                resh = h;
            }
            else if (time == rest)
            {
                if (h > resh)
                    resh = h;
            }
        }
    }
    if (resh == -1)
    {
        rest = 0; resh = 0;
    }
    cout << rest << " " << resh << '\n';
}